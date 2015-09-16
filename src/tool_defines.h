//
//  tool_defines.h
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#ifndef cpili_tool_defines_h
#define cpili_tool_defines_h

#include "h264_defines.h"

#define MAX_INPUT_FILE_PATH_LENGTH    1024
#define MAX_OUTPUT_URL_LENGTH         1024
#define MAX_ERROR_MESSAGE_LENGTH      1024

// bool
typedef enum {
    true,
    false
} bool;

// IO type
typedef enum cpili_io_type {
    CPILI_IO_TYPE_UNKNOW = 0,
    CPILI_IO_TYPE_FILE,
    CPILI_IO_TYPE_STREAM
} cpili_io_type_t;

// File format
typedef enum cpili_file_format {
    CPILI_FILE_FORMAT_UNKNOW = 0,
    CPILI_FILE_FORMAT_H264,
    CPILI_FILE_FORMAT_AAC,
    CPILI_FILE_FORMAT_FLV
} cpili_file_format_t;

// Stream protocol
typedef enum cpili_stream_protocol {
    CPILI_STREAM_PROTOCOL_UNKNOW = 0,
    CPILI_STREAM_PROTOCOL_RTMP
} cpili_stream_protocol_t;

// Input
struct cpili_input {
    cpili_file_format_t file_format;
    struct {
        const char  *file_path;
    } options;
    struct {
        int     fps;
    } video_options;
};

typedef struct cpili_input cpili_input_t;

static const cpili_input_t CPILI_INPUT_DEFAULT = {
    .file_format = CPILI_FILE_FORMAT_UNKNOW,
    .options = {
        .file_path = ""
    },
    .video_options = {
        .fps = 30
    }
};

// Output
struct cpili_output {
    cpili_io_type_t   type;
    cpili_file_format_t   file_format;
    cpili_stream_protocol_t   stream_protocol;
    struct {
        const char  *url;
    } options;
    struct {
        h264_bitstream_format_t bitstream_format;
        h264_sps_pps_packetization_mode_t   sps_pps_packetization_mode;
    } video_options;
};

typedef struct cpili_output cpili_output_t;

const cpili_output_t CPILI_OUTPUT_DEFAULT = {
    .type = CPILI_IO_TYPE_UNKNOW,
    .file_format = CPILI_FILE_FORMAT_UNKNOW,
    .stream_protocol = CPILI_STREAM_PROTOCOL_UNKNOW,
    .options = {
        .url = ""
    },
    .video_options = {
        .bitstream_format = H264_FORMAT_AVCC,
        .sps_pps_packetization_mode = H264_PMODE_HEADER_ONLY
    }
};

// Error
typedef enum cpili_error_code {
    CPILI_ERROR_NONE = 0,
    CPILI_ERROR_WRONG_PARAM,
    CPILI_ERROR_IO_ERROR
} cpili_error_code_t;

struct cpili_error {
    cpili_error_code_t code;
    const char *message;
};

typedef struct cpili_error cpili_error_t;

// Task
struct cpili_task_param {
    cpili_input_t   input;
    cpili_output_t  output;
};

typedef struct cpili_task_param cpili_task_param_t;

typedef void (*cpili_task_handler)(cpili_task_param_t param);

struct cpili_task {
    cpili_error_t       error;
    cpili_task_handler  handler;
    cpili_task_param_t  param;
};

typedef struct cpili_task cpili_task_t;

#endif
