//
//  tool_task.c
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#include "tool_task.h"
#include "tool_error.h"

cpili_task_t todo(int argc, char *argv[]) {
    cpili_task_t task;
    
    if (2 == argc) {
        // -h, -v
    } else if (5 >= argc) {
        if (1 == argc % 2) {
            //
        } else {
            // wrong param
            init_error(CPILI_ERROR_WRONG_PARAM, &(task.error));
        }
    } else {
        init_error(CPILI_ERROR_WRONG_PARAM, &(task.error));
    }
    
    return task;
}

void go(cpili_task_t task) {
    task.handler(task.param);
}