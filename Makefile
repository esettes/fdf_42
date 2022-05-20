# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 19:38:39 by iostancu          #+#    #+#              #
#    Updated: 2022/05/13 19:08:16 by iostancu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	=\033[0;32m
WHITE	= \033[0;37m
BWHITE	= \033[1;37m
LGREEN	=\033[2;32m
LWHITE	= \033[2;37m

NAME	= fdf

OS		=	$(shell uname -s)

SRCDIR	= ./src/
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC	= $(addprefix $(SRCDIR), $(SRCNAMES))
OBJDIR	= ./obj/
OBJS	= $(addprefix $(OBJDIR), $(SRCNAMES:.c=.o))

GNL	= ./inc/gnl/gnl.a
LIBFT	= ./inc/libft/libft.a
LIBX42	= ./inc/MLX42/libmlx42.a

ifeq ($(OS), Darwin)
	LIBX42_FLAGS	=	-I include -lglfw -L "/Users/${USER}/.brew/opt/glfw/lib/"
else
	LIBX42_FLAGS	=	-I include -ldl -lglfw
endif

ALLINC	= -I include -I ./inc/libft/inc/ -I ./inc/gnl/inc/ -I ./inc/fdf_h/ -I ./inc/MLX42/include/MLX42/

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
MFLAGS	= -lpthread -framework OpenGL -framework AppKit #-lmlx  -Lmlx
DEB	= -g

all: $(OBJDIR) $(LIBFT) $(GNL) $(LIBX42) $(NAME)
	
$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(DEB) $(CFLAGS) $(ALLINC) -o $@ -c $<
	@echo "${LWHITE}Compiling $@ ${LGREEN}✓\033[0m"

$(NAME):	$(OBJS)
	@$(CC) $(DEB) $(CFLAGS) $(LIBX42_FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(GNL) $(LIBX42)
	@echo "${BWHITE}Compiling all\t${GREEN}[OK]\033[0m" 

$(LIBFT):
	@echo "${CYAN} "
	@make -C $(dir $(LIBFT))

$(GNL):
	@make -C $(dir $(GNL))

$(LIBX42):
	@make -C $(dir $(LIBX42))

clean:
	@rm -rf *.dSYM ${OBJDIR}*.o
	@echo "${CYAN} "
	@make -C $(dir $(LIBFT)) fclean
	@make -C $(dir $(GNL)) fclean
	@make -C $(dir $(LIBX42)) clean

fclean: clean
	@rm -rf $(NAME)
	@echo "${BWHITE}Cleaning all\t${GREEN}[OK]\033[0m"

re: fclean all

.PHONY: all fclean clean re
