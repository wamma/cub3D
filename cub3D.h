#ifndef CUB3D_H
# define CUB3D_H

# define WALL '1'
# define EMPTY_SPACE '0'
# define UNDEFINED_MAP 'x' 

# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

enum texture_path {
	SUM = 0,
	EA_PATH,
	WE_PATH,
	SO_PATH,
	NO_PATH,
	FLOOR,
	CEILING
};

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
	int		map_path_fd;
	int		width;
	int		height;
	int		starting_x;
	int		starting_y;
	int		starting_direction;
}	t_map;

/*srcs*/
void	ft_error(char *str);
void	free_ppc(char **ppc);
void	free_s_map(t_map *map);
char	**init_ppc(int column, int row);
int		*init_array_zero(int size);
void	init_floor_and_ceiling_structure(t_map *info_map);
void	init_s_map(t_map *info_map);

/*parse*/
char	**ft_split_white_space(char const *s);
void	check_map_component(t_map *info_map);
void	check_valid_map_component(char *line, t_map *info_map);
void	check_map_seperated(t_map *info_map, char *map_line);
void	check_valid_map_path(char *argv);
void	check_valid_texture_form(int type, char **info);
void	check_valid_rgb_form(char **rgb);
void	check_valid_texture_path(t_map *info_map);
void	check_valid_rgb_value(t_map *info_map);
char	**get_map(t_map *info_map, char *map_line);
void	get_map_size(t_map *info_map);
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
int		check_wall_row(char **map, int height);
int		is_all_wall_first_n_last_row(char *map_row);
int		check_is_valid_wall_row(char *map_row);

#endif