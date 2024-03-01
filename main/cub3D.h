/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:44:43 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/11 ??:??:?? by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H 202403

/* *********************** [V] CONSTANTS - PLAYER [V] *********************** */
# define PLAYER_SPEED 3.0
/* *********************** [^] CONSTANTS - PLAYER [^] *********************** */

/* ******************** [V] CONSTANTS - DEVICE SETUP [V] ******************** */
# define SPEED 250
/* ******************** [^] CONSTANTS - DEVICE SETUP [^] ******************** */

/* ********************* [V] CONSTANTS - GAME SETUP [V] ********************* */
# define SLICE 0.2
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500
/* ********************* [^] CONSTANTS - GAME SETUP [^] ********************* */

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

/* *************************** [V] MLX STRUCTS [V] ************************** */
typedef struct s_mlx_img_list
{
	int						width;
	int						height;
	char					*buffer;
	float					vertexes[8];
	struct s_mlx_img_list	*next;
}	t_game_img_list;

typedef struct s_mlx_img_ctx
{
	unsigned int			texture;
	unsigned int			vbuffer;
	t_game_img_list			*img;
	struct s_mlx_img_ctx	*next;
}	t_game_img_ctx;

typedef struct s_mlx_win_list
{
	void					*winid;
	t_game_img_ctx			*img_list;
	int						nb_flush;
	int						pixmgt;
	struct s_mlx_win_list	*next;
}	t_game_win_list;

typedef struct s_mlx_ptr
{
	void			*appid;
	t_game_win_list	*win_list;
	t_game_img_list	*img_list;
	void			(*loop_hook)(void *);
	void			*loop_hook_data;
	void			*loop_timer;
	t_game_img_list	*font;
	int				main_loop_active;
}	t_game_ptr;
/* *************************** [^] MLX STRUCTS [^] ************************** */

/* ***************************** [V] STRUCTS [V] **************************** */
struct s_player
{
	double	x;
	double	y;
	double	target_x;
	double	target_y;
	char	position[4];
	char	rotation;
};

/*struct s_wall
{
	int	x;
	int	y;
};*/

struct s_barrier
{
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
};

struct s_object
{
	struct s_player		player;
	//struct s_wall		*wall;
	struct s_barrier	*barrier;
	int					number_of_barriers;
	int					number_of_walls;
};

struct s_texture_packs
{
	void	*wall;
	void	*ground;
};

struct s_game {
	t_game_ptr				*mlx;
	void					*window;
	char					*window_title;
	int						window_width;
	int						window_height;
	char					**map;
	int						fps;
	int						game_speed;
	double					steps;
	struct s_texture_packs	texture_pack;
	struct s_object			object;
};
/* ***************************** [^] STRUCTS [^] **************************** */

/* ***************************** [V] TYPEDEF [V] **************************** */
typedef struct s_game	*t_game;
/* ***************************** [^] TYPEDEF [^] **************************** */

/* ************************ [V] ./EXIT_FUNCTIONS [V] ************************ */
extern void	game_error(t_game game, char *error_message, char mode);
extern int	close_window(t_game game);
/* ************************ [^] ./EXIT_FUNCTIONS [^] ************************ */

/* **************************** [V] ./EVENTS [V] **************************** */
extern int	key_down(int key, t_game game);
extern int	key_up(int key, t_game game);
extern void	player_position(t_game game);
extern void	debug(t_game game);
extern void	game(t_game game);
/* **************************** [^] ./EVENTS [^] **************************** */

/* *************************** [V] ./SEt_game [V] **************************** */
extern void	set_game(t_game game_library, char **argv);
extern void	*xpm_texture(t_game game_library, char *file);
extern void	free_objects(t_game game);
extern void	set_walls_as_objects(t_game game_library);
extern void	set_coins_as_objects(t_game game_library);
extern void	free_textures(t_game game, int id);
extern void	set_map_textures(t_game game);
/* ********************* [V] ./SEt_game/LOAD_TEXTURES [V] ******************** */
extern void	load_textures(t_game game_library);
extern void	load_wall(t_game game_lib, int *z);
/* ********************* [^] ./SEt_game/LOAD_TEXTURES [^] ******************** */
/* *************************** [^] ./SEt_game [^] **************************** */

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
