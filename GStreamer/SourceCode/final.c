#include <gst/gst.h>

static void on_pad_added(GstElement *element, GstPad *pad, gpointer data);

typedef struct _CustomData{
    GstElement *pipeline;
    GstElement *source;
    GstElement *depay;
    GstCaps *filtercaps;
    GstElement *filter;
    GstElement *parse;
    GstElement *decode;
    GstElement *encode;
    GstElement *mux;
    GstElement *sink;
} CustomData;

int main(int argc, char **argv){
    CustomData data;
    GstBus *bus;
    GstMessage *msg_err;
    GstMessage *msg_eos;
    GstStateChangeReturn ret;

    gst_init(&argc, &argv);

    data.source = gst_element_factory_make("rtspsrc", "source");
    data.depay = gst_element_factory_make("rtph264depay", "depay");
    data.filter = gst_element_factory_make("capsfilter", "filter");
    data.filtercaps = gst_caps_new_simple("video/x-h264", "stream-format", G_TYPE_STRING, "avc", NULL);
    data.parse = gst_element_factory_make("h264parse", "parse");
    data.decode = gst_element_factory_make("avdec_h264", "decode");
    data.encode = gst_element_factory_make("x264enc", "encode");
    data.mux = gst_element_factory_make("mpegtsmux", "mux");
    data.sink = gst_element_factory_make("hlssink", "sink");
    data.pipeline = gst_pipeline_new("rtsp-to-hls-pl");

    g_object_set(data.source, "location", "rtsp://192.168.0.70:8554/test", NULL);
    g_object_set(data.sink, "max_files", 10, "target-suration", 5, "location", "/nginx/hls/segment%05d.ts", "playlist-location", "/nginx/hls/playlistm3u8",NULL);
    g_object_set(data.filter, "caps", data.filtercaps, NULL);
    gst_caps_unref(data.filtercaps);

    gst_bin_add_many(GST_BIN(data.pipeline), data.source, data.depay, data.filter,
                            data.parse, data.decode, data.encode, data.mux, data.sink, NULL);

    ret = gst_element_set_state(data.pipeline, GST_STATE_PLAYING);
    bus = gst_element_get_bus(data.pipeline);
    msg_err = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR);
    msg_eos = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_EOS);

    if(msg_err != NULL || msg_eos != NULL){
        GError *err;
        gchar *debug_info;

        if(msg_err != NULL){
            gst_message_parse_error(msg_err, &err, &debug_info);
            g_printerr("Error received from element %s: %s\n", GST_OBJECT_NAME(msg_err->src), err->message);
            g_printerr("Debugging informations: %s\n", debug_info ? debug_info : "none");
            g_clear_error(&err);
            g_free(debug_info);
        }else if(msg_eos != NULL){
            g_print("END-OF-Stream reached.\n");
        }else{
            g_printerr("Unexpected message received.\n");
        }
        gst_message_unref(msg_err);
        gst_message_unref(msg_eos);
    }
    gst_object_unref(bus);
    gst_element_set_state(data.pipeline, GST_STATE_NULL);
    gst_object_unref(data.pipeline);
    return 0;
}