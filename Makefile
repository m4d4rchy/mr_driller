 ##
 # Filename: Makefile
 # Project: mr_driller
 # Created Date: Monday, December 17th 2018, 1:48:06 pm
 # Author: yassine.b (yassine.b@caramail.com)
 # 
 # Copyright (c) 2018 - 2018 Yassine Benmessahel
 ##

CC	= 	gcc

LDFLAGS =	lib/

INCLUDE =	include/

CFLAGS  =   	-Wl,-rpath=lib/ -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -W -Wall -Werror -Wextra

NAME	= 	mr_driller

SRC 	=	src/main.c\
			src/game.c\
			src/scorescreen.c\
			src/mapgenerate.c\
			src/main_menu.c\
			src/splashscreen.c\
			src/initialization.c

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(SRC) -I$(INCLUDE) -L$(LDFLAGS) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
