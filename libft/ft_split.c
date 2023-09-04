/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:36:20 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/16 11:59:20 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char c)
{
	int	str_cnt;
	int	flag;

	str_cnt = 0;
	flag = 1;
	while (*str)
	{
		if (flag == 1 && *str != c)
		{
			str_cnt++;
			flag = 0;
		}
		else if (*str == c)
			flag = 1;
		str++;
	}
	return (str_cnt);
}

static char	*str_word_print(char const *str, char c)
{
	char	*word;
	int		wc;
	int		i;

	wc = 0;
	i = 0;
	while (str[wc] && str[wc] != c)
		wc++;
	word = (char *)malloc(sizeof(char) * (wc + 1));
	if (!word)
		return (0);
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	free_split(char **arr, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		i;

	result = (char **)malloc(sizeof(char *) * (word_count(str, c) + 1));
	if (!result || !str)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str == '\0')
			break ;
		result[i] = str_word_print(str, c);
		if (result[i] == NULL)
		{
			free_split(result, i);
			return (NULL);
		}
		i++;
		while (*str && *str != c)
			str++;
	}
	result[i] = NULL;
	return (result);
}
