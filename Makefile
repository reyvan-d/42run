# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/28 11:16:22 by ggroener          #+#    #+#              #
#    Updated: 2016/10/08 10:32:05 by khansman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42run

CFLAGS =	-std=c++11 -Wno-deprecated-declarations -O3

#MAC
#CFLAGS2 = 	-framework OpenGL -framework GLUT -O3 -ltermcap \
			-Wno-deprecated-declarations
#Linix
CFLAGS2 =	-lGLU -lGL -lglut -Wno-deprecated-declarations \
			-O3 -ltermcap

CC = g++

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = abilities.cpp 				\
			change_size.cpp				\
			character.cpp				\
			compute.cpp					\
			draw_box.cpp				\
			draw_snowman.cpp			\
			draw_straight.cpp			\
			change_size.cpp				\
			health.cpp					\
			init_glut.cpp				\
			main.cpp					\
			pillar.cpp					\
			press_key.cpp				\
			random_range.cpp			\
			release_key.cpp				\
			render_cube.cpp				\
			render_log.cpp				\
			render_objects.cpp			\
			render_scene.cpp			\
			render_string.cpp			\
			set_view.cpp				\
			teapot.cpp					\

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.cpp=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

#uncomment these to work on Mac and comment to work on Linux.
#LIBRARY = -lmlx -L libft/ -lft -framework OpenGL -framework AppKit

#INCLUDES = -I includes/ -I libft/includes

#uncomment these to work on Linux and comment to work on Mac.
LIBRARY = -L /usr/X11/lib -lmlx -lX11 -lm -lXext -L libft/ -lft
 
INCLUDES = -I includes/ -I libft/includes -I /usr/X11/include

HEADER = 	$(INCLUDES_PATH)run.h		\

all: qme odir $(NAME)

define colourecho
	@tput setaf 14
	@echo $1
	@tput sgr0
endef

define colourecho2
	@tput setaf 2
	@echo $1
	@tput sgr0
endef

$(NAME): $(OBJS)
	@make -C libft
	@$(call colourecho, " - Making $(NAME)")
	@clear
	@$(CC) $(CFLAGS2) -o $(NAME) $^ $(LIBRARY) $(INCLUDES) -I$(INCLUDES_PATH)
	@clear
	@$(call colourecho, "Make Done!")

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	@$(call colourecho, " - Compiling $<")
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< -I$(INCLUDES_PATH)
	@$(call colourecho, "Compiling Done!")

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@make clean -C libft
	@$(call colourecho, " - Clearing object files")
	@rm -f $(OBJS)
	@$(call colourecho, "clean done!")

fclean: clean
	@make fclean -C libft
	@$(call colourecho, "Clearing executable files")
	@rm -f $(NAME)
	@$(call colourecho, "fclean done")

re: fclean all
	@$(call colourecho, "re Done!")

qre:
	@$(call colourecho, " - Clearing object files")
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@$(call colourecho, "clean done!")
	@make odir
	@make $(NAME)

format: norme me

norme: norm

norm:
	@clear
	@$(call colourecho2, "Norminette:")
	@norminette $(SRCS)
	@norminette $(HEADER)

fnorm: fnorme

fnorme:
	@clear
	@$(call colourecho2, "Norminette:")
	@find ./srcs -name "*.cpp" -maxdepth 1 -type f -exec norminette  {} \;
	@find ./includes -name "*.h" -maxdepth 1 -type f -exec norminette  {} \;

qme:
	@if [ ! -f author ]; then \
		whoami > author; \
	fi
	
me: qme
	cat -e author

submodule:
	git submodule init libft
	git submodule update
	git submodule sync -- libft

.PHONY: clean fclean re odir
