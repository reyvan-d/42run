/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:06:58 by khansman          #+#    #+#             */
/*   Updated: 2016/11/03 10:07:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_H
# define RUN_H

/*
** ----------\
** Includes   |
** ----------/
*/

# ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <GLUT/glut.h>
# else
#  include <GL/gl.h>
#  include <GL/glut.h>
# endif

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <libc.h>
# include <signal.h>
# include <errno.h>
# include <ctype.h>
# include <termios.h>
# include <term.h>

# include "../libft/includes/libft.h"

/*
** ----------\
** Defines    |
** ----------/
*/

/*
** Object Defines
*/
# define O_CUBE    1
# define O_SPHERE  2
# define O_TEAPOT  3

/*
** ----------\
** Structures |
** ----------/
*/

typedef struct	s_pos
{
	float		angle;
	float		lx;
	float		ly;
	float		lz;
	float		x;
	float		y;
	float		z;
	float		deltaAngle;
	float		deltaMove;
}				t_pos;

typedef struct	s_coord
{
	float		x;
	float		y;
	float		z;
}				t_coord;

typedef struct	s_eye
{
	float		ex;
	float		ey;
	float		ez;
	float		cx;
	float		cy;
	float		cz;
	float		ux;
	float		uy;
	float		uz;
}				t_eye;

typedef struct	s_object
{
	t_eye		eye;
	char		object_type;
	int			size;
}				t_object;

/*
** ----------\
** Global     |
** ----------/
*/

# ifdef MAIN_FILE

t_pos			g_pos;
t_eye			g_eye;
# else

extern t_pos	g_pos;
extern t_eye	g_eye;
# endif

/*
** ----------\
** Prototypes |
** ----------/
*/

/*
** change_size.cpp
*/
void			change_size(int width, int height);
/*
** compute.cpp
*/
void			compute_pos(float delta_move);
void			compute_dir(float delta_angle);
/*
** draw_box.cpp
*/
void			draw_main_box(char config);
/*
** draw_snowman.cpp
*/
void			draw_snowman(void);
/*
** draw_straight.cpp
*/
void 			draw_short_straight(void);
/*
** change_size.cpp
*/
void			change_size(int width, int height);
/*
** init_glut.cpp
*/
void			init_g_pos(void);
void			init_glut(int ac, char **av);
/*
** press_key.cpp
*/
void			press_key(int key, int x, int y);
/*
** release_key.cpp
*/
void			release_key(int key, int x, int y);
/*
** render_scene.cpp
*/
void			draw_36_snowmen(void);
void			draw_walls(void);
void			render_scene(void);


/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif