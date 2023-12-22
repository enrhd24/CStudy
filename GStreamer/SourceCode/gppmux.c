#include <gst/gst.h>
#include <stdio.h>

#define cSUCCESS 0
#define cFAIL (-1)

int main(int argc, char *argv[]){
    gst_init(&argc, &argv);

    // Create pipeline
    GstElement *pipeline = gst_pipeline_new("pipeline");
    GstElement *autoaudiosink = gst_element_factory_make("autoaudiosink", NULL);
    GstElement *autovideosink = gst_element_factory_make("autovideosink",NULL);
    GstElement *autovideosrc = gst_element_factory_make("autovideosrc", NULL);
    GstElement *autoaudiosrc = gst_element_factory_make("autoaudiosrc", NULL);
    GstElement *dvbsrc = gst_element_factory_make("dvbsrc",NULL);
    GstElement *dodge = gst_element_factory_make("dodge", NULL);
    GstElement *kmssink = gst_element_factory_make("kmssink", NULL);

    gst_bin_add_many(GST_BIN(pipeline),dvbsrc,kmssink,dodge,autovideosink,autovideosrc,autoaudiosink, NULL);
    gst_element_link_many(dvbsrc,kmssink,dodge,autovideosink,autovideosrc,autoaudiosink,NULL);
    gst_element_set_state(pipeline, GST_STATE_READY);

    if(!autovideosink) g_printerr("Failed to create autovideosink element.\n");
    if(!autovideosrc) g_printerr("Failed to create autovideosrc element.\n");
    if(!autovideosrc) g_printerr("Failed to create autoaudiosink element.\n");
    if(!autoaudiosrc) g_printerr("Failed to create autoaudiosrc element.\n");
    if(!dvbsrc) g_printerr("Failed to create cacasink element\n");
    if(!dodge) g_printerr("Failed to create dodge element\n");
    if(!kmssink) g_printerr("Failed to create kmssink element\n");

    GMainLoop *loop = g_main_loop_new(NULL, FALSE);
    
    gst_element_set_state(pipeline, GST_STATE_PLAYING);
    g_main_loop_run(loop);
 

    // Clean up
    gst_element_set_state(pipeline, GST_STATE_NULL);
    g_main_loop_unref(loop);
    gst_object_unref(pipeline);

    return 0;
}