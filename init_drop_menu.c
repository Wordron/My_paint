/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** init_drop_menu
*/
#include "include/my_paint.h"
#include "include/button.h"

void set_name_button(button_t *button, char *name)
{
    sfVector2f posi = sfRectangleShape_getPosition(button->rect);

    posi.x = posi.x + 50;
    sfFont *font = sfFont_createFromFile("texture/American Captain.ttf");
    button->name = sfText_create();
    sfText_setString(button->name, name);
    sfText_setCharacterSize(button->name, 30);
    sfText_setPosition(button->name, posi);
    sfText_setFont(button->name, font);
    sfText_setColor(button->name, sfBlack);
}

void init_file_menu(s_paint *paint)
{
    sfVector2f posi = {150, 50};
    sfVector2f size = {150, 50};

    paint->file = create_drop_menu(posi, size, sfRed, "FILE");
    posi.y = posi.y + 50;
    paint->file_save = init_button(posi, size, sfYellow, "file save");
    posi.y = posi.y + 50;
    paint->new_file = init_button(posi, size, sfGreen, "new file");
    posi.y = posi.y + 50;
    paint->open_file = init_button(posi, size, sfYellow, "open file");
    paint->file = add_option_drop_menu(paint->file, paint->file_save);
    paint->file->options = add_option_next(paint->file->options,
        paint->new_file);
    paint->file->options->next = add_option_next(paint->file->options->next,
        paint->open_file);
    paint->file->options->next->next->next = NULL;
}

void init_edit_menu(s_paint *paint)
{
    sfVector2f posi = {300, 50};
    sfVector2f size = {150, 50};

    paint->edit = create_drop_menu(posi, size, sfBlue, "EDIT");
    posi.y = posi.y + 50;
    paint->pencil = init_button(posi, size, sfYellow, "pencil");
    paint->pencil->state = PRESSED;
    posi.y = posi.y + 50;
    paint->eraser = init_button(posi, size, sfGreen, "eraser");
    paint->edit = add_option_drop_menu(paint->edit, paint->pencil);
    paint->edit->options = add_option_next(paint->edit->options,
        paint->eraser);
    paint->edit->options->next->next = NULL;
}

void init_help_menu(s_paint *paint)
{
    sfVector2f posi = {450, 50};
    sfVector2f size = {150, 50};

    paint->help = create_drop_menu(posi, size, sfMagenta, "HELP");
    posi.y = posi.y + 50;
    paint->about = init_button(posi, size, sfYellow, "about");
    posi.y = posi.y + 50;
    paint->help2 = init_button(posi, size, sfGreen, "help");
    paint->help = add_option_drop_menu(paint->help, paint->about);
    paint->help->options = add_option_next(paint->help->options, paint->help2);
    paint->help->options->next->next = NULL;
}
