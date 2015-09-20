# cpili

A command line tool for streaming a raw H.264 / flv file over RTMP, it can also convert a raw H.264 file to flv file.

## Feature

- Done
    - [x] Flv file -> RTMP Streaming
- TODO
    - [ ] H.264 file -> RTMP Streaming
    - [ ] AAC file -> RTMP Streaing

## Installation (Not ready yet)

With homebrew:

```bash
$ brew install cpili
```

With git:

```
$ git clone git@github.com:pili-engineering/cpili.git /tmp/cpili
$ cd /tmp/cpili
$ make install
```

## Usage

```bash
cpili -i input_file [output options] -o output

Options

    Generic options
    
        -h, --help
            Show this message.
            
        -v, --version
            Show version information.
        
    Main options
    
        -i, --input <input file path> (input)
            Input file path.
            
        -o, --output <output RTMP url / output flv file path> (output)
            Output RTMP url or output flv file path.
            
    Video options
        
        -vf, --video-fps <video frames per second> (input)
            Video's fps value. Only work for H.264 input file.
        
        -hf, --h264-bitstream-format <H.264 bitstream format> (output)
            Set H.264 bitstream format, it has effet on the way to packetize NAL units into flv tag. Only work for H.264 input file.
            
            Possible flags for this option are:
            
            avcc (default)
            annexb
            
        -sp, --sps-pps-packetization-mode <sps pps packetization mode> (output)
            Set sps and pps packetization mode. Only work for H.264 input file.
            
            Possible flags for this option are:
            
            header-only (default)
            every-keyframe
```

## Examples

Live streaming a FLV file

```bash
$ cpili -i ~/Videos/test.flv -o rtmp://publish-rtmp.live.com/hello/world
```

## License

MIT