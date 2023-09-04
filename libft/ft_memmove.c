/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:06:31 by hyungjup          #+#    #+#             */
/*   Updated: 2022/11/23 11:30:49 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	if (!dest && !src)
		return (NULL);
	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	i = -1;
	if (dest >= src)
	{
		while (++i < len)
			dest_tmp[len - i - 1] = src_tmp[len - i - 1];
	}
	else
	{
		while (++i < len)
			dest_tmp[i] = src_tmp[i];
	}
	return (dest);
}
