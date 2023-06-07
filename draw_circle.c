/*
** EPITECH PROJECT, 2023
** draw_circle.c
** File description:
** draw_circle
*/
#include "include/my_paint.h"

static void my_put_pixel(frame_t *frame, unsigned int w,
    unsigned int h, sfColor color)
{
    frame->pixels[(h * frame->width + w) * 4] = color.r;
    frame->pixels[(h * frame->width + w) * 4 + 1] = color.g;
    frame->pixels[(h * frame->width + w) * 4 + 2] = color.b;
    frame->pixels[(h * frame->width + w) * 4 + 3] = color.a;
}

void my_draw_circle(frame_t *frame, sfVector2i position, unsigned int size,
    sfColor color)
{
    unsigned int temp_size = size;
    int y = 0;
    int temp_y = 0;

    for (; y < (size / 2); y++) {
        for (int x = 0; x < temp_size; x++)
            my_put_pixel(frame, position.x + x, position.y + y, color);
        temp_size = temp_size + 2;
        position.x--;
    }
    for (; temp_y <= size; temp_y++) {
        for (int x = 0; x < size * 2; x++)
            my_put_pixel(frame, position.x + x, position.y + y + temp_y, color);
    }
    y = y + temp_y;
    for (temp_y = 0; temp_y < size / 2; temp_y++) {
        for (int x = 0; x < (size * 2) - (temp_y * 2); x++)
            my_put_pixel(frame, position.x + x, position.y + y + temp_y, color);
        position.x = position.x + 1;
    }
}

void init_circle(sfRenderWindow *window, s_paint *paint, sfVector2i position)
{
    position.x = position.x - (paint->current_pencil_size / 2);
    position.y = position.y - paint->current_pencil_size;
    my_draw_circle(paint->frame, position, paint->current_pencil_size,
        paint->current_color);
}
