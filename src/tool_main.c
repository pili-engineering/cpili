//
//  tool_main.c
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#include "tool_main.h"
#include "tool_task.h"

int main(int argc, char *argv[]) {
    cpili_task_t task = todo(argc, argv);
    go(task);
    
    return 0;
}