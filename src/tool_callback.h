//
//  tool_callback.h
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#ifndef cpili_tool_callback_h
#define cpili_tool_callback_h

// Callback func
typedef void (*cpili_callback_func)(void *data);

// Callback Action
struct cpili_callback {
    void *target;
    cpili_callback_func callback;
};

typedef struct cpili_callback cpili_callback_t;

#endif
