#include <stdio.h>
#include <gst/gst.h>

int main(int arc, char *argv[]){
    const gchar *nano_str;
    guint major, minor, micro, nano;

    gst_init(argc, &argv);
    gst_version(&major, &minor, &micro, &nano);

    if(nano == 1) nano_str = "(CVS)";
    else if(nano == 2) nano_str = "(Prerelease)";
    else nano_str = "";

    printf("this program is linked afainst GStreamer %d.%d.%d %s\n",
            major, minor, micro, nano_str);
}