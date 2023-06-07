/*
** EPITECH PROJECT, 2023
** create_drop_menu.c
** File description:
** create_drop_menu
*/
#include <stdlib.h>
#include "include/my_paint.h"

s_gui_drop_menu *add_option_drop_menu(s_gui_drop_menu *drop_menu,
    button_t *button)
{
    s_gui_options *option = malloc(sizeof(s_gui_options));

    option->option = button;
    drop_menu->options = option;
    return (drop_menu);
}

s_gui_options *add_option_next(s_gui_options *option, button_t *button)
{
    s_gui_options *next = malloc(sizeof(s_gui_options));

    next->option = button;
    option->next = next;
    return (option);
}

s_gui_drop_menu *create_drop_menu(sfVector2f position, sfVector2f size,
    sfColor color, char *name)
{
    s_gui_drop_menu *menu = malloc(sizeof(s_gui_drop_menu));

    menu->button = init_button(position, size, color, name);
    return (menu);
}
