#include "invasions.h"

#include "graphics/generic_button.h"
#include "graphics/graphics.h"
#include "graphics/lang_text.h"
#include "graphics/panel.h"
#include "graphics/text.h"
#include "graphics/window.h"
#include "scenario/editor.h"
#include "scenario/property.h"
#include "window/editor/attributes.h"

static void button_invasion(int id, int param2);

static generic_button buttons[] = {
    {20, 42, 310, 67, GB_IMMEDIATE, button_invasion, button_none, 0, 0},
    {20, 72, 310, 97, GB_IMMEDIATE, button_invasion, button_none, 1, 0},
    {20, 102, 310, 127, GB_IMMEDIATE, button_invasion, button_none, 2, 0},
    {20, 132, 310, 157, GB_IMMEDIATE, button_invasion, button_none, 3, 0},
    {20, 162, 310, 187, GB_IMMEDIATE, button_invasion, button_none, 4, 0},
    {20, 192, 310, 217, GB_IMMEDIATE, button_invasion, button_none, 5, 0},
    {20, 222, 310, 247, GB_IMMEDIATE, button_invasion, button_none, 6, 0},
    {20, 252, 310, 277, GB_IMMEDIATE, button_invasion, button_none, 7, 0},
    {20, 282, 310, 307, GB_IMMEDIATE, button_invasion, button_none, 8, 0},
    {20, 312, 310, 337, GB_IMMEDIATE, button_invasion, button_none, 9, 0},
    {320, 42, 610, 67, GB_IMMEDIATE, button_invasion, button_none, 10, 0},
    {320, 72, 610, 97, GB_IMMEDIATE, button_invasion, button_none, 11, 0},
    {320, 102, 610, 127, GB_IMMEDIATE, button_invasion, button_none, 12, 0},
    {320, 132, 610, 157, GB_IMMEDIATE, button_invasion, button_none, 13, 0},
    {320, 162, 610, 187, GB_IMMEDIATE, button_invasion, button_none, 14, 0},
    {320, 192, 610, 217, GB_IMMEDIATE, button_invasion, button_none, 15, 0},
    {320, 222, 610, 247, GB_IMMEDIATE, button_invasion, button_none, 16, 0},
    {320, 252, 610, 277, GB_IMMEDIATE, button_invasion, button_none, 17, 0},
    {320, 282, 610, 307, GB_IMMEDIATE, button_invasion, button_none, 18, 0},
    {320, 312, 610, 337, GB_IMMEDIATE, button_invasion, button_none, 19, 0},
};

static int focus_button_id;

static void draw_background(void)
{
    // TODO draw city map
}

static void draw_foreground(void)
{
    graphics_in_dialog();

    outer_panel_draw(0, 0, 40, 30);
    lang_text_draw(44, 15, 20, 12, FONT_LARGE_BLACK);
    lang_text_draw_centered(13, 3, 0, 456, 640, FONT_NORMAL_BLACK);
    lang_text_draw_multiline(152, 2, 32, 376, 576, FONT_NORMAL_BLACK);

    for (int i = 0; i < 20; i++) {
        int x, y;
        if (i < 10) {
            x = 20;
            y = 42 + 30 * i;
        } else {
            x = 320;
            y = 42 + 30 * (i - 10);
        }
        button_border_draw(x, y, 290, 25, focus_button_id == i + 1);
        editor_invasion invasion;
        scenario_editor_invasion_get(i, &invasion);
        if (invasion.type) {
            text_draw_number(invasion.year, '+', " ", x + 6, y + 6, FONT_NORMAL_BLACK);
            lang_text_draw_year(scenario_property_start_year() + invasion.year, x + 60, y + 6, FONT_NORMAL_BLACK);
            int width = text_draw_number(invasion.amount, '@', " ", x + 120, y + 6, FONT_NORMAL_BLACK);
            lang_text_draw(34, invasion.type, x + 115 + width, y + 6, FONT_NORMAL_BLACK);
        } else {
            lang_text_draw_centered(44, 23, x, y + 6, 290, FONT_NORMAL_BLACK);
        }
    }

    graphics_reset_dialog();
}

static void handle_mouse(const mouse *m)
{
    if (m->right.went_down) {
        window_editor_attributes_show();
    } else {
        generic_buttons_handle_mouse(mouse_in_dialog(m), 0, 0, buttons, 20, &focus_button_id);
    }
}

static void button_invasion(int id, int param2)
{
    //window_editor_edit_invasion_show(id);
}

void window_editor_invasions_show(void)
{
    window_type window = {
        WINDOW_EDITOR_INVASIONS,
        draw_background,
        draw_foreground,
        handle_mouse
    };
    window_show(&window);
}
