#ifndef TEST_H
#define TEST_H

# define WALL '1'
# define EMPTY_SPACE '0'
# define UNDEFINED_MAP 'x'
//매크로에 문자넣는 방법 

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

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
	t_rgb	*floor;
	t_rgb	*ceiling;
	char	**map;
	char	*map_path;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		map_path_fd;
	int		width;
	int		height;
	int		starting_x;
	int		starting_y;
	int		starting_direction;
}	t_map;

//ft_error.c
void	ft_error(char *str);

//check_valid_path.c
int		rev_strncmp(char *s1, char *s2, int n);
void	check_valid_path(char *argv);

//get_texture_info.c
void	get_f_n_c_info(t_map *info_map, int type, char **info, int *cnt);
void	get_texture_path(t_map *info_map, int type, char **info, int *cnt);
void	get_path_n_color(t_map *info_map, int type, char **info, int *cnt);
void	get_texture_info(t_map *info_map);

//init.c
int		*init_array_zero(int size);
void	init_floor_and_ceiling_structure(t_map *info_map);
void	init_s_map(char *map_path, t_map *info_map);

//parsing_utils.c
void	check_valid_rgb(char **rgb);
void	check_valid_texture_info(int type, char **info);
int		get_element_type(char **info);

//split_white_space.c
char	**split_white_space(char const *s);

#endif
