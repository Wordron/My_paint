/*
** EPITECH PROJECT, 2023
** draw.c
** File description:
** draw
*/
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my_paint.h"

void draw_texts(s_paint *paint, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, paint->file->button->name, NULL);
    sfRenderWindow_drawText(window, paint->edit->button->name, NULL);
    sfRenderWindow_drawText(window, paint->help->button->name, NULL);
    sfRenderWindow_drawText(window, paint->pencil_size_menu.size_five->name,
        NULL);
    sfRenderWindow_drawText(window, paint->pencil_size_menu.size_ten->name,
        NULL);
    sfRenderWindow_drawText(window, paint->pencil_size_menu.size_fifty->name,
        NULL);
    sfRenderWindow_drawText(window, paint->pencil_size_menu.size_hundred->name,
        NULL);
    sfRenderWindow_drawText(window, paint->eraser_menu.square->name, NULL);
    sfRenderWindow_drawText(window, paint->eraser_menu.circle->name, NULL);
    sfRenderWindow_drawText(window, paint->eraser_menu.brush->name, NULL);
}

static void draw_buttons_2(s_paint *paint, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, paint->color_menu.red->rect,
        NULL);
    sfRenderWindow_drawRectangleShape(window, paint->color_menu.black->rect,
        NULL);
    sfRenderWindow_drawRectangleShape(window,
        paint->pencil_size_menu.size_five->rect, NULL);
    sfRenderWindow_drawRectangleShape(window,
        paint->pencil_size_menu.size_ten->rect, NULL);
    sfRenderWindow_drawRectangleShape(window,
        paint->pencil_size_menu.size_fifty->rect, NULL);
    sfRenderWindow_drawRectangleShape(window,
        paint->pencil_size_menu.size_hundred->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, paint->eraser_menu.square->rect,
        NULL);
    sfRenderWindow_drawRectangleShape(window, paint->eraser_menu.circle->rect,
        NULL);
    sfRenderWindow_drawRectangleShape(window, paint->eraser_menu.brush->rect,
        NULL);
}

void draw_buttons(s_paint *paint, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, paint->file->button->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, paint->edit->button->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, paint->help->button->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, paint->color_menu.white->rect,
        NULL);
    sfRenderWindow_drawRectangleShape(window, paint->color_menu.yellow->rect,
        NULL);
    sfRenderWindow_drawRectangleShape(window, paint->color_menu.green->rect,
        NULL);
    sfRenderWindow_drawRectangleShape(window, paint->color_menu.cyan->rect,
        NULL);
    sfRenderWindow_drawRectangleShape(window, paint->color_menu.blue->rect,
        NULL);
    sfRenderWindow_drawRectangleShape(window, paint->color_menu.magenta->rect,
        NULL);
    draw_buttons_2(paint, window);
    draw_texts(paint, window);
}
