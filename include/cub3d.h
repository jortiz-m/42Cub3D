/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:06:37 by alba              #+#    #+#             */
/*   Updated: 2025/07/16 12:18:07 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3d_H
# define cub3d_H

/************
* LIBRARIES *
************/

#include "mlx.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/*********
* MACROS *
*********/

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080
# define TEXTURE_SIZE	64

/*********
* COLORS *
*********/

# define RD		"\033[1;91m"
# define PR		"\033[4;95m"
# define CI		"\033[0;96m"
# define GR		"\033[0;92m"
# define PI		"\033[0;94m"
# define FF		"\033[0;97m"
# define RES	"\033[0m"

/*************
* STRUCTURES *
*************/

// Color structure for RGB values
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

// MLX image data structure
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

// Texture structure
typedef struct s_texture
{
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
}	t_texture;

// Player structure
typedef struct s_player
{
	double	x;			// Player X position
	double	y;			// Player Y position
	double	dir_x;		// Direction vector X
	double	dir_y;		// Direction vector Y
	double	plane_x;	// Camera plane X
	double	plane_y;	// Camera plane Y
}	t_player;

// Map structure
typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_count;
}	t_map;

// Parsing data structure (temporary for file parsing)
typedef struct s_data
{
	int		file_rows;
	char	**map_data;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	t_color	floor;
	t_color	ceiling;
	int		map_rows;
	int		map_col;
}	t_data;

// Main game structure
typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_img		screen;
	t_texture	textures;
	t_player	player;
	t_map		map;
	t_data		data;
}	t_game;

/************
* FUNCTIONS *
************/

// Argument validation and file parsing
void	check_args(int argc, char **argv);
void	open_file(char *argv, t_data *data);
void	read_file(char *argv, t_data *data);
void	file2array(char *argv, t_data *data);

// Texture parsing functions
void	parse_no(char *no, t_data *data);
void	parse_so(char *so, t_data *data);
void	parse_we(char *we, t_data *data);
void	parse_ea(char *ea, t_data *data);

// Game initialization and cleanup
void	init_game(t_game *game);
void	init_player(t_game *game, char direction, int x, int y);
void	load_textures(t_game *game);
int		close_win(t_game *game);

// MLX utilities
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		get_texture_color(t_img *texture, int x, int y);

// Game loop and events
int		game_loop(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);

// Raycasting
void	raycast(t_game *game);
void	render_frame(t_game *game);

// Utils
void	error_exit(char *message);
void	free_game(t_game *game);
int		create_rgb(int r, int g, int b);


/******
* MEM *
******/

#endif