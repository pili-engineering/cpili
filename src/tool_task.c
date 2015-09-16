//
//  tool_task.c
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#include "tool_task.h"
#include "tool_error.h"
#include "tool_parser.h"

static void init_task(cpili_task_t *task) {
    task->handler = NULL;
    
    task->error.code = CPILI_ERROR_NONE;
    task->error.message = NULL;
    
    task->param.input = CPILI_INPUT_DEFAULT;
    task->param.output = CPILI_OUTPUT_DEFAULT;
}

cpili_task_t todo(int argc, char *argv[]) {
    cpili_task_t task;
    init_task(&task);
    
    tool_parse(argc, argv, &task);
    
    return task;
}

void go(cpili_task_t task) {
    task.handler(task.param);
}