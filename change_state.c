/*
** EPITECH PROJECT, 2023
** change_menu_state.c
** File description:
** change_state
*/
#include <stdlib.h>
#include "include/my_paint.h"

void is_button_interacted(button_t *button, sfRenderWindow *window,
    sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed && is_hover(button, window))
        button->state = PRESSED;
    else {
        if (!IS_PRESSED(button->state) && is_hover(button, window))
            button->state = HOVER;
        if (IS_NONE(button->state) || IS_RELEASED(button->state))
            button->state = NONE;
    }
}

sfBool is_hover(button_t *button, sfRenderWindow *window)
{
    sfFloatRect rec = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&rec, sfMouse_getPositionRenderWindow(window).x,
        sfMouse_getPositionRenderWindow(window).y)) {
        button->state = HOVER;
        return (sfTrue);
    } else {
        button->state = NONE;
        return (sfFalse);
    }
}

void change_menu_state(s_gui_drop_menu *temp, int state)
{
    while (temp->options->next != NULL) {
        temp->options->option->state = state;
        temp->options = temp->options->next;
    }
    temp->options->option->state = state;
    temp->options = temp->options->next;
}

void is_button_menu_interacted(s_gui_drop_menu *menu, button_t *button,
    sfRenderWindow *window, sfEvent *event)
{
    if (IS_PRESSED(menu->button->state)
        && event->type == sfEvtMouseButtonPressed && is_hover(button, window))
        button->state = PRESSED;
    else if (IS_PRESSED(menu->button->state))
        button->state = HOVER;
}

void is_menu_interacted(s_gui_drop_menu *menu, sfRenderWindow *window,
    sfEvent *event)
{
    s_gui_drop_menu *temp = malloc(sizeof(s_gui_drop_menu));

    temp->options = menu->options;
    if (event->type == sfEvtMouseButtonPressed &&
        is_hover(menu->button, window)) {
        menu->button->state = PRESSED;
    } else {
        if (!IS_PRESSED(menu->button->state) && is_hover(menu->button, window))
            change_menu_state(temp, HOVER);
        if (IS_NONE(menu->button->state) || IS_RELEASED(menu->button->state))
            change_menu_state(temp, NONE);
    }
}
