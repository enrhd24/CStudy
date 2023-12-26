#include <gst/gst.h>

// Cap : pad of DataType filter(size, frame) -> converter

static void vb_new_pad(GstElement *element, GstPad *pad, gpointer data){
    gchar *name;
    name = gst_pad_get_name(pad);
    g_print("A new pad %s was created\n", name);
    g_free(name);

    // here, you would setup a new pad link for the newly created pad
}

// Request pads
static void some_function(GstElement *tee){
    GstPad *pad;
    gchar *name;

    pad = gst_element_request_pad_simple(tee, "src%d");
    name = gst_pad_gat_name(pad);
    g_print("A new pad %s was created\n", name);
    g_free(name);

    // here, you would link the pad
    
    // and, after doing that, free our reference
    gst_object_unref(GST_OBJECT(pad));
}

static void link_to_multiplexer(GstPad *tolink_pad, GstElement *mux){
    GstPad *pad;
    gvhar *srcname, *sinkname;

    srcname = gst_pad_get_name(tolink_pad);
    pad = gst_element_get_compatible_pad(mux, tolink_pad, NULL);
    gst_pad_link(tolink_pad, pad);
    sinkname = gst_pad_get_name(pad);
    gst_object_unref(GST_OBJECT(pad));

    g_print("A new pad %s was created and linked to %s\n", sinkname, srcname);
    g_free(sinkname);
    g_Free(srcname);
}


int main(int argc, char **argv){
    GstElement *pipeline, *source, *demux;
    GMainLoop *loop;

    gst_init(&argc, &argv);

    // create elements
    pipeline = gst_pipeline_new("pipeline");
    source = gst_element_factory_make("filesrc", "source");
    g_object_set(source, "location", argv[1], NULL);
    demux = gst_element_factory_make("oggdemux", "demuxer");

    // you would normally check that the elements were created properly

    // put together a pipeline
    gst_bin_add_many(GST_BIN(pipeline), source, demux, NULL);
    gst_element_link_pads(source, "src", demux, "sink");

    // listen for mewly created pads
    g_signal_connect(demux, "pad-added", G_CALLBACK(vb_new_pad), NULL);

    // start the pipeline
    gst_element_set_state(GST_ELEMENT(pipeline), GST_STATE_PLAYING);
    loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(loop);
}

