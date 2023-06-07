/*
** EPITECH PROJECT, 2022
** analyse_envents.c
** File description:
** analyse the events in a window
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "include/my_paint.h"

static void drop_menu_interaction(sfRenderWindow *window, s_paint *paint)
{
    is_button_menu_interacted(paint->help, paint->about, window,
        &(paint->event));
    is_pop_up_button_interacted(paint->help_pop_up_menu, window,
        &(paint->event));
    is_button_menu_interacted(paint->file, paint->file_save, window,
        &(paint->event));
    is_button_menu_interacted(paint->help, paint->help2, window,
        &(paint->event));
    if (IS_PRESSED(paint->help2->state))
        paint->help_pop_up_menu->state = PRESSED;
    is_button_menu_interacted(paint->edit, paint->pencil, window,
        &(paint->event));
    if (IS_PRESSED(paint->pencil->state))
        paint->current_color = sfBlack;
    is_button_menu_interacted(paint->edit, paint->eraser, window,
        &(paint->event));
    if (IS_PRESSED(paint->eraser->state))
        paint->current_color = sfWhite;
    if (IS_PRESSED(paint->file_save->state))
        save_picture(paint);
}

static void button_interaction(sfRenderWindow *window, s_paint *paint)
{
    is_button_interacted(paint->eraser_menu.circle, window, &(paint->event));
    if (IS_PRESSED(paint->eraser_menu.circle->state))
        paint->current_shape = CIRCLE;
    is_button_interacted(paint->eraser_menu.square, window, &(paint->event));
    if (IS_PRESSED(paint->eraser_menu.square->state))
        paint->current_shape = SQUARE;
    is_button_interacted(paint->eraser_menu.brush, window, &(paint->event));
    if (IS_PRESSED(paint->eraser_menu.brush->state))
        paint->current_shape = BRUSH;
    drop_menu_interaction(window, paint);
}

static void button_interacted(sfRenderWindow *window, s_paint *paint)
{
    is_button_interacted(paint->color_menu.black, window, &(paint->event));
    is_button_interacted(paint->color_menu.white, window, &(paint->event));
    is_button_interacted(paint->color_menu.blue, window, &(paint->event));
    is_button_interacted(paint->color_menu.cyan, window, &(paint->event));
    is_button_interacted(paint->color_menu.red, window, &(paint->event));
    is_button_interacted(paint->color_menu.green, window, &(paint->event));
    is_button_interacted(paint->color_menu.magenta, window, &(paint->event));
    is_button_interacted(paint->color_menu.yellow, window, &(paint->event));
    is_button_interacted(paint->pencil_size_menu.size_five, window,
        &(paint->event));
    is_button_interacted(paint->pencil_size_menu.size_ten, window,
        &(paint->event));
    is_button_interacted(paint->pencil_size_menu.size_fifty, window,
        &(paint->event));
    is_button_interacted(paint->pencil_size_menu.size_hundred, window,
        &(paint->event));
    button_interaction(window, paint);
}

static void analyse_window_event(sfRenderWindow *window, s_paint *paint)
{
    sfView *view = sfView_create();
    sfFloatRect area;

    if (paint->event.type == sfEvtResized) {
        area.left = 0;
        area.top = 0;
        area.width = paint->event.size.width;
        area.height = paint->event.size.height;
        view = sfView_createFromRect(area);
        sfRenderWindow_setView(window, view);
    }
}

void analyse_events(sfRenderWindow *window, s_paint *paint)
{
    sfVector2f size = {10, 10};

    button_interacted(window, paint);
    is_menu_interacted(paint->file, window, &(paint->event));
    is_menu_interacted(paint->edit, window, &(paint->event));
    is_menu_interacted(paint->help, window, &(paint->event));
    if (paint->event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (paint->event.type == sfEvtMouseButtonPressed &&
        is_hover_area(paint->drawing_area.area, window,
        paint->current_pencil_size))
        paint->is_pressed = MOUSE_PRESSED;
    if (paint->event.type == sfEvtMouseButtonReleased)
        paint->is_pressed = MOUSE_RELEASED;
    analyse_window_event(window, paint);
}
