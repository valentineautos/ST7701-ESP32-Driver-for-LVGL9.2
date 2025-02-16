#pragma once

#include <lvgl.h>
#include "lv_conf.h"
#include <esp_heap_caps.h>
#include "Display_ST7701.h"

#define LCD_WIDTH     ESP_PANEL_LCD_WIDTH
#define LCD_HEIGHT    ESP_PANEL_LCD_HEIGHT
#define LVGL_BUF_LEN  (ESP_PANEL_LCD_WIDTH * ESP_PANEL_LCD_HEIGHT / 5)

#define EXAMPLE_LVGL_TICK_PERIOD_MS  2


extern lv_display_t *disp;

void Lvgl_print(const char *buf);
void lvgl_flush_callback(lv_display_t *display, const lv_area_t *area, uint8_t *px_map);
void example_increase_lvgl_tick(void *arg);

void Lvgl_Init(void);
void Lvgl_Loop(void);
