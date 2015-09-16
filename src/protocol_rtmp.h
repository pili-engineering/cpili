//
//  protocol_rtmp.h
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#ifndef __cpili__protocol_rtmp__
#define __cpili__protocol_rtmp__

#include "tool_protocol.h"
#include "pili_camera.h"
#include "tool_callback.h"

struct rtmp_user_data {
    pili_stream_context_p stream_ctx;
    cpili_callback_t    callback;
};

typedef struct rtmp_user_data rtmp_user_data_t;

bool rtmp_open(cpili_url_context_t *ctx, const char *url);
bool rtmp_read(cpili_url_context_t *ctx, unsigned char *buf, int size);
bool rtmp_write(cpili_url_context_t *ctx, const unsigned char *buf, int size);
bool rtmp_close(cpili_url_context_t *ctx);

#endif /* defined(__cpili__protocol_rtmp__) */
