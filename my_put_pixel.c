/*
** EPITECH PROJECT, 2023
** my_put_pixel.c
** File description:
** my_put_pixel
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "include/my_paint.h"

static void my_put_pixel(frame_t *frame, unsigned int w,
    unsigned int h, sfColor color)
{
    frame->pixels[(h * frame->width + w) * 4] = color.r;
    frame->pixels[(h * frame->width + w) * 4 + 1] = color.g;
    frame->pixels[(h * frame->width + w) * 4 + 2] = color.b;
    frame->pixels[(h * frame->width + w) * 4 + 3] = color.a;
}

static void my_draw_square(frame_t *frame, sfVector2i position,
    unsigned int size, sfColor color)
{
    for (unsigned int y = 0; y <= size; y++) {
        for (unsigned int x = 0; x <= size; x++)
            my_put_pixel(frame, position.x + x, position.y + y, color);
    }
}

static void do_rand(frame_t *frame, int x, int y, sfColor color)
{
    int tmp = rand() % 7;

    if (tmp < 4)
        my_put_pixel(frame, x, y, color);
}

static void my_draw_brush(frame_t *frame, sfVector2i position,
    unsigned int size, sfColor color)
{
    for (unsigned int y = 0; y <= size; y++) {
        for (unsigned int x = 0; x <= size; x++)
            do_rand(frame, position.x + x, position.y + y, color);
    }
}

void draw_pixel(sfRenderWindow *window, s_paint *paint, sfVector2i position)
{
    if (paint->current_shape == SQUARE) {
        position.x = position.x - (paint->current_pencil_size / 2);
        position.y = position.y - (paint->current_pencil_size / 2);
        my_draw_square(paint->frame, position, paint->current_pencil_size,
            paint->current_color);
    }
    if (paint->current_shape == CIRCLE)
        init_circle(window, paint, position);
    if (paint->current_shape == BRUSH) {
        position.x = position.x - (paint->current_pencil_size / 2);
        position.y = position.y - (paint->current_pencil_size / 2);
        my_draw_brush(paint->frame, position, paint->current_pencil_size,
            paint->current_color);
    }
    sfTexture_updateFromPixels(paint->frame->frame_texture,
        paint->frame->pixels, 1920, 1080, 0, 0);
}
