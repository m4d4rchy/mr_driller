 ##
 # Filename: Makefile
 # Project: mr_driller
 # Created Date: Monday, December 17th 2018, 1:48:06 pm
 # Author: yassine.b (yassine.b@caramail.com)
 # 
 # Copyright (c) 2018 - 2018 Yassine Benmessahel
 ##

CC	= 	gcc

LDFLAGS =	

INCLUDE =	include/

CFLAGS  =   	-lc_graph_prog -W -Wall -Werror -Wextra

NAME	= 	mr_driller

SRC 	=	src/main.c\
			src/game.c

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(SRC) -I$(INCLUDE) $(CFLAGS) $(LDFLAGS)

clean:
			rm -f $(OBJ)

fclean: 	clean
			$(RM) $(NAME)
re: 		fclean all

.PHONY: 	all clean fclean re
