GREEN	=\033[0;32m
WHITE	= \033[0;37m
BWHITE	= \033[1;37m
LGREEN	=\033[2;32m
LWHITE	= \033[2;37m

$(NAME):	$(OBJS)
	@$(CC) $(DEB) $(CFLAGS) $(LIBX42_FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(GNL) $(LIBX42)
	@echo "${BWHITE}Compiling all\t${GREEN}[OK]\033[0m"

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(DEB) $(CFLAGS) $(ALLINC) -o $@ -c $<
	@echo "${LWHITE}Compiling $@ ${LGREEN}✓\033[0m"

clean:
	@rm -rf *.dSYM ${OBJDIR}*.o
	@echo "${CYAN} "
	@make -C $(dir $(LIBFT)) fclean
	@make -C $(dir $(GNL)) fclean
	@make -C $(dir $(LIBX42)) clean

fclean: clean
	@rm -rf $(NAME)
	@echo "${BWHITE}Cleaning all\t${GREEN}[OK]\033[0m"