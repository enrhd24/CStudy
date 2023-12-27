#include <gst/gst.h>

typedef struct _CustomData{
    GstElement *pipeline;
    GstElement *videotestsrc;
    GstElement *autovideosink;

}CustomData;

int main(int argc, char **argv){
    CustomData data;
    GstStateChangeReturn ret;

    gst_init(&argc, &argv);

    data.pipeline = gst_pipeline_new("pipeline");
    data.videotestsrc = gst_element_factory_make("videotestsrc","videotestsrc");
    data.autovideosink = gst_element_factory_make("autovideosink","autovideosink");

    if(!data.pipeline || !data.videotestsrc || !data.autovideosink){
        g_printerr("Not all elements could created.\n");
        return -1;
    }

    gst_bin_add_many(GST_BIN(data.pipeline), data.videotestsrc, data.autovideosink,NULL);
    gst_element_link_many(data.videotestsrc, data.autovideosink,NULL);
    GMainLoop *loop = g_main_loop_new(NULL,FALSE);

    ret = gst_element_set_state(data.pipeline, GST_STATE_PLAYING);

    g_main_loop_run(loop); // 무한루프 시작
    gst_element_set_state(data.pipeline, GST_STATE_NULL);
    g_main_loop_unref(loop);  // 무한루프 끝
    gst_object_unref(data.pipeline);

    return 0;
}