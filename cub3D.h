/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:12:00 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 17:28:02 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WALL				'1'
# define EMPTY_SPACE		'0'
# define UNDEFINED_MAP		'x' 
# define WIN_WIDTH			1000
# define WIN_HEIGHT			800
# define TEX_WIDTH			64
# define TEX_HEIGHT			64
# define TEXTURE_NUMBER		4

# define FALSE				0
# define TRUE				1

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_ESC			53
# define KEY_LEFT			123
# define KEY_RIGHT			124

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

# define SUM				0
# define EA_PATH			1
# define WE_PATH			2
# define SO_PATH			3
# define NO_PATH			4
# define FLOOR				5
# define CEILING			6

# define EAST				0
# define WEST				1
# define SOUTH				2
# define NORTH				3

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_map
{
	char	**map;
	char	*map_path;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	t_rgb	*floor;
	t_rgb	*ceiling;
	int		floor_int_rgb;
	int		ceiling_int_rgb;
	int		map_path_fd;
	int		width;
	int		height;
	double	starting_x;
	double	starting_y;
	int		starting_direction;
}	t_map;

typedef struct s_image
{
	void	*img_ptr;
	int		*data_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		color;
}	t_image;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	t_image		*win_img;
	t_image		*img_texture;
	t_vec		dir;
	t_vec		plane;
	t_vec		pos;
	double		move_speed;
	double		rot_speed;
	char		**map;
	t_map		*info_map;
}	t_cub;

typedef struct s_calc
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		hit;
	int		step_x;
	int		step_y;
	int		side;
	int		color;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}	t_calc;

/*srcs*/
void	ft_error(char *str);
void	free_ppc(char **ppc);
void	free_s_map(t_map *map);
int		*init_array_zero(int size);
void	init_floor_and_ceiling_structure(t_map *info_map);
void	init_s_map(t_map *info_map);
void	init_mlx(t_cub *cub);
void	init_s_cub(t_cub *cub, t_map *info_map);
t_calc	*init_s_calc(void);
int		key_press(int key_code, t_cub *cub);
void	load_image(t_cub *cub);
int		main_loop(t_cub *cub);
t_calc	*calculate(t_cub *cub);
void	get_calc_info(t_calc *calc, t_cub *cub, int x);
void	get_wall_tex_num(t_calc *calc);
void	get_side_dist(t_calc *calc, t_cub *cub);
void	get_side(t_calc *calc, t_cub *cub);
void	get_perp_wall_dist(t_calc *calc, t_cub *cub);
void	get_draw_start_and_end(t_calc *calc);
void	draw_floor_ceiling(t_calc *calc, t_cub *cub, t_image *win_img, int x);
void	draw_wall(t_calc *calc, t_cub *cub, int x, t_image *win_img);
void	get_step_and_tex_pos(t_calc *calc, t_cub *cub);
void	get_wall_x_tex_x(t_calc *calc, t_cub *cub);
void	my_mlx_pixel_put(t_image *win_img, int x, int y, int color);

/*parse*/
char	**ft_split_white_space(char const *s);
void	check_map_component(t_map *info_map);
void	check_valid_map_component(char *line, t_map *info_map);
void	check_map_seperated(t_map *info_map, char *map_line);
void	check_duplicated_map_path(t_map *info_map);
void	check_valid_map_path(char *argv);
void	check_valid_texture_form(int type, char **info);
void	check_valid_rgb_element(char *rgb);
void	check_numbers_of_rgb(char **rgb);
void	check_valid_texture_path(t_map *info_map);
void	check_valid_rgb_value(t_map *info_map);
void	get_map_size(t_map *info_map);
char	**get_map(t_map *info_map, char *map_line);
void	get_texture_info(t_map *info_map);
int		get_element_type(char **info);
void	get_path_n_color(t_map *info_map, int type, char **info, int *cnt);
void	get_texture_path(t_map *info_map, int type, char **info, int *cnt);
void	get_f_n_c_info(t_map *info_map, int type, char **info, int *cnt);
void	parse_info_map(t_map *info_map, char *map_path);
char	**parse_map(t_map *info_map);
int		rev_strncmp(char *s1, char *s2, int n);
int		is_same(char *s1, char *s2);
int		is_all_white_space(char *str);
int		is_white_space(char c);
void	read_remain_of_map(int fd, char *line);
char	*get_starting_line_of_map(t_map *info_map);
int		is_player(char c);
void	check_and_get_starting_position(t_map *info_map, char **map);
char	**allocate_two_dimension_array(int column, int row);
int		check_surrounded_by_wall(char **map, t_map *info_map);
void	ft_error_free_map(char *str, t_map *info_map);
void	free_two_dimension_array(char **arr);

#endif