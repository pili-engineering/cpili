//
//  protocol_defines.h
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#ifndef cpili_protocol_defines_h
#define cpili_protocol_defines_h

#include "tool_protocol.h"
#include "protocol_rtmp.h"
#include "protocol_flv.h"

#define PROTOCOL_COUNT  2

// protocols
static const cpili_protocol_t protocols[] = {
    {"rtmp", rtmp_open, rtmp_read, rtmp_write, rtmp_close},
    {"flv", flv_open, flv_read, flv_write, flv_close}
};

#endif
