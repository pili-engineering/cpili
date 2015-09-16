//
//  protocol_flv.c
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#include "protocol_flv.h"

bool flv_open(cpili_url_context_t *ctx, const char *url) {
    FILE *file = NULL;
    file = fopen(url, "rw");
    
    if (!file) {
        return false;
    }
    
    flv_user_data_t user_data = {file};
    ctx->user_data = &user_data;
    
    return true;
}

bool flv_read(cpili_url_context_t *ctx, unsigned char *buf, int size) {
    
}

bool flv_write(cpili_url_context_t *ctx, const unsigned char *buf, int size) {}

bool flv_close(cpili_url_context_t *ctx) {}