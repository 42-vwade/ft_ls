
########################################################	MAIN MAKEFILE	####
####	CONTROL PANEL	########################################################

NAME		=	ft_ls
BUILDDIR	=	build
SRCDIR		=	source
OBJDIR		=	obj
LIBFT		=	libft/libft.a
CFILES		=	$(shell find $(SRCDIR) ! -name "._*" -regex ".*\\.[c]")
LFILES		=	$(shell find $(dir $(LIBFT)) ! -name "._*" -regex ".*\\.[c]")
FLAGS		:=	$(FLAGS) -Wall -Wextra
FLAGS		:=	$(FLAGS) -Werror

####	DEBUGGING		########################################################

FLAGS		:=	-Wall -Wextra -g

####	AUTO SETTING	########################################################

OBJDIR		:=	$(addprefix $(BUILDDIR)/, $(OBJDIR))
OBJECTS		=	$(addprefix $(OBJDIR)/, $(notdir $(CFILES:%.c=%.o)))

####	UNDER THE HOOD	########################################################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	@gcc $(FLAGS) -o $@ -L $(<D) -lft

$(OBJECTS): $(CFILES) | $(OBJDIR)
	@cd $(@D); gcc -c $(FLAGS) $(abspath $^)

$(LIBFT): | $(OBJDIR)
	@make -C $(@D)

$(OBJDIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJDIR) \
		make clean -C $(dir $(LIBFT))

fclean:
	@rm -rf $(BUILDDIR) \
		make fclean -C $(dir $(LIBFT))

re: fclean all

.PHONY: clean fclean all re