//
//  tool_router.c
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#include "tool_router.h"
#include "tool_help.h"
#include "tool_version.h"
#include "protocol_defines.h"

#include <string.h>
#include <unistd.h>

/**
 * flv -> rtmp
 */
static void flv2rtmp(cpili_task_param_t param) {
    puts("FLV file -> RTMP stream");
    cpili_url_context_t flv_ctx, rtmp_ctx;
    
    flv_ctx.url = param.input.options.file_path;
    flv_ctx.user_data = NULL;
    
    rtmp_ctx.url = param.output.options.url;
    rtmp_ctx.user_data = NULL;
    
    for (int i = 0; i < PROTOCOL_COUNT; i++) {
        cpili_protocol_t protocol = protocols[i];
        
        if (!strcmp("flv", protocol.name)) {
            cpili_protocol_cpy(flv_ctx.protocol, protocol);
        } else if (!strcmp("rtmp", protocol.name)) {
            cpili_protocol_cpy(rtmp_ctx.protocol, protocol);
        }
    }
    
    if (!flv_ctx.protocol.url_open(&flv_ctx, flv_ctx.url)) {
        puts("fail to open flv file");
        return;
    }
    
    if (-1 == rtmp_ctx.protocol.url_open(&rtmp_ctx, rtmp_ctx.url)) {
        puts("fail to connect rtmp");
        return;
    }
    
    bool res = true;
    uint32_t pre_tag_ts = 0;
    do {
        flv_tag_p flv_tag = flv_create_tag();
        res = flv_ctx.protocol.url_read(&flv_ctx, (unsigned char *)flv_tag, sizeof(flv_tag_t));
        
        uint32_t tag_ts = flv_tag->timestamp;
        if (!pre_tag_ts) {
            usleep(40000);
        } else {
            printf("%d, %u\n", flv_tag->tag_type, tag_ts);
            usleep(tag_ts - pre_tag_ts);
        }
        pre_tag_ts = tag_ts;
        
        rtmp_ctx.protocol.url_write(&rtmp_ctx, (unsigned char *)flv_tag, sizeof(flv_tag_t));
        flv_release_tag(flv_tag);
        
    } while (res);
}

//-----------

static void opt_usage(cpili_task_param_t param) {
    print_help();
}

static void opt_version(cpili_task_param_t param) {
    print_version();
}

static void opt_streaming(cpili_task_param_t param) {
    if (CPILI_FILE_FORMAT_FLV == param.input.file_format) {
        if (CPILI_IO_TYPE_STREAM == param.output.type && CPILI_STREAM_PROTOCOL_RTMP == param.output.stream_protocol) {
            flv2rtmp(param);
        }
    }
}

static const cpili_task_handler operation[] = {
    opt_usage,
    opt_version,
    opt_streaming
};

void tool_route(cpili_task_operation_t opt, cpili_task_t *task) {
    task->handler = operation[opt];
}