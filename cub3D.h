/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:26:07 by hyungjup          #+#    #+#             */
/*   Updated: 2023/09/05 17:19:44 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WALL 1
# define EMPTY_SPACE 0
# define UNDEFINED_MAP 2

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
	int		fd;
	int		width;
	int		height;
}	t_map;

/*parsing*/
void	save_direction_file(char *map_name, t_map *info_map);
char	*get_path(char *argv);
void	check_valid_map(t_map *map_info);
char	**parse_map(t_map *info_map);
char	**get_map(t_map *info_map);

/*srcs*/
int		is_all_white_space(char *str);
char	*get_starting_line_of_map(int fd);
char	**init_ppc(int x, int y);
void	ft_error(char *str);

#endif