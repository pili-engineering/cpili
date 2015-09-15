//
//  tool_router.c
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#include "tool_router.h"
#include "tool_help.h"

// -> rtmp
static void h264_to_rtmp(cpili_task_param_t param) {}
static void aac_to_rtmp(cpili_task_param_t param) {}
static void flv_to_rtmp(cpili_task_param_t param) {}

// -> flv
static void h264_to_flv(cpili_task_param_t param) {}
static void aac_to_flv(cpili_task_param_t param) {}

// streaming
static void streaming_handler(cpili_task_param_t param) {
}

// usage
static void usage_handler(cpili_task_param_t param) {
    tool_help();
}

void tool_bind_handler(int argc, char *argv[], cpili_task_t *task) {
    if (2 == argc) {
        // -h, -v
        task->handler = usage_handler;
    } else if (5 >= argc) {
        if (1 == argc % 2) {
            //
        } else {
            // wrong param
            task->handler = usage_handler;
        }
    } else {
        task->handler = usage_handler;
    }
}