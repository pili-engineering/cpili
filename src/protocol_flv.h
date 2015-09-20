//
//  protocol_flv.h
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#ifndef __cpili__protocol_flv__
#define __cpili__protocol_flv__

#include "tool_protocol.h"

#include <stdio.h>

struct flv_user_data {
    FILE    *file;
    struct {
        bool    is_flv_header_writen;
    } writer;
    struct {
        bool    eof;
        long    file_size;
        uint8_t *buffer;
        uint8_t *index;
    } reader;
};

typedef struct flv_user_data flv_user_data_t;

bool flv_open(cpili_url_context_t *ctx, const char *url);
bool flv_read(cpili_url_context_t *ctx, unsigned char *buf, int size);
bool flv_write(cpili_url_context_t *ctx, const unsigned char *buf, int size);
bool flv_close(cpili_url_context_t *ctx);

#endif /* defined(__cpili__protocol_flv__) */
