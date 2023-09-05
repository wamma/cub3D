/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:26:40 by eoh               #+#    #+#             */
/*   Updated: 2023/09/05 10:50:34 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*gnl_strdup(char *src)
{
	char	*str;
	char	*c_src;
	int		l;
	int		i;

	l = 0;
	i = 0;
	c_src = src;
	while (c_src[l])
	{
		l++;
	}
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (str == 0)
		return (0);
	while (i < l)
	{
		str[i] = c_src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;
	size_t	i;

	i = 0;
	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!result)
		return (0);
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		result[i] = s2[i - s1_len];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*gnl_substr(char *s, int start, int end)
{
	char	*result;
	int		i;

	i = 0;
	if (s == 0)
		return (0);
	result = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!result)
	{
		return (0);
	}
	while (i < end - start + 1)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}