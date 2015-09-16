//
//  tool_help.c
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#include <stdio.h>
#include "tool_help.h"

static const char *const help_text[] = {
    "cpili -i input_file [output options] -o output",
    "",
    "Options",
    "",
    "   Generic options",
    "",
    "       -h, --help",
    "           Show this message.",
    "",
    "       -v, --version",
    "           Show version information.",
    "",
    "   Main options",
    "",
    "       -i, --input <input file path> (input)",
    "           Input file path.",
    "",
    "       -o, --output <output RTMP url / output flv file path> (output)",
    "           Output RTMP url or output flv file path.",
    "",
    "   Video options",
    "",
    "       -vf, --video-fps <video frames per second> (input)",
    "           Video's fps value.",
    "",
    "       -hf, --h264-bitstream-format <H.264 bitstream format> (output)",
    "           Set H.264 bitstream format, it has effet on the way to packetize NAL units into flv tag.",
    "",
    "           Possible flags for this option are:",
    "",
    "           avcc (default)",
    "           annexb",
    "",
    "       -sp, --sps-pps-packetization-mode <sps pps packetization mode> (output)",
    "",
    "           Set sps and pps packetization mode.",
    "",
    "           Possible flags for this option are:",
    "",
    "           header-only (default)",
    "           every-keyframe",
    NULL
};

void tool_help() {
    for(int i = 0; help_text[i]; i++) {
        puts(help_text[i]);
    }
}