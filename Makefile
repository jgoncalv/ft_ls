# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 15:05:44 by jgoncalv          #+#    #+#              #
#    Updated: 2017/03/28 20:05:35 by jgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ls

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g

LIBFT_DIR	=	libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	$(LIBFT_DIR)includes/

SRC_DIR		=	srcs/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SRC_FILE	=	main.c\
init.c\
stat_args.c\
ls_output.c\
args_lst.c\
args_sort.c\
display.c\
struc_length_l.c\
file_info.c\
open_dir.c\
joinpath.c\
swap_arg.c\
bonus.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_FILE:.c=.o))

all:			$(NAME)

$(NAME):		$(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
	@$(CC) $(FLAGS) -I $(INC_DIR) -I $(LIBFT_INC) $(LIBFT_LIB) $(OBJS) -o $(NAME)

$(LIBFT_LIB):
	@make -j -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_INC)

clean:			cleanlib
	@rm -rf $(OBJ_DIR)

cleanlib:
	@make -C $(LIBFT_DIR) clean

fclean:			clean fcleanlib
	@rm -f $(NAME)

fcleanlib:		cleanlib
	@make -C $(LIBFT_DIR) fclean

re:				fclean all

relib:			fcleanlib $(LIBFT_LIB)

.PHONY:			fclean clean re relib cleanlib fcleanlib

-include $(OBJS:.o=.d)
