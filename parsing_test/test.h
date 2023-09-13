#ifndef TEST_H
#define TEST_H

# define WALL '1'
# define EMPTY_SPACE '0'
# define UNDEFINED_MAP 'x'
//매크로에 문자넣는 방법 

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_element_cnt
{
	int	no_texture;
	int	so_texture;
	int	we_texture;
	int	ea_texture;
	int	floor;
	int	ceiling;
} t_element_cnt;

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

/*parsing*/
int		check_valid_map(t_map *map_info);
char	**parse_map(t_map *info_map);
char	**get_map(t_map *info_map, char *map_line, char **map);
void	check_extension(char *argv);
void	check_map_exist(t_map *info_map);
void	check_map_seperate(t_map *info_map);
void	get_map_size(t_map *map);
void	check_valid_component(t_map *info_map);
void	check_and_get_starting_position(t_map *info_map, char **map);
int		is_player(char c);
void	get_player_starting_position(t_map *info_map, int x, int y, char direc);
void	check_surrounded_by_wall(t_map *info_map);

/*srcs*/
int		is_all_white_space(char *str);
char	*ft_after_space(char *str);
char	*get_starting_line_of_map(int fd);
char	**init_ppc(int x, int y);
void	ft_error(char *str);
int		is_white_space(char c);
void	init_info_map(char *map_name, t_map *info_map);
void	free_direction(t_map *map);
void	f_c_free_and_error(t_map *map_info, char **rgb);
void	init_struct(t_map *info_map);

#endif
