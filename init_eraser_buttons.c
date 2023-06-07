/*
** EPITECH PROJECT, 2023
** init_eraser_buttons.c
** File description:
** init_eraser_buttons
*/
#include "include/my_paint.h"

static void init_brush(s_paint *paint)
{
    sfVector2f posi = {1700, 630};
    sfVector2f size = {100, 50};
    sfVector2f posi_pen;

    paint->eraser_menu.brush = set_up_menu_button(posi, sfCyan,
        "Brush", size);
    posi_pen.x = sfRectangleShape_getPosition(
        paint->eraser_menu.brush->rect).x + 15;
    posi_pen.y = sfRectangleShape_getPosition(
        paint->eraser_menu.brush->rect).y;
    sfText_setPosition(paint->eraser_menu.brush->name, posi_pen);
}

void init_buttons_eraser(s_paint *paint)
{
    sfVector2f posi = {1700, 700};
    sfVector2f size = {100, 50};
    sfVector2f posi_pen;

    paint->eraser_menu.square = set_up_menu_button(posi, sfCyan,
        "Square", size);
    posi_pen.x = sfRectangleShape_getPosition(
        paint->eraser_menu.square->rect).x + 10;
    posi_pen.y = sfRectangleShape_getPosition(
        paint->eraser_menu.square->rect).y;
    sfText_setPosition(paint->eraser_menu.square->name, posi_pen);
    posi.x = posi.x + 110;
    paint->eraser_menu.circle = set_up_menu_button(posi, sfCyan,
        "Circle", size);
    posi_pen.x = sfRectangleShape_getPosition(
        paint->eraser_menu.circle->rect).x + 15;
    sfText_setPosition(paint->eraser_menu.circle->name, posi_pen);
    init_brush(paint);
    paint->eraser_menu.square->state = PRESSED;
}
