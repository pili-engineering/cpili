//
//  tool_task.c
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#include "tool_task.h"

cpili_task_t todo(int argc, char *argv[]) {
    cpili_task_t task;
    
    return task;
}

void fire(cpili_task_t task) {
    switch (task.error.code) {
        case CPILI_ERROR_NONE:
            break;
        case CPILI_ERROR_WRONG_PARAM:
            break;
        case CPILI_ERROR_IO_ERROR:
            break;
        default:
            break;
    }
}