/*
** EPITECH PROJECT, 2023
** init_drawing_area.c
** File description:
** init_drawing_area
*/
#include "include/my_paint.h"

static sfRectangleShape *create_drawing_area_limit(sfVector2f posi,
    sfVector2f size)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, sfWhite);
    sfRectangleShape_setPosition(rect, posi);
    sfRectangleShape_setSize(rect, size);
    return (rect);
}

static sfRectangleShape *init_area(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f posi = {150, 150};
    sfVector2f size = {1500, 800};

    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRectangleShape_setOutlineThickness(rect, 2);
    sfRectangleShape_setPosition(rect, posi);
    sfRectangleShape_setSize(rect, size);
    return (rect);
}

void init_drawing_area(s_paint *paint)
{
    sfVector2f posi = {0, 0};
    sfVector2f size = {150, 1080};

    paint->drawing_area.area = init_area();
    paint->drawing_area.left_area = create_drawing_area_limit(posi, size);
    posi.x = 1650;
    paint->drawing_area.right_area = create_drawing_area_limit(posi, size);
    size.x = 1500;
    size.y = 150;
    posi.x = 150;
    paint->drawing_area.up_area = create_drawing_area_limit(posi, size);
    posi.y = 950;
    paint->drawing_area.down_area = create_drawing_area_limit(posi, size);
}

void init_framebuffer(s_paint *paint)
{
    paint->frame = malloc(sizeof(frame_t));
    paint->frame->pixels = malloc(sizeof(sfUint8) * 1920 * 1080 * 8);
    paint->frame->width = 1920;
    paint->frame->height = 1080;
    paint->frame->frame_texture = sfTexture_create(1920, 1080);
    paint->frame->frame_sprite = sfSprite_create();
}
