//
//  tool_version.c
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#include "tool_version.h"

#include <stdio.h>

void print_version() {
    static const char *const version = LIBCPILI_VERSION;
    printf("cpili %s\n", version);
}