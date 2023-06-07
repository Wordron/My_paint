/*
** EPITECH PROJECT, 2023
** save_image.c
** File description:
** save_image
*/
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "include/my_paint.h"
/*
int save_picture(s_paint *paint)
{
    int size = 1;
    FILE *picture;
    char *binary = malloc(sizeof(char) * 5000);

    for (int i = 0; paint->frame->pixels[i] != 0; i++)
        binary = strcat(binary, get_binary(paint->frame->pixels[i]));
    binary = strcat(binary, "\n");
    picture = fopen("test.jpg","w");
    fwrite(binary, 1, sizeof(binary) - 1, picture);
    return (0);
}
*/
char *get_binary(char a)
{
    int i = 0;
    char *str = malloc(9);

    for (i = 0 ; i < 8 ; i++) {
        str[i] = a % 2;
        a = a / 2;
    }
    str[8] = '\0';
    return (str);
}

int save_picture(s_paint *paint)
{
    return (0);
}
