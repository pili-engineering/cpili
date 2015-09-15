# cpili

A command line tool for streaming a raw H.264 / flv file over RTMP, it can also convert a raw H.264 file to flv file.

## Installation (Not ready yet)

With homebrew:

```shell
$ brew install cpili
```

With git:
```
$ git clone https://github.com/pili-engineering/cpili.git /tmp/cpili
$ cd /tmp/cpili
$ make install
```

## Usage

```shell
cpili [global options] {[input file options] -i <u>input_file</u>} ... {[output options] -o <u>output</u>}

Options

    Generic options
    
        -h, --help
            Show this message
            
        -v, --version
            Show version information
        
    Main options
    
        -i, --input <input file path> <u>(input)</u>
            Input file path.
            
        -o, --output <output RTMP url / output flv file path> <u>(output)</u>
            Output RTMP url or output flv file path.
            
    Video options
    
        -hf, --h264-bitstream-format <H.264 bitstream format> <u>(output)</u>
            Set H.264 bitstream format, it has effet on the way to packetize NAL units into flv tag.
            
            *Default*: avcc
            
            Possible flags for this option are:
            
            *avcc*
            *annexb*
            
        -sp, --sps-pps-packetization-mode <sps pps packetization mode> <u>(output)</u>
            Set sps and pps packetization mode.
            
            *Default*: header-only
            
            Possible flags for this option are:
            
            *header-only*
            *every-keyframe*
```

## Examples

Live streaming a raw H.264 file
```shell
$ cpili -i ~/Videos/test.h264 -o rtmp://publish-rtmp.live.com/hello/world
```

## License

MIT