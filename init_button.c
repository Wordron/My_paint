/*
** EPITECH PROJECT, 2023
** init_button.c
** File description:
** init_button
*/
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my_paint.h"

button_t *init_button(sfVector2f position, sfVector2f size, sfColor color,
    char *name)
{
    button_t *button = malloc(sizeof(button_t));

    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor(button->rect, color);
    button->state = NONE;
    set_name_button(button, name);
    return (button);
}

void change_size_button(button_t *button)
{
    if (IS_HOVER(button->state)) {
        sfRectangleShape_setOutlineThickness(button->rect, 2);
        sfRectangleShape_setOutlineColor(button->rect, sfBlack);
    }
    if (IS_PRESSED(button->state)) {
        sfRectangleShape_setOutlineThickness(button->rect, 4);
        sfRectangleShape_setOutlineColor(button->rect, sfBlack);
    }
    if (IS_NONE(button->state)) {
        sfRectangleShape_setOutlineThickness(button->rect, 1);
        sfRectangleShape_setOutlineColor(button->rect, sfWhite);
    }
}

void change_color_button(button_t *button, sfColor color)
{
    if (IS_HOVER(button->state)) {
        sfRectangleShape_setOutlineThickness(button->rect, 2);
        sfRectangleShape_setOutlineColor(button->rect, color);
    }
    if (IS_PRESSED(button->state)) {
        sfRectangleShape_setOutlineThickness(button->rect, 4);
        sfRectangleShape_setOutlineColor(button->rect, color);
    }
    if (IS_NONE(button->state)) {
        sfRectangleShape_setOutlineThickness(button->rect, 1);
        sfRectangleShape_setOutlineColor(button->rect, sfWhite);
    }
}

void change_current_color(s_paint *paint)
{
    if (IS_PRESSED(paint->color_menu.black->state))
        paint->current_color = sfBlack;
    if (IS_PRESSED(paint->color_menu.white->state))
        paint->current_color = sfWhite;
    if (IS_PRESSED(paint->color_menu.blue->state))
        paint->current_color = sfBlue;
    if (IS_PRESSED(paint->color_menu.cyan->state))
        paint->current_color = sfCyan;
    if (IS_PRESSED(paint->color_menu.red->state))
        paint->current_color = sfRed;
    if (IS_PRESSED(paint->color_menu.green->state))
        paint->current_color = sfGreen;
    if (IS_PRESSED(paint->color_menu.magenta->state))
        paint->current_color = sfMagenta;
    if (IS_PRESSED(paint->color_menu.yellow->state))
        paint->current_color = sfYellow;
}

void change_current_size(s_paint *paint)
{
    if (IS_PRESSED(paint->pencil_size_menu.size_five->state))
        paint->current_pencil_size = 5;
    if (IS_PRESSED(paint->pencil_size_menu.size_ten->state))
        paint->current_pencil_size = 10;
    if (IS_PRESSED(paint->pencil_size_menu.size_fifty->state))
        paint->current_pencil_size = 50;
    if (IS_PRESSED(paint->pencil_size_menu.size_hundred->state))
        paint->current_pencil_size = 100;
}
