/*
** EPITECH PROJECT, 2023
** my_paint.h
** File description:
** my_paint
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "button.h"

#ifndef MY_PAINT_H_
    #define MY_PAINT_H_

    // structure of the colored button
    typedef struct {
        button_t *white;
        button_t *yellow;
        button_t *green;
        button_t *cyan;
        button_t *blue;
        button_t *magenta;
        button_t *red;
        button_t *black;
    } s_color_menu;

    // structure for the pencil size
    typedef struct s_pencil_size_menu {
        button_t *size_five;
        button_t *size_ten;
        button_t *size_fifty;
        button_t *size_hundred;
    }   s_pencil_size;

    // structure for the eraser shape
    typedef struct s_eraser_side_menu {
        button_t *square;
        button_t *circle;
        button_t *brush;
    }   s_eraser_shape_t;

    // structure containing the drawing area
    typedef struct s_drawing_area {
        sfRectangleShape *area;
        sfRectangleShape *right_area;
        sfRectangleShape *left_area;
        sfRectangleShape *up_area;
        sfRectangleShape *down_area;
    } s_drawing_area;

    // structure for put_pixel
    typedef struct frame_t {
        unsigned int width;
        unsigned int height;
        sfUint8 *pixels;
        sfSprite *frame_sprite;
        sfTexture *frame_texture;
    } frame_t;

    // main structure of my_paint
    typedef struct s_paint {
        int is_pressed;
        unsigned int current_pencil_size;
        unsigned int current_shape;
        button_t *help_pop_up_menu;
        sfEvent event;
        sfColor current_color;
        frame_t *frame;
        s_drawing_area drawing_area;
        s_color_menu color_menu;
        s_pencil_size pencil_size_menu;
        s_eraser_shape_t eraser_menu;
        // file drop menu
        s_gui_drop_menu *file;
        button_t *file_save;
        button_t *new_file;
        button_t *open_file;
        // edit drop menu
        s_gui_drop_menu *edit;
        button_t *pencil;
        button_t *eraser;
        // help drop menu
        s_gui_drop_menu *help;
        button_t *about;
        button_t *help2;
    } s_paint;

    sfRenderWindow *create_window(void);

    // creation of buttons and menu
    button_t *init_button(sfVector2f position, sfVector2f size, sfColor color,
            char *name);
    void set_name_button(button_t *button, char *name);
    s_gui_drop_menu *create_drop_menu(sfVector2f position, sfVector2f size,
            sfColor color, char *name);
    s_gui_drop_menu *add_option_drop_menu(s_gui_drop_menu *drop_menu,
            button_t *button);
    button_t *set_up_menu_button(sfVector2f posi, sfColor color, char *name,
            sfVector2f size);
    s_gui_options *add_option_next(s_gui_options *option, button_t *button);
    //init of a group of button
    void init_file_menu(s_paint *paint);
    void init_edit_menu(s_paint *paint);
    void init_help_menu(s_paint *paint);
    void init_color_menu(s_paint *paint);
    void init_pencile_size_menu(s_paint *paint);
    void init_framebuffer(s_paint *paint);
    void init_drawing_area(s_paint *paint);
    void init_buttons_eraser(s_paint *paint);
    void init_pop_up_menu(s_paint *paint);

    // event
    #define MOUSE_PRESSED  1
    #define MOUSE_RELEASED 0

    void analyse_events(sfRenderWindow *window, s_paint *paint);
    sfBool is_hover(button_t *button, sfRenderWindow *window);
    sfBool is_hover_area(sfRectangleShape *area, sfRenderWindow *window,
            int size);
    void is_button_interacted(button_t *button, sfRenderWindow *window,
            sfEvent *event);
    void is_menu_interacted(struct s_gui_drop_menu *menu,
            sfRenderWindow *window, sfEvent *event);
    void is_button_menu_interacted(s_gui_drop_menu *menu, button_t *button,
            sfRenderWindow *window, sfEvent *event);
    void is_pop_up_button_interacted(button_t *pop_up, sfRenderWindow *window,
        sfEvent *event);
    void change_menu_state(s_gui_drop_menu *temp, int state);
    void change_current_color(s_paint *paint);
    void change_current_size(s_paint *paint);

    // display
    #define BRUSH  2
    #define CIRCLE 1
    #define SQUARE 0
    void put_framebuffer(sfRenderWindow *window, s_paint *paint);
    void check_and_display(s_paint *paint, sfRenderWindow *window);
    void draw_buttons(s_paint *paint, sfRenderWindow *window);
    void draw_texts(s_paint *paint, sfRenderWindow *window);
    void draw_pixel(sfRenderWindow *window, s_paint *paint,
            sfVector2i position);
    void show_button(struct button_s *button, sfRenderWindow *window);
    void change_size_button(button_t *button);
    void change_color_button(button_t *button, sfColor color);
    void init_circle(sfRenderWindow *window, s_paint *paint,
            sfVector2i position);

    // free
    void framebuffer_destroy(frame_t *frame);
    void free_button(button_t *button);
    void free_everything(s_paint *paint);
    int save_picture(s_paint *paint);

#endif /* !MY_PAINT_H_ */
