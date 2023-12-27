#include <gst/gst.h>

typedef struct _CustomData{
    GstElement *pipeline;
    GstElement *videotestsrc;
    GstElement *videoconvert;
    GstElement *fpsdisplaysink;

}CustomData;

int main(int argc, char **argv){
    CustomData data;
    GstStateChangeReturn ret;

    gst_init(&argc, &argv);

    data.pipeline = gst_pipeline_new("pipeline");
    data.videotestsrc = gst_element_factory_make("videotestsrc","videotestsrc");
    data.videoconvert = gst_element_factory_make("videoconvert","videoconvert");
    data.fpsdisplaysink = gst_element_factory_make("fpsdisplaysink","fpsdisplaysink");

    if(!data.pipeline || !data.videoconvert || !data.fpsdisplaysink){
        g_printerr("Not all elements could created.\n");
        return -1;
    }

    // Modify the source's properties
    g_object_set(G_OBJECT(data.fpsdisplaysink), "text-overlay", 1, NULL);

    gst_bin_add_many(GST_BIN(data.pipeline), data.videotestsrc, data.videoconvert, data.fpsdisplaysink,NULL);
    gst_element_link_many(data.videotestsrc, data.videoconvert, data.fpsdisplaysink,NULL);

    GMainLoop *loop = g_main_loop_new(NULL,FALSE);

    ret = gst_element_set_state(data.pipeline, GST_STATE_PLAYING);

    g_main_loop_run(loop);

    gst_element_set_state(data.pipeline, GST_STATE_NULL);
    g_main_loop_unref(loop);
    gst_object_unref(data.pipeline);

    return 0;
}