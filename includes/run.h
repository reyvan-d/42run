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
# include <stdio.h>
# include <signal.h>
# include <errno.h>
# include <ctype.h>
# include <termios.h>
# include <term.h>
#include <iostream>
#include <random>

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
# define O_PILLAR  4
# define O_LOG     5

# define OL_CENTER 0b00000010
# define OL_RIGHT  0b00000001
# define OL_LEFT   0b00000100
# define OL_TOP    0b00100000
# define OL_BOTTOM 0b00001000
# define OL_MID    0b00010000
# define OL_TRANS  0b10000000
# define OL_SPEC   0b01000000

/*
** Ability Defines
*/
# define AB_NONE   0
# define AB_FLY    1
# define AB_TRANS  2
# define AB_HEAL   3
# define AB_FAST   4
# define AB_SLOW   5

# define C_SNOWBAL 1

/*
** Gameplay
*/
# define RENDER_DIST  200
# define NUM_OBJS     30

# define WIN_WIDTH    720
# define WIN_HEIGHT   720
# define WIN_X        200
# define WIN_Y        200

/*
** Gamemode
*/
# define MODE_PLAY    1
# define MODE_STOP    2
# define MODE_PAUSE   3

/*
** ----------\
** Structures |
** ----------/
*/

typedef struct		s_vertex
{
	char		type;
	float		x;
	float		y;
	float		z;
	float		w;
}					t_vertex;

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
	char		object_type;
	char		lane;
	t_eye		eye;
	int			size;
	float		weight;
	t_coord		colour;
}				t_object;

typedef struct	s_window
{
	int			width;
	int			height;
}				t_win;

typedef struct	s_game
{
	char		mode;
	float		time;
	int			speed;
	int			render;
	int			render_min;
	float		score;
	float		health;
	float		high_score;
	char		ability;
	const char	*ability_str;
	float		ability_time;
	float		tmp;
}				t_game;

/*
** ----------\
** Global     |
** ----------/
*/

# ifdef MAIN_FILE

t_pos			g_pos;
t_eye			g_eye;
GLuint			*textures;
t_win			g_win;
t_game			g_game;
t_vertex		fnormals;
t_vertex		w1normals;
t_vertex		w2normals;
t_vertex		cnormals;
# else

extern t_pos	g_pos;
extern t_eye	g_eye;
extern GLuint	*textures;
extern t_win	g_win;
extern t_game	g_game;
extern t_vertex		fnormals;
extern t_vertex		w1normals;
extern t_vertex		w2normals;
extern t_vertex		cnormals;
# endif

/*
** ----------\
** Prototypes |
** ----------/
*/

void	init_normals(void);
t_vertex	normalise_point(t_vertex *p1, t_vertex *p2, t_vertex *p3);
void LoadTextureRAW(GLuint texture, const char *filename, int wrap, int width, int height);

/*
** abilities.cpp 
*/
void			activate_ability(char ability);
void			ability_clear(void);
void			ability_do(void);
/*
** change_size.cpp
*/
void			change_size(int width, int height);
/*
** character.cpp
*/
void			render_character(void);
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
** exit_prog.cpp 
*/
void			exit_prog(void);
/*
** change_size.cpp
*/
void			change_size(int width, int height);
/*
** health.cpp
*/
void			collide(t_object object);
void			calc_collision(t_object object);
/*
** init_glut.cpp
*/
void			init_g_pos(void);
void			init_glut(int ac, char **av);
/*
** pillar.cpp
*/
t_object		generate_pillar(void);
int				draw_pillar(t_object *pillar);
/*
** press_key.cpp
*/
void			press_key(int key, int x, int y);
/*
** random_range.cpp
*/
int				random_range(int min, int max);
/*
** release_key.cpp
*/
void			release_key(int key, int x, int y);
/*
** render_cube.cpp
*/
t_object		generate_cube(void);
int				draw_cube(t_object *cube);
/*
** render_log.cpp
*/
t_object		generate_log(void);
int				draw_log(t_object *log);
/*
** render_objects.cpp
*/
void			render_objects(void);
/*
** render_scene.cpp
*/
void			draw_36_snowmen(void);
void			draw_walls(void);
void			render_scene(void);
/*
** render_string.cpp
*/
void			render_string(t_coord pos, void *font, char *str);
void			render_game_stats(void);
void			render_game_over(void);
void			render_game_paused(void);
/*
** set_view.cpp
*/
void			set_orthographic_projection(void);
void			restore_perspective_projection(void);
/*
** teapot.cpp
*/
t_object		generate_teapot(void);
int				draw_teapot(t_object *teapot);

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif
