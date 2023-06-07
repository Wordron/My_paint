/*
** EPITECH PROJECT, 2023
** init_pop_up_menu.c
** File description:
** init_pop_up_menu
*/
#include "include/my_paint.h"
#include "include/button.h"

void init_pop_up_menu(s_paint *paint)
{
    sfVector2f posi = {550, 400};
    sfVector2f size = {800, 100};

    paint->help_pop_up_menu = init_button(posi, size, sfGreen,
    "In the edit menu, you can choose between the pencil, with it's colors\n \
    and size at the bottom right and the eraser with it's size.\
    \nYou can only draw in the dedicated square in the center of the screen");
}
