/*
** EPITECH PROJECT, 2023
** check_events.c
** File description:
** check_events
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "include/my_paint.h"

void show_button(struct button_s *button, sfRenderWindow *window)
{
    if (button->state == HOVER || button->state == PRESSED) {
        sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
        sfRenderWindow_drawText(window, button->name, NULL);
    }
}

void is_pop_up_button_interacted(button_t *pop_up, sfRenderWindow *window,
    sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed)
        pop_up->state = NONE;
}

sfBool is_hover_area(sfRectangleShape *area, sfRenderWindow *window, int size)
{
    sfFloatRect rec = sfRectangleShape_getGlobalBounds(area);

    if (sfFloatRect_contains(&rec, sfMouse_getPositionRenderWindow(window).x,
        sfMouse_getPositionRenderWindow(window).y))
        return (sfTrue);
    else
        return (sfFalse);
}
