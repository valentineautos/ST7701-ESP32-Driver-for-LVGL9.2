/*****************************************************************************
  | File        :   LVGL_Driver.c
  
  | help        : 
    The provided LVGL library file must be installed first
******************************************************************************/
#include "LVGL_Driver.h"

static lv_color_t* buf1 = (lv_color_t*)heap_caps_aligned_alloc(32, (LCD_WIDTH * LCD_HEIGHT * 2) / 6, MALLOC_CAP_DMA);
static lv_color_t* buf2 = (lv_color_t*)heap_caps_aligned_alloc(32, (LCD_WIDTH * LCD_HEIGHT * 2) / 6, MALLOC_CAP_DMA);

/*  Display flushing 
    Displays LVGL content on the LCD
    This function implements associating LVGL data to the LCD screen
*/
void flushDisplay(lv_display_t *disp, const lv_area_t *area, uint8_t *color_p) {
    LCD_addWindow(area->x1, area->x2, area->y1, area->y2, color_p);
    lv_display_flush_ready(disp);
}

void example_increase_lvgl_tick(void *arg)
{
    lv_tick_inc(EXAMPLE_LVGL_TICK_PERIOD_MS);
}

void Lvgl_Init(void)
{
  lv_init();
  lv_tick_set_cb(xTaskGetTickCount);
  
  lv_display_t *disp_drv = lv_display_create(LCD_WIDTH, LCD_HEIGHT);

  /* Initialize the draw buffer */
  lv_display_set_buffers(disp_drv, buf1, buf2, (LCD_WIDTH * LCD_HEIGHT) / 6, LV_DISPLAY_RENDER_MODE_PARTIAL);

  /* Set the display resolution */
  lv_display_set_resolution(disp_drv, LCD_WIDTH, LCD_HEIGHT);
  lv_display_set_physical_resolution(disp_drv, LCD_WIDTH, LCD_HEIGHT);

  /* Set flush callback */
  lv_display_set_flush_cb(disp_drv, flushDisplay);
}
