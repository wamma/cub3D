#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 42

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

char	*free_save(char *save)
{
	free(save);
	return (0);
}

char	*update_save(char *save, char *result)
{
	char	*new_save;
	int		n_index;

	if (result == NULL)
	{
		free(save);
		return (0);
	}
	if (save[0] == '\0')
	{
		free(save);
		return (0);
	}
	n_index = gnl_strchr(save, '\n');
	if (n_index == -1)
	{
		free(save);
		new_save = 0;
	}
	else
	{
		new_save = gnl_substr(save, n_index + 1, gnl_strlen(save) - 1);
		free(save);
	}
	return (new_save);
}

char	*get_result(char *save)
{
	int		n_index;
	char	*result;

	if (save[0] == '\0')
		return (0);
	n_index = gnl_strchr(save, '\n');
	if (n_index == -1)
		result = gnl_strdup(save);
	else
		result = gnl_substr(save, 0, n_index);
	return (result);
}

char	*read_line(int fd, char *buf, char *save)
{
	char	*old_save;
	int		read_res;

	while (1)
	{
		read_res = read(fd, buf, BUFFER_SIZE);
		if (read_res < 0)
		{
			free(save);
			return (0);
		}
		if (read_res == 0)
			return (save);
		buf[read_res] = '\0';
		old_save = save;
		save = gnl_strjoin(save, buf);
		free(old_save);
		if (save == NULL)
			return (0);
		if (save[0] == '\0')
			return (free_save(save));
		if (gnl_strchr(save, '\n') != -1 || read_res < BUFFER_SIZE)
			return (save);
	}
}
char	*get_next_line(int fd)
{
	char		*buf;
	char		*result;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (save == 0)
		save = gnl_strdup("");
	if (save == NULL)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
	{
		if (save != NULL)
			free(save);
		save = NULL;
		return (NULL);
	}
	save = read_line(fd, buf, save);
	free(buf);
	if (save == NULL)
		return (NULL);
	result = get_result(save);
	save = update_save(save, result);
	return (result);
}

int main()
{
	char *str;
	int		fd;

	fd = open("valid_map.cub", O_RDONLY);;
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	fd = open("valid_map.cub", O_RDONLY);
	str = get_next_line(fd);
	printf("new : %s\n", str);
	return (0);
}