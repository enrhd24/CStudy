#include <gst/gst.h>

/*
    gst_init() : GStreamer를 초기화 하는 방법
    gst_parse_launch() : 파이프라인을 빠르게 구축하는 방법
    gst_element_set_state() : GStreamer에 신호를 보내는 방법
    GStreamer : 모든 것을 처리하는 동안 편안히 않아 휴식을 취하는 방법
*/

/*
    gst_init() 
    - 내부 자료 구조를 초기화
    - 설치되어 있는 플러그인 유효한지 체크
    - gstreamer 옵션 값을 받아 실행 argc, argv
*/ 

/*
    gst_parse_launch() 
    - GstElement * gst_parse_launch(const gchar *pipeline_description, GError **error)
    - playbin : uri에 맞는 적절한 element를 생성하게 된다.
    - gstreamer : source element, sink element 
      - source에서 sink로 흘러가는 과정 : pipeline
*/

/*
    gst_element_get_bus(pipeline) : pipeline으로부터 bus를 가져옴
*/

/*
    gst_bus_timed_pop_filtered()
    - pipeline으로 부터 bus를 가지고 온다.
    - message가 에러 or 파일의 끝이면 Block시킨다.
*/

/*
    Cleanup(자원 반환)코드
    - bus로부터 반환된 메시지를 해제
    - bus 객체도 해제
    - gst_message_unref()
    - gst_object_unref()
    - gst_element_set_state(pipeline, GST_STATE_NULL)
*/

int tutorial_main(int argc, char *argv[]);

int main(int argc, char *argv[]){
    return tutorial_main(argc, argv)
}

int tutorial_main(int argc, char *argv[]){

    /* structure variable declare */
    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;

    /* 매개변수로 부터 gst 초기화 */
    gst_init(&argc, &argv);

    /* source element, sink element = gst_pare_lanuch */
    pipeline=gst_pare_launch("playbin uri=", NULL);
    gst_element_set_state(pipeline, GST_STATE_PLAYING);

    bus = gst_element_get_bus(pipeline);
    msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,
        GST_MESSAGE_ERROR | GST_MESSAGE_EOS)

    /* 사전 차단 conditional */
    if (GST_MESSAGE_TYPE(msg) = GST_MESSAGE_ERROR)
        g_error("variable set for more details")
    
    /* Cleanup 자원반환 -> Free resources */
    gst_message_nref(msg);
    gst_object_unref(bus);
    gst_element_set_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
    
}