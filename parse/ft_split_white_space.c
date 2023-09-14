#include "../cub3D.h"

/*
static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (src[l])
	{
		l++;
	}
	while (i + 1 < size && i < l)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (l);
}
*/
/*
static int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
*/
static size_t	count_word(char const *s)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (is_white_space(s[i]) == 0 && \
		(is_white_space(s[i + 1]) == 1 || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

static char	**free_result(char **s)
{
	size_t	j;

	j = 0;
	while (s[j])
	{
		free((s[j]));
		j++;
	}
	free(s);
	return (0);
}

char	**ft_split_white_space(char const *s)
{
	size_t		i;
	char		**result;
	char const	*tmp;

	i = 0;
	result = (char **)malloc(sizeof(char *) * (count_word(s) + 1));
	if (!result)
		return (0);
	while (*s)
	{
		if (is_white_space(*s) == 0)
		{
			tmp = s;
			while (*s && is_white_space(*s) == 0)
				s++;
			result[i] = (char *)malloc(sizeof(char) * (s - tmp + 1));
			if (!result[i])
				return (free_result(result));
			ft_strlcpy(result[i++], tmp, s - tmp + 1);
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}