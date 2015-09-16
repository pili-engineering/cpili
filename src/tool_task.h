//
//  tool_task.h
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#ifndef __cpili__tool_task__
#define __cpili__tool_task__

#include "tool_defines.h"

cpili_task_t todo(int argc, char *argv[]);
void go(cpili_task_t task);

typedef bool (*cpili_task_property_setter)(cpili_task_t *task, const char *value);

bool task_setter_i(cpili_task_t *task, const char *value);
bool task_setter_o(cpili_task_t *task, const char *value);
bool task_setter_vf(cpili_task_t *task, const char *value);
bool task_setter_hf(cpili_task_t *task, const char *value);
bool task_setter_sp(cpili_task_t *task, const char *value);

#endif /* defined(__cpili__tool_task__) */
