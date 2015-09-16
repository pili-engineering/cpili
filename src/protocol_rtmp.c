//
//  protocol_rtmp.c
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#include "protocol_rtmp.h"

#include <stdio.h>

static void stream_cb(uint8_t state) {
    printf("stream state: %d\n", state);
}

bool rtmp_open(cpili_url_context_t *ctx, const char *url) {
    pili_stream_context_p stream_ctx = pili_create_stream_context();
    pili_init_stream_context(stream_ctx, 0, 0, stream_cb);
    
    rtmp_user_data_t user_data = {stream_ctx, {NULL, NULL}};
    ctx->user_data = &user_data;
    
    bool result = !!pili_stream_push_open(stream_ctx, url);
    if (result) {
        pili_release_stream_context(stream_ctx);
        ctx->user_data = NULL;
        user_data.stream_ctx = NULL;
        puts("Fail to open rtmp stream");
    }
    
    return result;
}

bool rtmp_read(cpili_url_context_t *ctx, unsigned char *buf, int size) {
    return false;
}

bool rtmp_write(cpili_url_context_t *ctx, const unsigned char *buf, int size) {
    bool result = true;
    return result;
}

bool rtmp_close(cpili_url_context_t *ctx) {
    bool result = true;
    return result;
}