#include <gst/gst.h>

typedef struct _CustomData{
    GstElement *pipeline;
    GstElement *videotestsrc;
    GstCaps *videocaps;
    GstElement *fpsdisplaysink;
}CustomData;

int main(int argc, char **argv){
    CustomData data;
    GstStateChangeReturn ret;

    gst_init(&argc, &argv);

    data.pipeline = gst_pipeline_new("pipeline");
    data.videotestsrc = gst_element_factory_make("videotestsrc","videotestsrc");
    data.videocaps = gst_caps_new_simple(
        "video/x-raw",
        "format",
        G_TYPE_STRING,
        "I420",
        "framerate",
        GST_TYPE_FRACTION,
         60/1,
         "width",1280,
         "height",720,
         NULL
        );
    data.fpsdisplaysink = gst_element_factory_make("fpdisplaysink", "fpsdisplaysink");

    g_object_set(data.videotestsrc,"caps",data.videocaps, NULL);
    gst_caps_unref(data.videocaps);

    gst_bin_add_many(GST_BIN(data.pipeline), data.videotestsrc, data.fpsdisplaysink,NULL);
    gst_element_link_many(data.videotestsrc, data.fpsdisplaysink,NULL);

    GMainLoop *loop = g_main_loop_new(NULL,FALSE);

    ret = gst_element_set_state(data.pipeline, GST_STATE_PLAYING);
    
    g_main_loop_run(loop);

    gst_element_set_state(data.pipeline, GST_STATE_NULL);
    g_main_loop_unref(loop);
    gst_object_unref(data.pipeline);

    return 0;
}