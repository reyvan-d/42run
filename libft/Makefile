# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/15 07:50:12 by ggroener          #+#    #+#              #
#    Updated: 2016/11/09 11:03:08 by ggroener         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = g++

CFLAGS = -Ofast -g -g3

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME1 = ft_atoi.cpp \
			ft_bzero.cpp \
			ft_isalnum.cpp \
			ft_isalpha.cpp \
			ft_isascii.cpp \
			ft_isdigit.cpp \
			ft_isprint.cpp \
			ft_itoa.cpp \
			ft_memalloc.cpp \
			ft_memccpy.cpp \
			ft_memchr.cpp \
			ft_memcmp.cpp \
			ft_memcpy.cpp \
			ft_memdel.cpp \
			ft_memmove.cpp \
			ft_memset.cpp \
			ft_putchar.cpp \
			ft_strsub_free.cpp \
			ft_strtrim_free.cpp \
			ft_exit.cpp \
			ft_free_2d_array.cpp \

SRCS_NAME2 = ft_putchar_fd.cpp \
			ft_putendl.cpp \
			ft_putendl_fd.cpp \
			ft_putnbr.cpp \
			ft_putnbr_fd.cpp \
			ft_putstr.cpp \
			ft_putstr_fd.cpp \
			ft_strcat.cpp \
			ft_strchr.cpp \
			ft_strclr.cpp \
			ft_strcmp.cpp \
			ft_strcpy.cpp \
			ft_strdel.cpp \
			ft_strdup.cpp \
			ft_strequ.cpp \
			ft_striter.cpp \
			ft_striteri.cpp \
			ft_strjoin.cpp \
			ft_strlcat.cpp \
			ft_strlen.cpp \
			ft_lstnew.cpp \
			ft_lstdelone.cpp \
			ft_lstdel.cpp \

SRCS_NAME3 = ft_strmap.cpp \
			ft_strmapi.cpp \
			ft_strncat.cpp \
			ft_strncmp.cpp \
			ft_strncpy.cpp \
			ft_strnequ.cpp \
			ft_strnew.cpp \
			ft_strnstr.cpp \
			ft_strrchr.cpp \
			ft_strsplit.cpp \
			ft_strstr.cpp \
			ft_strsub.cpp \
			ft_strtrim.cpp \
			ft_tolower.cpp \
			ft_toupper.cpp \
			ft_intlen.cpp \
			ft_printf_diff.cpp \
			ft_printf_hex.cpp \
			ft_printf_long.cpp \
			ft_printf_nbr_ld.cpp \
			ft_printf.cpp \
			ft_strisdigit.cpp \

SRCS_NAME4 = ft_lstadd.cpp \
			ft_lstiter.cpp \
			ft_lstmap.cpp \
			ft_strjoin_free1.cpp \
			ft_strjoin_free2.cpp \
			ft_strjoin_free3.cpp \
			ft_atod.cpp \
			ft_strcount.cpp \
			ft_strisdigit.cpp \
			ft_ltoa.cpp \
			ft_ultoa.cpp \
			ft_ltoa_base.cpp \
			ft_ultoa_base.cpp \
			ft_putwchar.cpp \
			ft_putwchar_fd.cpp \
			ft_putwstr.cpp \
			ft_putwstr_fd.cpp \
			ft_wstrlen.cpp \
			ft_wstrsub.cpp \
			ft_atol.cpp \
			ft_putul.cpp \
			ft_putul_fd.cpp \
			get_next_line.cpp 

SRCS4 = $(addprefix $(SRCS_PATH), $(SRCS_NAME4))

SRCS3 = $(addprefix $(SRCS_PATH), $(SRCS_NAME3))

SRCS2 = $(addprefix $(SRCS_PATH), $(SRCS_NAME2))

SRCS1 = $(addprefix $(SRCS_PATH), $(SRCS_NAME1))

SRCS = $(SRCS1) $(SRCS2) $(SRCS3) $(SRCS4)

HEADER = 	$(INCLUDES_PATH)libft.h \

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME1:.cpp=.o) $(SRCS_NAME2:.cpp=.o) $(SRCS_NAME3:.cpp=.o) $(SRCS_NAME4:.cpp=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

all: odir $(NAME)

$(NAME): $(OBJS)
	@echo " - Making $(NAME)"
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@clear
	@echo "Make Done!"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@echo " - Cleaning objs"
	@rm -f $(OBJS)
	@clear
	@echo "clean Done!"

fclean: clean
	@echo " - Cleaning executable"
	@rm -f $(NAME)
	@clear
	@echo "fclean Done!"

re: fclean all
	@echo "re Done!"

format: norm

norm:
	@clear
	@echo "Norminette:"
	@norminette $(HEADER)
	@echo "Header Done:"
	@norminette $(SRCS1)
	@echo "SRCS1 Done:"
	@norminette $(SRCS2)
	@echo "SRCS2 Done:"
	@norminette $(SRCS3)
	@echo "SRCS3 Done:"
	@norminette	$(SRCS4)
	@echo "SRCS4 Done:"
	
.PHONY: clean fclean re odir
