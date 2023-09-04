/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:00:33 by hyungjup          #+#    #+#             */
/*   Updated: 2022/11/23 11:21:56 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*str;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	tmp = (unsigned char *)dest;
	str = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		tmp[i] = str[i];
		i++;
	}
	return (dest);
}
