//
//  tool_parser.c
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#include "tool_parser.h"
#include "tool_router.h"
#include "tool_error.h"
#include "tool_task.h"

#include <string.h>

struct cpili_option {
    const char *letter; // short for name
    const char *name;   // name
    bool extra_param;   // whether it takes an additional argument
    cpili_task_property_setter setter;
};

typedef struct cpili_option cpili_option_t;

static const cpili_option_t aliases[] = {
    {"h",  "help",                          false, NULL},
    {"v",  "version",                       false, NULL},
    {"i",  "input",                         true,  task_setter_i},
    {"o",  "output",                        true,  task_setter_o},
    {"vf", "video-fps",                     true,  task_setter_vf},
    {"hf", "h264-bitstream-format",         true,  task_setter_hf},
    {"sp", "sps-pps-packetization-mode",    true,  task_setter_sp},
    {NULL, NULL,                            false, NULL},
};

static cpili_option_t get_option(const char *string) {
    static int null_option_index = 0;
    if (!null_option_index) {
        int index = 0;
        while (NULL != aliases[index].letter) {
            index++;
        }
        
        null_option_index = index;
    }
    
    size_t length = strlen(string);
    if (length < 2 || '-' != string[0] || ('-' == string[1] && length < 3)) {
        return aliases[null_option_index];
    }
    
    bool is_letter = (string[1] != '-');
    
    const char *str = NULL;
    size_t str_length = 0;
    if (is_letter) {
        str = &string[1];
        str_length = length - 1;
    } else {
        str = &string[2];
        str_length = length - 2;
    }
    
    cpili_option_t result = aliases[null_option_index];
    for (int i = 0; i < null_option_index; i++) {
        cpili_option_t option = aliases[i];
        bool found = is_letter ? !strcmp(option.letter, str) : !strcmp(option.name, str);
        if (found) {
            result = option;
            break;
        }
    }
    
    return result;
}

void tool_parse(int argc, char *argv[], cpili_task_t *task) {
    if (1 == argc) {
        // wrong param, show usage
        init_error(CPILI_ERROR_WRONG_PARAM, &(task->error));
        tool_route(CPILI_OPT_USAGE, task);
    } else {
        cpili_task_operation_t opt = CPILI_OPT_USAGE;
        
        int i = 1;
        while (i < argc) {
            cpili_option_t option = get_option(argv[i]);
            if (NULL == option.letter) {
                init_error(CPILI_ERROR_WRONG_PARAM, &(task->error));
                break;
            } else if (!strcmp("h", option.letter)) {
                // help
                opt = CPILI_OPT_USAGE;
            } else if (!strcmp("v", option.letter)) {
                // version
                opt = CPILI_OPT_VERSION;
            } else {
                // streaming
                opt = CPILI_OPT_STREAMING;
            }
            
            if (option.extra_param) {
                if (i + 1 < argc) {
                    const char *value = argv[++i];
                    if (!option.setter(task, value)) {
                        init_error(CPILI_ERROR_WRONG_PARAM, &(task->error));
                        break;
                    }
                } else {
                    init_error(CPILI_ERROR_WRONG_PARAM, &(task->error));
                    break;
                }
            }
            ++i;
        }
        
        tool_route(opt, task);
    }
}