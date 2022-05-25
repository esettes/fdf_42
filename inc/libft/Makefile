GREEN	=\033[0;32m
BBLUE	=\033[1;34m
LBLUE	=\033[2;34m
LRED	=\033[2;31m
LYELLOW	=\033[2;33m
LWHITE	= \033[2;37m
LGREEN	=\033[2;32m

NAME	= libft.a

SRCDIR	= ./src/
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC	= $(addprefix $(SRCDIR), $(SRCNAMES))
OBJDIR	= ./obj/
OBJS	= $(addprefix $(OBJDIR), $(SRCNAMES:.c=.o))

LIBINC	= ./inc/#libft.h
FLAGS	= -Wall -Wextra -Werror -glldb
CC	= gcc

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(FLAGS) -I$(LIBINC) -o $@ -c $<
	@echo "${LWHITE}Compiling $@ ${LGREEN}✓\033[0m"

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
#	@echo "${LBLUE}> Libft\t\t${LRED}...\033[0m"

all: $(NAME) ${OBJDIR}

clean:
	@rm -rf $(OBJDIR)*.o
#	@echo "${LBLUE}Libft\t\t${LWHITE}\033[0m"

fclean: clean
	@rm -fr $(NAME)
#	@echo "${BBLUE}> Libft\t\t${LYELLOW}Cleaning lib\t${GREEN}[OK]\033[0m"

re: fclean all

.PHONY: re clean fclean all
