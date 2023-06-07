/*
** EPITECH PROJECT, 2023
** free.c
** File description:
** free
*/
#include <stdlib.h>
#include "include/my_paint.h"

void framebuffer_destroy(frame_t *frame)
{
    free(frame->pixels);
    sfTexture_destroy(frame->frame_texture);
    sfSprite_destroy(frame->frame_sprite);
    free(frame);
}

void free_button(button_t *button)
{
    sfRectangleShape_destroy(button->rect);
    sfText_destroy(button->name);
    free(button);
}

void free_everything_part_two(s_paint *paint)
{
    free_button(paint->eraser_menu.square);
    free_button(paint->eraser_menu.circle);
    free_button(paint->help_pop_up_menu);
    free(paint);
}

void free_everything(s_paint *paint)
{
    sfRectangleShape_destroy(paint->drawing_area.area);
    sfRectangleShape_destroy(paint->drawing_area.left_area);
    sfRectangleShape_destroy(paint->drawing_area.up_area);
    sfRectangleShape_destroy(paint->drawing_area.down_area);
    sfRectangleShape_destroy(paint->drawing_area.right_area);
    free_button(paint->color_menu.black);
    free_button(paint->color_menu.blue);
    free_button(paint->color_menu.cyan);
    free_button(paint->color_menu.green);
    free_button(paint->color_menu.magenta);
    free_button(paint->color_menu.red);
    free_button(paint->color_menu.white);
    free_button(paint->color_menu.yellow);
    free_button(paint->pencil_size_menu.size_fifty);
    free_button(paint->pencil_size_menu.size_five);
    free_button(paint->pencil_size_menu.size_hundred);
    free_button(paint->pencil_size_menu.size_ten);
    free_everything_part_two(paint);
}
