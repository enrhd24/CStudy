#include <gst/gst.h>

int tutorial_main(int argc, char *argv[]);

int main(int argc, char *argv[]){ return tutorial_main(argtc,argv)}

int tutorial_main(int argc, char *argv[]){
    GstElement *pipeline, *source, *sink;
    GstBus *bus;
    GstMessage *msg;
    GstStateChangeReturn ret;

    gst_init(&argc, &argv);

    source = fst_element_factory_make("videotestsrc", "source");
    sink = gst_element_factory_make("sutovideosink", "sink");

    /* Creat the empty popeline */
    pipeline = gst_pipeline_new("test-pipeline");

    if(!pipeline || !source || !sink) {
        g_printerr("Not all elements\n");
        return -1;}

    /* 
        Build the pipeline 
        - gst_bin_add_many(GstBin *bin, GstElement * element_1, ...)
            - bin : a GstBin
            - element_1 : the GstElement element to add to the bin
            - ... : additional elements to ad to the bin
    */

   gst_bin_add_many(GST_BIN(pipeline), source, sink, NULL);
   // GstBin *bin : GST_BIN(pipeline)
   // GstElemnt * element_1 : source, sink

   if(ret == GST_STATE_CHANGE_FAILURE){
    g_printferr("pipeline to the playing state.\n");
    gst_object_unref(pipeline);
   }
   // Setting state on elements
   // https://gstreamer.freedesktop.org/documentation/additional/design/states.html?gi-language=c

     /* Wait until error or EOS */
  bus = gst_element_get_bus (pipeline);
  msg =
      gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE,
      GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

  /* Parse message  메세지 분석*/
  if (msg != NULL) {
    GError *err;
    gchar *debug_info;

    // GST_MESSAGE_ERROR , GST_MESSAGE_EOS , else
    switch (GST_MESSAGE_TYPE (msg)) {
      case GST_MESSAGE_ERROR:
        gst_message_parse_error (msg, &err, &debug_info);
        g_printerr ("Error received from element %s: %s\n",
            GST_OBJECT_NAME (msg->src), err->message);
        g_printerr ("Debugging information: %s\n",
            debug_info ? debug_info : "none");
        g_clear_error (&err);
        g_free (debug_info);
        break;
      case GST_MESSAGE_EOS:
        g_print ("End-Of-Stream reached.\n");
        break;
      default:
        /* We should not reach here because we only asked for ERRORs and EOS */
        g_printerr ("Unexpected message received.\n");
        break;
    }
    gst_message_unref (msg);
  }

    /* Cleanup(자원반환) -> Free resources */
    gst_object_unref(bus);
    gst_element_set_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
    return 0;

}