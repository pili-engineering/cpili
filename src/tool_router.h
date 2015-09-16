//
//  tool_router.h
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#ifndef __cpili__tool_router__
#define __cpili__tool_router__

#include <stdio.h>
#include "tool_defines.h"

typedef enum cpili_task_operation {
    CPILI_OPT_USAGE = 0,
    CPILI_OPT_VERSION,
    CPILI_OPT_STREAMING
} cpili_task_operation_t;

void tool_route(cpili_task_operation_t opt, cpili_task_t *task);

#endif /* defined(__cpili__tool_router__) */
