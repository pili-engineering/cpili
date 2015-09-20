//
//  protocol_rtmp.c
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#include "protocol_rtmp.h"

#include <stdio.h>

const char *stream_states[] = {
    "Stream state: Unknow",
    "Stream state: Connecting",
    "Stream state: Connected",
    "Stream state: Disconnected",
    "Stream state: Error"
};

static void stream_cb(uint8_t state, pili_error_t error) {
    printf("%s\n", stream_states[state]);
}

bool rtmp_open(cpili_url_context_t *ctx, const char *url) {
    pili_stream_context_p stream_ctx = pili_create_stream_context();
    pili_init_stream_context(stream_ctx, 0, 0, stream_cb);
    
    rtmp_user_data_t *user_data = malloc(sizeof(rtmp_user_data_t));
    user_data->stream_ctx = stream_ctx;
    user_data->callback.target = NULL;
    user_data->callback.callback = NULL;
    
    ctx->user_data = user_data;
    
    bool result = !!pili_stream_push_open(stream_ctx, url);
    if (result) {
        pili_release_stream_context(stream_ctx);
        ctx->user_data = NULL;
        user_data->stream_ctx = NULL;
        free(user_data);
        puts("Fail to open rtmp stream");
    }
    
    return result;
}

bool rtmp_read(cpili_url_context_t *ctx, unsigned char *buf, int size) {
    // do nothing
    return false;
}

bool rtmp_write(cpili_url_context_t *ctx, const unsigned char *buf, int size) {
    pili_stream_context_p stream_ctx = ((rtmp_user_data_t *)ctx->user_data)->stream_ctx;
    
    flv_tag_p flv_tag = (flv_tag_p)buf;
    bool result = pili_write_flv_tag(stream_ctx, flv_tag);
    
    return result;
}

bool rtmp_close(cpili_url_context_t *ctx) {
    bool result = true;
    return result;
}