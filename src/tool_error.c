//
//  tool_error.c
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#include "tool_error.h"
#include <stdio.h>

static const char *const error_message[] = {
    NULL,
    "Wrong params",
    "I/O error"
};

void init_error(cpili_error_code_t code, cpili_error_t *err) {
    (*err).code = code;
    (*err).message = error_message[code];
}