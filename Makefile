# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsliu <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 11:49:10 by hsliu             #+#    #+#              #
#    Updated: 2022/12/27 17:13:28 by hsliu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

MAKE	=	make

SRC_DIR	=	./src/

OBJ_DIR	=	./.obj/

INC_DIR	=	./include/

LIST_SRC	=	pipex.c   ft_fork.c  ft_init_cmd.c  ft_init_arg.c \
				ft_init_pathname.c ft_init_pipe.c ft_free_cmd.c

LIST_OBJ	=	$(LIST_SRC:.c=.o) 

LIST_INC	=	pipex.h 

SRC		=	$(addprefix $(SRC_DIR), $(LIST_SRC))

OBJ		=	$(addprefix $(OBJ_DIR), $(LIST_OBJ))

INC		=	$(addprefix $(INC_DIR), $(LIST_INC))

LIB_DIR	=	libftprintf

LIB		=	libftprintf/libftprintf.a

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME)	:	$(OBJ_DIR) $(OBJ) $(INC) $(LIB) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

$(LIB): $(LIB_DIR)
	$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) 

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

clean : 
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: clean fclearn re all
