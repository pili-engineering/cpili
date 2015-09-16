//
//  tool_protocol.h
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#ifndef __cpili__tool_protocol__
#define __cpili__tool_protocol__

#include "tool_defines.h"

typedef struct cpili_protocol cpili_protocol_t;
typedef struct cpili_url_context cpili_url_context_t;

// url context
struct cpili_url_context {
    cpili_protocol_t *protocol;
    const char *url;
    void *user_data;
};

typedef struct cpili_callback_action cpili_callback_action_t;

// Protocol
struct cpili_protocol {
    const char *name;
    bool (*url_open)(cpili_url_context_t *ctx, const char *url);
    bool (*url_read)(cpili_url_context_t *ctx, unsigned char *buf, int size);
    bool (*url_write)(cpili_url_context_t *ctx, const unsigned char *buf, int size);
    bool (*url_close)(cpili_url_context_t *ctx);
};

#endif /* defined(__cpili__tool_protocol__) */
