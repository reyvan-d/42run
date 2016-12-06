# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khansman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/15 10:33:49 by khansman          #+#    #+#              #
#    Updated: 2016/11/12 18:06:22 by khansman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a				\

FLAGS = -Wall -Werror -Wextra -pedantic

COMP = clang

INC_PATH = includes/

SRCS_PATH = srcs/

OBJS_PATH = objs/

HEADER = libft.h

INCLUDES = libft.h			\

SRCS1 =	ft_atoi.c			\
		ft_bzero.c			\
		ft_isalnum.c		\
		ft_isalpha.c		\
		ft_isascii.c		\
		ft_isdigit.c		\
		ft_isprint.c		\
		ft_itoa.c			\
		ft_memalloc.c		\
		ft_memccpy.c		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_memcpy.c			\
		ft_memdel.c			\
		ft_memmove.c		\
		ft_memset.c			\
		ft_putchar_fd.c		\
		ft_putchar.c		\
		ft_putendl_fd.c		\

SRCS2 = ft_putendl.c		\
		ft_putnbr_fd.c		\
		ft_putnbr.c			\
		ft_putstr_fd.c		\
		ft_putstr.c			\
		ft_strcat.c			\
		ft_strchr.c			\
		ft_strclr.c			\
		ft_strcmp.c			\
		ft_strcpy.c			\
		ft_strdel.c			\
		ft_strdup.c			\
		ft_strequ.c			\
		ft_striter.c		\
		ft_striteri.c		\
		ft_strjoin.c		\
		ft_strlcat.c		\
		ft_strlen.c			\
		ft_strmap.c			\

SRCS3 = ft_strmapi.c		\
		ft_strncat.c		\
		ft_strncmp.c		\
		ft_strncpy.c		\
		ft_strnequ.c		\
		ft_strnew.c			\
		ft_strnstr.c		\
		ft_strrchr.c		\
		ft_strsplit.c		\
		ft_strstr.c			\
		ft_strsub.c			\
		ft_strtrim.c		\
		ft_tolower.c		\
		ft_toupper.c		\

SRCS4 = ft_lstnew.c			\
		ft_lstdelone.c		\
		ft_lstdel.c			\
		ft_lstadd.c			\
		ft_lstiter.c		\
		ft_lstmap.c			\
		ft_free2d.c			\
		ft_get_line.c		\
		ft_itoa_base.c		\
		ft_print_hex.c		\
		get_next_line.c		\
		ft_die.c			\
		ft_print_memory.c 	\
		ft_strtolower.c		\


SRCS_ALL = $(SRCS1) $(SRCS2) $(SRCS3) $(SRCS4)

OBJS_ALL = $(SRCS_ALL:.c=.o)

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_ALL))

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_ALL))

define colourecho
tput setaf 4
@echo $1
tput sgr0
endef

define colourecho2
tput setaf 10
@echo $1
tput sgr0
endef

all: $(NAME)

$(libft):
	@if [ ! -f $(NAME) ]; then \
		make $(NAME) ; else \
		echo make: "Nothing to be done for 'libft'." ; \
		fi

$(NAME):
	@if [ ! -f $(NAME) ]; then \
		make compile ; else \
		echo make: "Nothing to be done for 'all.'" ; \
		fi

compile: qme objs_dir $(OBJS)
	@$(call colourecho, "Compiling $(NAME)")
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@$(call colourecho, "Done Compiling!")

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(COMP) $(FLAGS) -o $@ -c $< -I$(INC_PATH)

clean:
	@$(call colourecho, "Removing object files.")
	@rm -Rf $(OBJS_PATH)
	@$(call colourecho, "Done cleaning!")
	@if [ -f includes/libft.h.gch ]; then \
		rm includes/libft.h.gch; \
		fi

fclean: clean
	@$(call colourecho, "Removing $(NAME)")
	@rm -Rf $(NAME)

re: fclean all

me: qme
	@$(call colourecho2, "\nAuthor:")
	cat -e author

objs_dir:
	@mkdir -p $(OBJS_PATH)

qme:
	@if [ ! -f author ]; then \
		whoami > author; \
	fi

norme:
	@clear
	@$(call colourecho2, "\nNorminette:")
	@norminette $(addprefix $(SRCS_PATH), $(SRCS1))
	@norminette $(addprefix $(SRCS_PATH), $(SRCS2))
	@norminette $(addprefix $(SRCS_PATH), $(SRCS3))
	@norminette $(addprefix $(SRCS_PATH), $(SRCS4))
	@norminette $(addprefix $(INC_PATH), $(HEADER))

test:
	@ $@ norminette $^ $(addprefix $(SRC_PATH), $(SRC_ALL))

format: norme me

objs: re

srcs: objs

.IGNORE: Makefile a.out author includes srcs

.DEFAULT: re

.EXPORT_ALL_VARIABLES:

.PHONY: clean fclean re objs_dir
