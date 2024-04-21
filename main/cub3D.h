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

/* ********************* [V] CONSTANTS - GAME SETUP [V] ********************* */
# define SLICE 0.2
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define RAY_MULTIPY 1
# define PERSPECTIVE 66.0
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

# include <stdlib.h> /*
# typedef size_t;
#         */

/* ***************************** [V] STRUCTS [V] **************************** */
typedef struct s_image
{
	void	*image;
	char	*buffer;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

struct s_ray
{
	double	x;
	double	y;
	double	distance;
	double	view;
	double	theta;

};

struct s_game
{
	/***[vvv] MLX [vvv]***/
	void			*mlx;
	void			*window;
	/***[^^^] MLX [^^^]***/
	/***[vvv] CHARACTER VALUES [vvv]***/
	size_t			perspective;
	double			x;
	double			y;
	/***[^^^] CHARACTER VALUES [^^^]***/
	/***[vvv] MATH FORMULAS [vvv]***/
	double			theta_rotation;
	double			theta_perspective;
	/***[^^^] MATH FORMULAS [^^^]***/
	char			*window_title;
	char			**map;
	unsigned int	movement[8];
	double			wall_pixel_width;
	size_t			ray_size;
	struct s_ray	*ray;
	t_image			canvas;
};
/* ***************************** [^] STRUCTS [^] **************************** */

/* ***************************** [V] TYPEDEF [V] **************************** */
typedef struct s_game	*t_game;
/* ***************************** [^] TYPEDEF [^] **************************** */

/* ************************ [V] ./exit_functions [V] ************************ */
extern void	game_error(t_game game, char *message);
extern int	close_window(t_game game);
/* ************************ [^] ./exit_functions [^] ************************ */

/* **************************** [V] ./events [V] **************************** */
extern int	key_down(int key, t_game game);
extern int	key_up(int key, t_game game);
/* **************************** [^] ./events [^] **************************** */

/* *************************** [v] ./set_game [v] *************************** */
extern void	set_game(t_game game, char **argv);
/* *************************** [^] ./set_game [^] *************************** */

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
