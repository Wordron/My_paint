/*
** EPITECH PROJECT, 2022
** create_window.c
** File description:
** create a window
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "include/my_paint.h"

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};

    window = sfRenderWindow_create(video_mode, "My_paint",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}
