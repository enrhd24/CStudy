#include <gst/gst.h> //gstreamer-in-c-code

typedef struct _CustomData{
    GstElement *pipeline;
    GstElement *videotestsrc;
    GstElement *autovideosink;
    GstCaps *video;
    GstElement *videoconvert;
    GstElement *fpsdisplaysink;   
}CustomData;

int main(int argc, char **argv){
    CustomData data;
    GstBus *bus;
    GstMessage *msg_err;
    GstMessage *msg_eos;
    GstStateChangeReturn ret;

    gst_init(&argc, &argv);

    data.pipeline = gst_pipeline_new("pipeline");
    data.videotestsrc = gst_element_factory_make("videotestsrc","videotestsrc");
    data.autovideosink = gst_element_factory_make("autovideosink","autovideosink");
    data.video = gst_caps_new_simple("cideo/x-raw", "video", G_TYPE_STRING, "avc", NULL);
    data.videoconvert = gst_element_factory_make("videoconvert", "videoconvert");
    data.fpsdisplaysink = gst_element_factory_make("fpsdisplaysink", "fpsdisplaysink");

    g_object_set(data.autovideosink, "caps", data.video, NULL);
    gst_caps_unref(data.video);

    if(!data.pipeline || !data.videotestsrc || !data.autovideosink || !data.videoconvert || !data.fpsdisplaysink){
        g_printerr("Not all elements could ve created, \n");
        return -1;
    }

    gst_bin_add_many(GST_BIN(data.pipeline), data.pipeline, data.videotestsrc, data.autovideosink, data.video, data.videoconvert, data.fpsdisplaysink);

    if(!gst_element_link_many(data.pipeline, data.videotestsrc, data.autovideosink, data.video, data.videoconvert)){
        g_printerr("Elements could not be linked. \n");
        return -1;
    }

    ret = gst_element_set_state(data.pipeline, GST_STATE_PLAYING);
    bus = gst_element_get_bus(data.pipeline);
    msg_err = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR);
    msg_eos = gst_bus_timed_pop_filtered(bus,GST_CLOCK_TIME_NONE, GST_MESSAGE_EOS);

    if(msg_err != NULL || msg_eos != NULL){
        GError *err;
        gchar *debug_info;

        if(msg_err != NULL){
            gst_message_parse_error(msg_err, &err, &debug_info);
            g_printerr("Error received from element %s: %s\n", GST_OBJECT_NAME(msg_err->src),err->message);
            g_printerr("Debugging information: %s\n", debug_info ? debug_info : "none");
            g_clear_error(&err);
            g_free(debug_info);
        }else if(msg_eos != NULL){
            g_print("End-Of-Stream reached.\n");
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