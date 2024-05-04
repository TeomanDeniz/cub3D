/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H 202403

#include <stdio.h> ////////////
#include <unistd.h>

/* ********************* [V] CONSTANTS - GAME SETUP [V] ********************* */
# define SLICE 0.1
# define WINDOW_WIDTH 2200
# define WINDOW_HEIGHT 1200
# define RAY_MULTIPY 8
# define PERSPECTIVE 66.0
# define WALL_SIZE 600 // WINDOW_HEIGHT / 2 (PX)
# define ROTATE_SPEED 0.03
# define PLAYER_SPEED 0.2
# define CELL_SIZE 1.0F // ???
# define RENDER_DISTANCE 100.0F // LIMIT OF RENDER DISTANCE
/* ********************* [^] CONSTANTS - GAME SETUP [^] ********************* */

/* ******************* [v] CONSTANTS - ERROR MESSAGES [v] ******************* */
# define ERROR4 "Allocaction error."
/* ******************* [^] CONSTANTS - ERROR MESSAGES [^] ******************* */

/* *********************** [V] CONSTANTS - INPUTS [V] *********************** */
# define LETTER_KEY_LEFT 0 // A
# define LETTER_KEY_RIGHT 2 // D
# define LETTER_KEY_UP 13 // W
# define LETTER_KEY_DOWN 1 // S
# define ARROW_KEY_LEFT 123 // <-
# define ARROW_KEY_RIGHT 124 // ->
# define ARROW_KEY_UP 126 // ^
# define ARROW_KEY_DOWN 125 // V
# define KEY_ESC 53 // ESC
/* *********************** [^] CONSTANTS - INPUTS [^] *********************** */

/* **************************** [v] INCLUDES [v] **************************** */
# include <stdlib.h> /*
# typedef size_t;
#         */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [V] STRUCTS [V] **************************** */
typedef struct s_image
{
	void			*image; // Original image pointer. For MLX of course!
	char			*buffer; // Pixel matrix, please use it as an array
	int				bits_per_pixel; // Hpw many bits a pixel uses
	int				line_length; // How many pixels a line has
	int				endian; // wtf is that
	unsigned int	x; // Max Image X size
	unsigned int	y; // Max Image Y size
	unsigned int	size; // Total pixel size of image
}	t_image;

struct s_ray
{
	float	x; // Ray's Y coordinate on the map
	float	y; // Ray's X coordinate on the map
	float	distance; // Distance between ray and player
	float	theta; // The angle of ray we throwed
	float	cos_theta;
	float	sin_theta;
	float	x_distance; // The total distance of only ray's x position
	float	y_distance; // The total distance of only ray's y position
	float	x_teleport_distance; // Distance between 2 grids of x_theta
	float	y_teleport_distance; // Distance between 2 grids of y_theta
};

typedef struct s_game
{
	/* [v]			MLX [v] */
	void			*mlx; // MiniLibX MLX PTR
	void			*window; // MiniLibX Window PTR
	char			*window_title; // Window name
	char			**argv;
	int				argc;
	t_image			canvas; // The real paint
	/* [^]			MLX [^] */

	/* [v]			CHARACTER VALUES [v] */
	float			perspective; // The perspective
	float			x; // Player X coordinate on the map
	float			y; // Player Y coordinate on the map
	float			target_x; // For smooting lerp()
	float			target_y; // For smooting lerp()
	unsigned int	key[8]; // Key input (They are actually bool, 1/0)
	/* [^]			CHARACTER VALUES [^] */

	/* [v]			MATH FORMULAS [v] */
	float			theta_rotation; // Angle of player rotation
	float			theta_target_rotation; // For smooting lerp()
	float			theta_perspective; // The angle of perspective
	float			cos_theta_rotation; // cos(game->theta_rotation)
	float			sin_theta_rotation; // sin(game->theta_rotation)
	float			wall_pixel_width; // A calculation for... Idk
	float			skyline; // The Z coordinate of walls
	float			target_skyline; // For smooting lerp()
	int				number_of_rays; // The number of rays in the perspective
	struct s_ray	*ray; // Rays
	/* [^]			MATH FORMULAS [^] */

	/* [v]			MAP [v] */
	char			**map; // Map lol
	int				map_width; // map[ ][*]
	int				map_height; // map[*][ ]
	/* [^]			MAP [^] */

	/* [v]			SOME EXTRA VARIABLES FOR THROWING RAY [v] */
	float			jump_x; // Jumping x for calculating y [y][jump_x]
	float			jump_y; // Jumping y for calculating x [jump_y][x]
	float			add_x; // Adder to jump_x variable += (-1 || 0 || 1)
	float			add_y; // Adder to jump_y variable += (-1 || 0 || 1)
	unsigned int	touching_corner; // If both x&y of ray touching corner
	/* [^]			SOME EXTRA VARIABLES FOR THROWING RAY [^] */
}	*t_game;
/* ***************************** [^] STRUCTS [^] **************************** */

/* ************************ [V] ./exit_functions [V] ************************ */
extern void	game_error(t_game game, char *message);
extern int	close_window(t_game game);
/* ************************ [^] ./exit_functions [^] ************************ */

/* **************************** [V] ./events [V] **************************** */
extern int	key_down(int key, t_game game);
extern int	key_up(int key, t_game game);
/* **************************** [^] ./events [^] **************************** */

/* **************************** [v] ./setup [v] ***************************** */
extern void	setup(t_game game, int argc, char **argv);
/* **************************** [^] ./setup [^] ***************************** */

/* **************************** [v] ./render [v] **************************** */
extern void	render(t_game game);
extern void	cast_rays(t_game game);
extern void	putpixel(t_game game, register int x, register int y, \
register int color);
extern void	skybox(t_game game, register int ground, register int floor);
/* **************************** [^] ./render [^] **************************** */

/****************************************************************************\
|*                        MINILIBX EVENT HOOK LIST                          *|
|****************************************************************************|
|*        02 KeyPress       | 14 NoExpose         | 26 CirculateNotify      *|
|*        03 KeyRelease     | 15 VisibilityNotify | 27 CirculateRequest     *|
|*        04 ButtonPress    | 16 CreateNotify     | 28 PropertyNotify       *|
|*        05 ButtonRelease  | 17 DestroyNotify    | 29 SelectionClear       *|
|*        06 MotionNotify   | 18 UnmapNotify      | 30 SelectionRequest     *|
|*        07 EnterNotify    | 19 MapNotify        | 31 SelectionNotify      *|
|*        08 LeaveNotify    | 20 MapRequest       | 32 ColormapNotify       *|
|*        09 FocusIn        | 21 ReparentNotify   | 33 ClientMessage        *|
|*        10 FocusOut       | 22 ConfigureNotify  | 34 MappingNotify        *|
|*        11 KeymapNotify   | 23 ConfigureRequest | 35 GenericEvent         *|
|*        12 Expose         | 24 GravityNotify    | 36 LASTEvent            *|
|*        13 GraphicsExpose | 25 ResizeRequest    |                         *|
\****************************************************************************/

/****************************************************************************\
|*                        MINILIBX MASK HOOK LIST                           *|
|****************************************************************************|
|*         (0L) NoEventMask            | (1L<<12) Button5MotionMask         *|
|*      (1L<<0) KeyPressMask           | (1L<<13) ButtonMotionMask          *|
|*      (1L<<1) KeyReleaseMask         | (1L<<14) KeymapStateMask           *|
|*      (1L<<2) ButtonPressMask        | (1L<<15) ExposureMask              *|
|*      (1L<<3) ButtonReleaseMask      | (1L<<16) VisibilityChangeMask      *|
|*      (1L<<4) EnterWindowMask        | (1L<<17) StructureNotifyMask       *|
|*      (1L<<5) LeaveWindowMask        | (1L<<18) ResizeRedirectMask        *|
|*      (1L<<6) PointerMotionMask      | (1L<<19) SubstructureNotifyMask    *|
|*      (1L<<7) PointerMotionHintMask  | (1L<<20) SubstructureRedirectMask  *|
|*      (1L<<8) Button1MotionMask      | (1L<<21) FocusChangeMask           *|
|*      (1L<<9) Button2MotionMask      | (1L<<22) PropertyChangeMask        *|
|*     (1L<<10) Button3MotionMask      | (1L<<23) ColormapChangeMask        *|
|*     (1L<<11) Button4MotionMask      | (1L<<24) OwnerGrabButtonMask       *|
\****************************************************************************/

#endif /* CUB3D_H */
