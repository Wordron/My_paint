/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** update_buttons_display
*/
#include "include/my_paint.h"

static void change_buttons(s_paint *paint, sfRenderWindow *window)
{
    change_color_button(paint->color_menu.magenta, sfBlack);
    change_color_button(paint->color_menu.yellow, sfBlack);
    change_size_button(paint->pencil_size_menu.size_five);
    change_size_button(paint->pencil_size_menu.size_ten);
    change_size_button(paint->pencil_size_menu.size_fifty);
    change_size_button(paint->pencil_size_menu.size_hundred);
    change_size_button(paint->eraser_menu.square);
    change_size_button(paint->eraser_menu.circle);
    change_size_button(paint->eraser_menu.brush);
    sfRenderWindow_display(window);
}

void color_buttons(s_paint *paint, sfRenderWindow *window)
{
    change_current_color(paint);
    change_current_size(paint);
    change_color_button(paint->color_menu.black, sfRed);
    change_color_button(paint->color_menu.white, sfBlack);
    change_color_button(paint->color_menu.blue, sfBlack);
    change_color_button(paint->color_menu.cyan, sfBlack);
    change_color_button(paint->color_menu.red, sfBlack);
    change_color_button(paint->color_menu.green, sfBlack);
    show_button(paint->help_pop_up_menu, window);
    change_buttons(paint, window);
}

void check_and_display(s_paint *paint, sfRenderWindow *window)
{
    put_framebuffer(window, paint);
    sfRenderWindow_drawRectangleShape(window,
        paint->drawing_area.left_area, NULL);
    sfRenderWindow_drawRectangleShape(window,
        paint->drawing_area.up_area, NULL);
    sfRenderWindow_drawRectangleShape(window,
        paint->drawing_area.right_area, NULL);
    sfRenderWindow_drawRectangleShape(window,
        paint->drawing_area.down_area, NULL);
    sfRenderWindow_drawRectangleShape(window,
        paint->drawing_area.area, NULL);
    draw_buttons(paint, window);
    show_button(paint->file_save, window);
    show_button(paint->open_file, window);
    show_button(paint->new_file, window);
    show_button(paint->pencil, window);
    show_button(paint->eraser, window);
    show_button(paint->about, window);
    show_button(paint->help2, window);
    color_buttons(paint, window);
}

void put_framebuffer(sfRenderWindow *window, s_paint *paint)
{
    if (paint->is_pressed == MOUSE_PRESSED
    && is_hover_area(paint->drawing_area.area,
        window, paint->current_pencil_size))
        draw_pixel(window, paint, sfMouse_getPositionRenderWindow(window));
    sfSprite_setTexture(paint->frame->frame_sprite,
        paint->frame->frame_texture, sfTrue);
    sfRenderWindow_drawSprite(window, paint->frame->frame_sprite, NULL);
}
