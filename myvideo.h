#include <stdio.h>
#include <gst/gst.h>
#include <glib-unix.h>

#define VIDEO_IPV4 "192.168.0.101"
#define VIDEO_PORT 5000

int create_video_pipeline(void);
void start_video_pipeline(void);

