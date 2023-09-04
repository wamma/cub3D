/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:26:07 by hyungjup          #+#    #+#             */
/*   Updated: 2023/09/04 21:25:11 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_map {
	int	l;
	int	w;
}	t_map;

void	ft_error(char *str);

#endif