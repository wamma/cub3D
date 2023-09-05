/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:26:07 by hyungjup          #+#    #+#             */
/*   Updated: 2023/09/05 16:27:41 by eoh              ###   ########.fr       */
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
	size_t	width;
	size_t	height;
}	t_map;


/*error.c*/
void	ft_error(char *str);

/*get_map.c*/

/*utils.c*/
int		is_all_white_space(char *str);
char	*get_starting_line_of_map(int fd);

/*get_path.c*/
int		rev_strncmp(char *s1, char *s2, int n);
char	*get_path(char *argv);

/*map_utils.c*/
char	*get_starting_line_of_map(int fd);

/*parse_map.c*/
char	**parse_map(t_map *info_map);
void	check_map_exist(t_map *info_map);
void	get_map_size(t_map *map);
void	check_valid_component(t_map *info_map);
char	**get_map(t_map *info_map);

/*init.c*/
char	**init_ppc(int x, int y);

#endif