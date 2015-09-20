//
//  protocol_flv.c
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#include "protocol_flv.h"

#include <stdlib.h>
#include <memory.h>
#include <pili_camera.h>

#define HTONTIME(x) ((x>>16&0xff)|(x<<16&0xff0000)|(x&0xff00)|(x&0xff000000))

static size_t read_1(uint8_t *p, uint8_t *d) {
    int count = 1;
    *d = *p;
    p += count;
    return count;
}

static size_t read_3(uint8_t *p, uint32_t *d) {
    int count = 3;
    *d = (p[0] << 16) | (p[1] << 8) | p[2];
    p += count;
    return count;
}

static size_t read_time(uint8_t *p, uint32_t *utime) {
    *utime = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
    *utime = HTONTIME(*utime);
    return 4;
}

/**
 * Private
 */
static size_t read_flv_tag(uint8_t *index, flv_tag_p tag) {
    uint8_t *p = index;
    size_t size = 4;
    p += 4; // skip pre tag size
    
    size += read_1(p, &(tag->tag_type));
    size += read_3(p, &(tag->data_size));
    size += read_time(p, &(tag->timestamp));
    size += read_3(p, &(tag->stream_id));
    
    tag->data = malloc(tag->data_size);
    memcpy(tag->data, p, tag->data_size);
    
    return size;
}

/**
 * Public
 */
bool flv_open(cpili_url_context_t *ctx, const char *url) {
    FILE *file = NULL;
    file = fopen(url, "rw");
    
    if (!file) {
        return false;
    }
    
    flv_user_data_t user_data = {
        .file = file,
        .writer = {
            .is_flv_header_writen = false
        },
        .reader = {
            .eof = false,
            .file_size = 0,
            .buffer = NULL,
            .index = NULL
        }
    };
    ctx->user_data = &user_data;
    
    return true;
}

bool flv_read(cpili_url_context_t *ctx, unsigned char *buf, int size) {
    flv_user_data_t *user_data = (flv_user_data_t *)ctx->user_data;
    if (user_data->reader.eof) {
        return false;
    }
    
    if (0 == user_data->reader.index) {
        fseek(user_data->file, 0, SEEK_END);
        long file_size = ftell(user_data->file);
        rewind(user_data->file);
        
        user_data->reader.file_size = file_size;
        if (file_size <= 9) {
            return false;
        }
        
        if (NULL == user_data->reader.buffer) {
            user_data->reader.buffer = malloc(sizeof(uint8_t) * file_size);
        }
        
        if (NULL == user_data->reader.index) {
            user_data->reader.index = user_data->reader.buffer + 9; // skip flv header
        }
    }
    
    if (user_data->reader.index + 4 >= user_data->reader.buffer + user_data->reader.file_size) {
        return false;
    }
    
    flv_tag_p tag = (flv_tag_p)buf;
    size_t tag_size = read_flv_tag(user_data->reader.index, tag);
    user_data->reader.index += tag_size;
    
    return !!tag_size;
}

bool flv_write(cpili_url_context_t *ctx, const unsigned char *buf, int size) {
    return false;
}

bool flv_close(cpili_url_context_t *ctx) {
    flv_user_data_t *user_data = (flv_user_data_t *)ctx->user_data;
    return !!fclose(user_data->file);
}