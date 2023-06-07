/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my_paint.h"

static void init(s_paint *paint)
{
    init_file_menu(paint);
    init_edit_menu(paint);
    init_help_menu(paint);
    init_color_menu(paint);
    init_framebuffer(paint);
    init_pencile_size_menu(paint);
    init_drawing_area(paint);
    init_buttons_eraser(paint);
    init_pop_up_menu(paint);
    paint->is_pressed = MOUSE_RELEASED;
    paint->current_shape = SQUARE;
}

void main(void)
{
    s_paint *paint = malloc(sizeof(s_paint));
    sfRenderWindow *window = create_window();

    init(paint);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfWhite);
        while (sfRenderWindow_pollEvent(window, &(paint->event)))
            analyse_events(window, paint);
        check_and_display(paint, window);
    }
    sfRenderWindow_destroy(window);
    framebuffer_destroy(paint->frame);
    free_everything(paint);
}
