/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:44:43 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/11 ??:??:?? by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

 KENAR TIRTIKLANMA

 BALIK GÖZ

 HARİTA KONTROLÜ

 HARİTAYI İŞLEME

*/

#include <stdio.h> ////////////////////////// DELETE

#ifndef CUB3D_H
# define CUB3D_H 202403

/* *********************** [v] CONSTANTS - OTHERS [v] *********************** */
# define PLAYER_SPEED 0.02
# define M_2XPI 6.283185307
/* *********************** [^] CONSTANTS - PLAYER [^] *********************** */

/* *********************** [v] CONSTANTS - ERRORS [v] *********************** */
# define ERROR1 "Failed to open MLX"
# define ERROR2 "Failed to open windows via using MLX"
# define ERROR3 "RAM failed to allocate 'game->photon'"
# define ERROR4 "Failed to open 'game->render.image' via using MLX"
/* *********************** [^] CONSTANTS - ERRORS [^] *********************** */

/* ********************* [v] CONSTANTS - GAME SETUP [v] ********************* */
# define DEFAULT_PERSPECTIVE 66.0 // DEGREE
# define PHOTON_MULTIPY 8.0
# define DEFULT_WINDOW_X_SIZE 2200
# define DEFULT_WINDOW_Y_SIZE 1200
# define RENDER_EPSILON 0.01
# define ROTATE_SPEED 1.5 // DEGREE
# define WALL_SIZE DEFULT_WINDOW_Y_SIZE / 2 // PX
# define SLICE 0.1
/* ********************* [^] CONSTANTS - GAME SETUP [^] ********************* */

/* *********************** [v] CONSTANTS - INPUTS [v] *********************** */
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
# */
# include <stdbool.h> /*
# typedef bool;
# */
/* **************************** [^] INCLUDES [^] **************************** */

/* ***************************** [v] STRUCTS [v] **************************** */
struct s_photon
{
	double	distance;
	double	angle;
	double	fish_eye_fix;
};

typedef struct s_image
{
	void	*image;
	char	*buffer;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	char			**map;
	struct s_photon	*photon;
	size_t			photon_len;
	double			perspective;
	double			perspective_angle;
	double			rotate;
	double			target_rotate;
	double			rotate_angle;
	double			player_x;
	double			player_y;
	double			target_player_x;
	double			target_player_y;
	double			wall_pixel_size;
	double			cos_angle;
	double			sin_angle;
	double			fix_fish_eye;
	int				window_x;
	int				window_y;
	double			skyline;
	double			target_skyline;
	bool			move[8];
	bool			setup;
	t_image			render;
}	*t_game;
/* ***************************** [^] STRUCTS [^] **************************** */

/* ************************ [v] ./exit_functions [v] ************************ */
extern void	game_error(t_game game, char *error_message, char mode);
extern int	close_window(t_game game);
/* ************************ [^] ./exit_functions [^] ************************ */

/* **************************** [v] ./setup [v] ***************************** */
extern void	setup(t_game game);
/* **************************** [^] ./setup [^] ***************************** */

/* ************************** [v] ./game_exit [v] *************************** */
extern void	exit_game(t_game game, int error_level);
/* ************************** [^] ./game_exit [^] *************************** */

/* ************************** [v] ./error_game [v] ************************** */
extern void	error_game(t_game game, const char *const error_message);
/* ************************** [^] ./error_game [^] ************************** */

/* ************************** [v] ./free_game [v] *************************** */
extern void	free_game(t_game game);
/* ************************** [^] ./free_game [^] *************************** */

/* ************************** [v] ./raycasting [v] ************************** */
extern void	raycasting(t_game game);
/* ************************** [^] ./raycasting [^] ************************** */

/* ************************* [v] ./game_events [v] ************************** */
extern int	close_game(void *arg);
extern int	key_up(int key, void *arg);
extern int	key_down(int key, void *arg);
/* ************************* [^] ./game_events [^] ************************** */

/* **************************** [v] ./render [v] **************************** */
extern void	putpixel(t_game game, register int x, register int y, \
register int color);
extern void	clear_window(t_game game);
extern void	render(t_game game);
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
