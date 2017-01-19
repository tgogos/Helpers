# ffmpeg cheat sheet

## send video file

```bash
# examples
ffmpeg -re -i big_buck_bunny.mp4 -vcodec mpeg4 -an -b 1024k -s 640x480 -f mpegts udp://10.143.0.246:9999?pkt_size=1316
ffmpeg -re -i big_buck_bunny_1080p_h264.mov -c:v mpeg4 -vtag xvid -b:v 5000k -an -f mpegts udp://10.143.0.234:9999

#       -re (input)
#           Read input at native frame rate. Mainly used to simulate a grab device.  or live input stream (e.g. when reading from a file). Should not be used with actual
#           grab devices or live input streams (where it can cause packet loss).  By default ffmpeg attempts to read the input(s) as fast as possible.  This option will slow
#           down the reading of the input(s) to the native frame rate of the input(s). It is useful for real-time output (e.g. live streaming).
#
#       -i filename (input)
#           input file name
#
#       -vcodec codec (output)
#           Set the video codec. This is an alias for "-codec:v".
#
#       -an (output)
#           Disable audio recording.
#
#       -s[:stream_specifier] size (input/output,per-stream)
#           Set frame size.
#
#           As an input option, this is a shortcut for the video_size private option, recognized by some demuxers for which the frame size is either not stored in the file
#           or is configurable -- e.g. raw video or video grabbers.
#
#           As an output option, this inserts the "scale" video filter to the end of the corresponding filtergraph. Please use the "scale" filter directly to insert it at
#           the beginning or some other place.
#
#           The format is wxh (default - same as source).
#
#       -f fmt (input/output)
#           Force input or output file format. The format is normally auto detected for input files and guessed from the file extension for output files, so this option is
#           not needed in most cases.


```
