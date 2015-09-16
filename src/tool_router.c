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

static void opt_usage(cpili_task_param_t param) {
    print_help();
}

static void opt_version(cpili_task_param_t param) {
    print_version();
}

static void opt_streaming(cpili_task_param_t param) {
}

static const cpili_task_handler operation[] = {
    opt_usage,
    opt_version,
    opt_streaming
};

void tool_route(cpili_task_operation_t opt, cpili_task_t *task) {
    task->handler = operation[opt];
}