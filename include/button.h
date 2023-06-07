/*
** EPITECH PROJECT, 2023
** button.h
** File description:
** boutton
*/
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Window/Event.h>

#ifndef BOUTTON_H_
    #define BOUTTON_H_

    enum e_gui_state {
        NONE = 0,
        HOVER,
        PRESSED,
        RELEASED
    };

    typedef struct button_s {
        sfRectangleShape *rect;
        sfText *name;
        sfBool (*is_clicked) (struct button_s *button,
            sfMouseButtonEvent *event);
        sfBool (*is_hover) (struct button_s *button,
            sfMouseButtonEvent *event);
        enum e_gui_state state;
    } button_t;

    typedef struct s_gui_options {
        struct button_s *option;
        struct s_gui_options *next;
    } s_gui_options;

    typedef struct s_gui_drop_menu {
        struct button_s *button;
        struct s_gui_options *options;
    } s_gui_drop_menu;

    #define IS_NONE(a) (a == NONE)
    #define IS_HOVER(a) (a == HOVER)
    #define IS_PRESSED(a) (a == PRESSED)
    #define IS_RELEASED(a) (a == RELEASED)

#endif /* !BOUTTON_H_ */
