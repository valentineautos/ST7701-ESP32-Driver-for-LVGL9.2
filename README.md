Driver config for running LVGL 9.2 on a Waveshare 2.1" Round Touchscreen, utilising triple buffering.

To use on a Waveshare LCD Driver Board, adjust the three commented sections in Driver_ST7701.cpp as noted.
I recommend #define `LV_MEM_SIZE (120 * 1024U)` in lv_conf.h for the larger buffers.
