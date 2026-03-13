/*
 * M5Stick C Plus 1.1 – Hardware Abstraction Layer (compatibility API)
 *
 * Exposes the same API as m5stack_basic_v27_hal so app_main and ui.c
 * work unchanged. Physical display is 135x240; coordinates are scaled
 * from the logical 320x240 layout.
 *
 * Pinout per M5Stack docs (StickC-Plus): DC=23, RST=18, MOSI=15, SCLK=13, CS=5.
 * Buttons A=37, B=39; Power=35 (mapped as Button C).
 */

#ifndef M5STICKC_PLUS11_HAL_H
#define M5STICKC_PLUS11_HAL_H

#include <stdint.h>
#include <stdbool.h>
#include "esp_err.h"
#include "esp_lcd_types.h"

/* Logical resolution (UI uses 320x240) – physical is 135x240, scaling in .c */
#define M5_LCD_H_RES        320
#define M5_LCD_V_RES        240

/* Same API as m5stack_basic_v27_hal – implemented in m5stickc_plus11_hal.c */
int m5stack_basic_v27_init(void);
int m5stack_basic_v27_power_init(void);
int m5stack_basic_v27_display_init(void);
int m5stack_basic_v27_buttons_init(void);
bool m5stack_basic_v27_button_a_pressed(void);
bool m5stack_basic_v27_button_b_pressed(void);
bool m5stack_basic_v27_button_c_pressed(void);
void m5stack_basic_v27_display_set_brightness(uint8_t brightness);
esp_lcd_panel_handle_t m5stack_basic_v27_get_display_handle(void);
void m5stack_basic_v27_display_clear(uint16_t color);
void m5stack_basic_v27_display_show_boot_logo(void);
void m5stack_basic_v27_display_print(int x, int y, const char *text, uint16_t color);
void m5stack_basic_v27_display_print_scaled(int x, int y, const char *text, uint16_t color, int scale);
void m5stack_basic_v27_display_draw_bitmap(int x, int y, int width, int height, const uint8_t *bitmap, uint16_t color, uint16_t bg_color);
void m5stack_basic_v27_display_fill_circle(int x, int y, int radius, uint16_t color);
void m5stack_basic_v27_display_fill_rect(int x, int y, int width, int height, uint16_t color);

/* Colors (BGR ordering for ST7789) */
#define M5_COLOR_BLACK      0x0000
#define M5_COLOR_WHITE      0xFFFF
#define M5_COLOR_RED        0xF800
#define M5_COLOR_GREEN      0x001F
#define M5_COLOR_BLUE       0x07E0
#define M5_COLOR_YELLOW     0xFFE0
#define M5_COLOR_CYAN       0x07FF
#define M5_COLOR_MAGENTA    0xF81F
#define M5_COLOR_ORANGE     0xFDA0
#define M5_COLOR_PURPLE     0x8010
#define M5_COLOR_DARKGREY   0x39C6
#define M5_COLOR_GREY       0x7BEF
#define M5_COLOR_GRAY       0x8410

#endif /* M5STICKC_PLUS11_HAL_H */
