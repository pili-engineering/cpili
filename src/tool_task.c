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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

bool task_setter_i(cpili_task_t *task, const char *value) {
    int length = (int)strlen(value);
    cpili_file_format_t file_format = CPILI_FILE_FORMAT_UNKNOW;
    
    const char *file_extension = NULL;
    int ext_length = 0;
    for (int i = length - 1; i >= 0; i--) {
        if ('.' == value[i]) {
            ext_length = length - i - 1;
            file_extension = value + i + 1;
            break;
        }
    }
    
    if (file_extension && ext_length > 0) {
        if (!strcmp("h264", file_extension)) {
            file_format = CPILI_FILE_FORMAT_H264;
        } else if (!strcmp("flv", file_extension)) {
            file_format = CPILI_FILE_FORMAT_FLV;
        } else if (!strcmp("aac", file_extension)) {
            file_format = CPILI_FILE_FORMAT_AAC;
        }
        
        if (CPILI_FILE_FORMAT_UNKNOW == file_format) {
            return false;
        } else {
            task->param.input.options.file_path = value;
            task->param.input.file_format = file_format;
            return true;
        }
    } else {
        return false;
    }
}

bool task_setter_o(cpili_task_t *task, const char *value) {
    int length = (int)strlen(value);
    cpili_io_type_t io_type = CPILI_IO_TYPE_UNKNOW;
    
    if (length > 7 && !strncmp("rtmp://", value, 7)) {
        io_type = CPILI_IO_TYPE_STREAM;
        task->param.output.type = io_type;
        task->param.output.stream_protocol = CPILI_STREAM_PROTOCOL_RTMP;
        task->param.output.options.url = value;
        
        return true;
    } else {
        const char *file_extension = NULL;
        int ext_length = 0;
        for (int i = length - 1; i >= 0; i--) {
            if ('.' == value[i]) {
                ext_length = length - i - 1;
                file_extension = value + i + 1;
                break;
            }
        }
        
        if (file_extension && ext_length > 0) {
            if (!strcmp("flv", file_extension)) {
                io_type = CPILI_IO_TYPE_FILE;
                task->param.output.type = io_type;
                task->param.output.options.url = value;
                
                return true;
            }
        }
        
        return false;
    }
}

bool task_setter_vf(cpili_task_t *task, const char *value) {
    int intValue = atoi(value);
    if (intValue > 0 && intValue <= 60) {
        task->param.input.video_options.fps = intValue;
        return true;
    }
    
    return false;
}

bool task_setter_hf(cpili_task_t *task, const char *value) {
    if (!strcmp("avcc", value)) {
        task->param.output.video_options.bitstream_format = H264_FORMAT_AVCC;
        return true;
    } else if (!strcmp("annexb", value)) {
        task->param.output.video_options.bitstream_format = H264_FORMAT_ANNEXB;
        return true;
    }
    
    return false;
}

bool task_setter_sp(cpili_task_t *task, const char *value) {
    if (!strcmp("header-only", value)) {
        task->param.output.video_options.sps_pps_packetization_mode = H264_PMODE_HEADER_ONLY;
        return true;
    } else if (!strcmp("every-keyframe", value)) {
        task->param.output.video_options.sps_pps_packetization_mode = H264_PMODE_EVERY_KEYFRAME;
        return true;
    }
    
    return false;
}