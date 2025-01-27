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
# define SLICE 0.1
# define WINDOW_WIDTH 2500
# define WINDOW_HEIGHT 1800
# define WALL_SIZE 900 // WINDOW_HEIGHT / 2 (PX)
# define RAY_MULTIPY 16 // PERSPECTIVE * RAY_MULTIPY = number_of_rays
# define PERSPECTIVE 66.0 // Degree
# define ROTATE_SPEED 0.03
# define PLAYER_SPEED 1.5
# define CELL_SIZE 1.0F // ???
# define RENDER_DISTANCE 500.0F // LIMIT OF RENDER DISTANCE
# define SHADOW_DISTANCE 30.0F
# define RAY_JUMP_LIMIT 200 // RAY DISTANCE LIMIT
# define MAP_GRID_SIZE 50 // Map size, Example: 50 pixels per grid
# define SHADOW_ON 0 // SHOW SHADOW EFFECT OR NOT (1/0)
/* ********************* [^] CONSTANTS - GAME SETUP [^] ********************* */

/* ******************* [v] CONSTANTS - ERROR MESSAGES [v] ******************* */
# define ERROR4 "Allocaction error."
/* ******************* [^] CONSTANTS - ERROR MESSAGES [^] ******************* */

/* *********************** [V] CONSTANTS - INPUTS [V] *********************** */
# include <X11/keysym.h> /*
#  define XK_a
#  define XK_d
#  define XK_w
#  define XK_s
#  define XK_Left
#  define XK_Right
#  define XK_Up
#  define XK_Down
#  define XK_Escape
#         */
# define LETTER_KEY_LEFT XK_a // A
# define LETTER_KEY_RIGHT XK_d // D
# define LETTER_KEY_UP XK_w // W
# define LETTER_KEY_DOWN XK_s // S
# define ARROW_KEY_LEFT XK_Left // <-
# define ARROW_KEY_RIGHT XK_Right // ->
# define ARROW_KEY_UP XK_Up // ^
# define ARROW_KEY_DOWN XK_Down // V
# define KEY_ESC XK_Escape // ESC
# define SPACE_BAR XK_space // SPACE
/* *********************** [^] CONSTANTS - INPUTS [^] *********************** */

/* ***************************** [V] STRUCTS [V] **************************** */
typedef struct s_render // A struct only used at ./game/render.c
{
	float	half_wall_size; // The (size / 2) of wall
	int		shadow; // The shadow value of the ray, yeah there is shadow
	int		shadow_r; // 0XFF0000 shadow << 16
	int		shadow_g; // 0X00FF00 shadow << 8
	int		shadow_b; // 0X0000FF shadow itself
	int		texture_x; // The X coordinate of the texture (image)
	float	texture_y; // The X coordinate of the texture (image)
	float	texture_y_step; // Determine the Y index of image via that
	int		update_texture_y; // A variable for texture_y on X loop
	float	wall_height; // The height of the wall
	int		wall_y_start_point; // The start of the line coordinate
	float	wall_y_end_point; // The end of the line coordinate
	int		x; // Left to right rendering
	int		y; // Top to down rendering
	float	x_coordinates; // x + padding. 2 pixels or something
	int		index; // Ray index
	int		padding; // Spaces between rays
	int		hit; // The game->textures[hit] we gonna draw
}	t_render;

typedef struct s_lidar // A struct only used at ./game/cast_rays.c
{
	float	x; // x coordinate of the current ray
	float	y; // y coordinate of the current ray
	float	theta; // ray->theta + game->theta_rotation
	float	x_add; // The x jumper (-1 / 1)
	float	y_add; // The y jumper (-1 / 1)
	int		x_jump; // Total teleport number (jump_x += add_x)
	int		y_jump; // Total teleport number (jump_y += add_y)
	int		x_jump_on_map; // Kind of Jump's size (jump + game->x)
	int		y_jump_on_map; // Kind of Jump's size (jump + game->y)
	int		x_jump_on_map_pow2; // power ^2 (x_jump_on_map * x_jump_on_map)
	int		y_jump_on_map_pow2; // power ^2 (y_jump_on_map * y_jump_on_map)
	float	mod_game_x; // mod(game->x, 1.0) = 5.371 -> 0.371
	float	mod_game_y; // mod(game->y, 1.0) = 5.371 -> 0.371
	float	x_tan; // 1 / tan(ray_and_rotation_theta)
	float	y_tan; // tan(ray_and_rotation_theta)
	int		index; // Index of the ray we are throwing
	int		epsion; // To prevent the program to stuck in the inf loop
}	t_lidar;

typedef struct s_image
{
	void			*image; // Original image pointer. For MLX of course!
	char			*buffer; // Pixel matrix, please use it as an array
	int				bits_per_pixel; // How many bits a pixel uses
	int				line_length; // How many pixels a line has
	int				endian; // wtf is that
	unsigned int	x; // Max Image X size (pixel)
	unsigned int	y; // Max Image Y size (pixel)
}	t_image;

struct s_ray
{
	float	x; // Ray's Y coordinate on the map
	float	y; // Ray's X coordinate on the map
	float	distance; // Distance between ray and player
	float	theta; // The angle of ray we throwed
	float	sin_theta; // sin(90deg - ray.theta) for fixing fish eye effect
	char	hit; // The part of the wall ray hit (0=nan, 1=d, 2=r, 3=l 4=u)
}; // (5=door_d, 6=door_r, door_7=l 8=door_u)

struct s_key
{
	unsigned char	a : 1; // PRO-TIP: Bit fields :3
	unsigned char	d : 1;
	unsigned char	w : 1;
	unsigned char	s : 1;
	unsigned char	arrow_l : 1;
	unsigned char	arrow_r : 1;
	unsigned char	arrow_u : 1;
	unsigned char	arrow_d : 1;
	unsigned char	space;
};

typedef struct s_map // For map controls, nothing else
{
	char	*no; // Texture string
	char	*so; // Texture string
	char	*we; // Texture string
	char	*ea; // Texture string
	char	*door; // Door?
	char	*f; // Floor part (255,255,255\n)
	char	*c; // Ceiling part (255,255,255\n)
	char	**map; // Map itself (Matrix)
}	t_map;

typedef struct s_game
{
	/* [v]			MLX [v] */
	void			*mlx; // MiniLibX itself
	void			*window; // MiniLibX Window
	char			*window_title; // Window name
	int				window_height_center; // WINDOW_HEIGHT / 2
	char			**argv;
	int				argc;
	t_image			canvas; // The real paint
	t_image			textures[9]; // Textures, + door texture
	int				textures_are_ready; // To free textures if they are ready
	/* [v]			CHARACTER VALUES [v] */
	float			perspective; // The perspective
	float			x; // Player X coordinate on the map
	float			y; // Player Y coordinate on the map
	float			target_x; // For smooting lerp()
	float			target_y; // For smooting lerp()
	struct s_key	key; // Key input (They are actually bool, 1/0)
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
	float			target_shadow;
	float			shadow;
	struct s_ray	*ray; // Rays
	/* [v]			MAP [v] */
	char			**map; // Map lol
	int				map_width; // map[ ][*]
	int				map_height; // map[*][ ]
	int				floor_color;
	int				ceiling_color;
}	*t_game;
/* ***************************** [^] STRUCTS [^] **************************** */

/* ************************ [V] ./exit_functions [V] ************************ */
extern void	game_error(t_game game, char *message);
extern int	close_window(t_game game);
extern void	free_game(t_game game);
extern int	game_warning(const char *const message, const char *const prefix);
/* ************************ [^] ./exit_functions [^] ************************ */

/* **************************** [V] ./events [V] **************************** */
extern int	key_down(int key, t_game game);
extern int	key_up(int key, t_game game);
extern void	mouse_event(t_game game);
/* **************************** [^] ./events [^] **************************** */

/* **************************** [v] ./setup [v] ***************************** */
extern void	setup(t_game game);
extern void	create_image(t_game game, t_image *image, char *path);
extern void	collision(t_game game);
/* ***************************** [v] ./map [v] ****************************** */
extern int	check_map_data(t_game game, t_map *map);
extern int	check_map_header(t_game game, t_map *map);
extern int	check_map_header_color(const char *const line, \
const char *const prefix);
extern int	check_map_header_xpm(t_game game, const char *const line, \
const char *const prefix);
extern int	get_data_map(const char *const line, t_map *map);
extern int	get_map_header(char *line, t_map *map);
extern int	map_control(t_game game, const char *cub_file);
extern void	free_map(t_map *map);
extern void	set_map_to_game(t_game game, t_map map);
extern int	map_extension(const char *file);
/* ***************************** [^] ./map [^] ****************************** */
/* **************************** [^] ./setup [^] ***************************** */

/* **************************** [v] ./render [v] **************************** */
extern void	render(t_game game);
extern void	putpixel(t_game game, register int x, register int y, \
register int color);
extern void	skybox(t_game game, register int ground, register int floor);
extern void	input_events(t_game game);
/* ***************************** [v] ./lidar [v] **************************** */
extern void	lidar(t_game game);
extern int	calculate_distance_x(t_game game, t_lidar lidar, int hit);
extern int	calculate_distance_y(t_game game, t_lidar lidar, int hit);
extern int	check_between_0_90(t_game game, t_lidar *lidar);
extern int	check_between_90_180(t_game game, t_lidar *lidar);
extern int	check_between_180_240(t_game game, t_lidar *lidar);
extern int	check_between_240_360(t_game game, t_lidar *lidar);
/* ***************************** [^] ./lidar [^] **************************** */
/* **************************** [^] ./render [^] **************************** */

/* *************************** [v] ./minimap [v] **************************** */
extern void	minimap(t_game game, register int x, register int y);
/* *************************** [^] ./minimap [^] **************************** */

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
