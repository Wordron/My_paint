/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** init_button_menu
*/
#include "include/my_paint.h"

button_t *set_up_menu_button(sfVector2f posi, sfColor color, char *name,
    sfVector2f size)
{
    button_t *color_button = init_button(posi, size, color, name);

    sfRectangleShape_setOutlineThickness(color_button->rect, 1);
    sfRectangleShape_setOutlineColor(color_button->rect, sfWhite);
    return (color_button);
}

static void init_color_menu_second(s_paint *paint, sfVector2f posi,
    sfVector2f size)
{
    paint->color_menu.blue = set_up_menu_button(posi, sfBlue,
        "blue", size);
    posi.x = posi.x + 30;
    paint->color_menu.magenta = set_up_menu_button(posi, sfMagenta,
        "magen", size);
    posi.x = posi.x + 30;
    paint->color_menu.red = set_up_menu_button(posi, sfRed,
        "red", size);
    posi.x = posi.x + 30;
    paint->color_menu.black = set_up_menu_button(posi, sfBlack,
        "black", size);
    paint->color_menu.black->state = PRESSED;
}

void init_color_menu(s_paint *paint)
{
    sfVector2f posi = {1750, 900};
    sfVector2f size = {25, 25};

    paint->color_menu.white = set_up_menu_button(posi, sfWhite,
        "white", size);
    posi.x = posi.x + 30;
    paint->color_menu.yellow = set_up_menu_button(posi, sfYellow,
        "yellow", size);
    posi.x = posi.x + 30;
    paint->color_menu.green = set_up_menu_button(posi, sfGreen,
        "green", size);
    posi.x = posi.x + 30;
    paint->color_menu.cyan = set_up_menu_button(posi, sfCyan,
        "cyan", size);
    posi.x = 1750;
    posi.y = posi.y + 30;
    init_color_menu_second(paint, posi, size);
}

static void init_pencile_size_menu_second(s_paint *paint, sfVector2f posi,
    sfVector2f size, sfVector2f posi_pen)
{
    paint->pencil_size_menu.size_ten->state = PRESSED;
    posi.x = posi.x + 50;
    paint->pencil_size_menu.size_fifty = set_up_menu_button(posi, sfRed,
        "50", size);
    posi_pen.x = sfRectangleShape_getPosition(
        paint->pencil_size_menu.size_fifty->rect).x + 7;
    sfText_setPosition(paint->pencil_size_menu.size_fifty->name, posi_pen);
    posi.x = posi.x + 50;
    paint->pencil_size_menu.size_hundred = set_up_menu_button(posi, sfRed,
        "100", size);
    posi_pen.x = sfRectangleShape_getPosition(
        paint->pencil_size_menu.size_hundred->rect).x + 2;
    sfText_setPosition(paint->pencil_size_menu.size_hundred->name, posi_pen);
}

void init_pencile_size_menu(s_paint *paint)
{
    sfVector2f posi = {1700, 800};
    sfVector2f size = {40, 40};
    sfVector2f posi_pen;

    paint->pencil_size_menu.size_five = set_up_menu_button(posi, sfRed,
        "5", size);
    posi_pen.x = sfRectangleShape_getPosition(
        paint->pencil_size_menu.size_five->rect).x + 14;
    posi_pen.y = sfRectangleShape_getPosition(
        paint->pencil_size_menu.size_five->rect).y;
    sfText_setPosition(paint->pencil_size_menu.size_five->name, posi_pen);
    posi.x = posi.x + 50;
    paint->pencil_size_menu.size_ten = set_up_menu_button(posi, sfRed,
        "10", size);
    posi_pen.x = sfRectangleShape_getPosition(
        paint->pencil_size_menu.size_ten->rect).x + 8;
    sfText_setPosition(paint->pencil_size_menu.size_ten->name, posi_pen);
    init_pencile_size_menu_second(paint, posi, size, posi_pen);
}
