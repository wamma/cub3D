/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:26:57 by hyungjup          #+#    #+#             */
/*   Updated: 2023/10/25 15:42:52 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_valid_map_path(char *argv)
{
	int	fd;

	if (rev_strncmp(argv, "buc.", 4) == -1)
		ft_error("Check: invalid map extension\n");
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error("Check: invalid map path\n");
	close(fd);
}

void	check_valid_texture_form(int type, char **info)
{
	int	i;

	i = 0;
	if (type == -1)
		ft_error("Check : invalidate file form\n");
	if (type >= EA_PATH && type <= CEILING)
	{
		while (info[i] != NULL)
		{
			i++;
		}
		if (i != 2)
			ft_error("Check : invalidate file form\n");
	}
}

void	check_valid_rgb_element(char *rgb)
{
	int	i;
	int	flag_comma;

	i = 0;
	flag_comma = 0;
	while (rgb[i] != '\0')
	{
		if (ft_isdigit(rgb[i]) == 0 && rgb[i] != ',')
			ft_error("Check: invalid rgb element\n");
		if (rgb[i] == ',')
		{
			if (flag_comma == 1)
				ft_error("Check: invalid rgb form\n");
			flag_comma = 1;
		}
		if (flag_comma == 1 && ft_isdigit(rgb[i]) == 1)
			flag_comma = 0;
		i++;
	}
	if (flag_comma == 1)
		ft_error("Check: invalid rgb form\n");
}

void	check_numbers_of_rgb(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i] != NULL)
	{
		i++;
	}
	if (i != 3)
		ft_error("Check : numbers of rgb\n");
}

void	free_two_dimension_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}