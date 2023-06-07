##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	main.c	\
		create_window.c	\
		analyse_event.c	\
		init_drop_menu.c	\
		create_drop_menu.c	\
		change_state.c	\
		my_put_pixel.c 	\
		draw.c 	\
		free.c	\
		init_button_menu.c	\
		init_button.c 	\
		update_buttons_display.c	\
		init_drawing_area.c	\
		init_eraser_buttons.c 	\
		init_pop_up_menu.c	\
		save_image.c 	\
		draw_circle.c	\
		check_events.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS = -g

NAME	=	my_paint

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-system -l csfml-audio

clean:
		rm $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
