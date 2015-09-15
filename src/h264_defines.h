//
//  h264_defines.h
//  cpili
//
//  Created by 0dayZh on 15/9/16.
//  Copyright (c) 2015年 pili-engineering. All rights reserved.
//

#ifndef cpili_h264_defines_h
#define cpili_h264_defines_h

typedef enum h264_bitstream_format {
    H264_FORMAT_AVCC,
    H264_FORMAT_ANNEXB
} h264_bitstream_format_t;

typedef enum h264_sps_pps_packetization_mode {
    H264_PMODE_HEADER_ONLY,
    H264_PMODE_EVERY_KEYFRAME
} h264_sps_pps_packetization_mode_t;

#endif
