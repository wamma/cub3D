/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:26:07 by hyungjup          #+#    #+#             */
/*   Updated: 2023/09/05 21:48:29 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WALL '1'
# define EMPTY_SPACE '0'
# define UNDEFINED_MAP 'z'
//매크로에 문자넣는 방법 

# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_map {
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
}	t_map;

/*parsing*/
void	check_valid_map(t_map *map_info);
char	**parse_map(t_map *info_map);
char	**get_map(t_map *info_map);
void	check_extension(char *argv);
void	check_map_exist(t_map *info_map);
void	get_map_size(t_map *map);
void	check_valid_component(t_map *info_map);

/*srcs*/
int		is_all_white_space(char *str);
char	*ft_after_space(char *str);
char	*get_starting_line_of_map(int fd);
char	**init_ppc(int x, int y);
void	ft_error(char *str);
int		is_white_space(char c);
int		only_space_and_new_line(char *line);
void	init_info_map(char *map_name, t_map *info_map);
void	free_direction(t_map *map);

#endif