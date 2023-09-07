#include "../cub3D.h"

char	*get_starting_line_of_map(int fd)
{
	int		cnt;
	char	*map_line;

	cnt = 0;
	map_line = get_next_line(fd);
	while (map_line)
	{
		if (is_all_white_space(map_line) == 0)
		{
			if (cnt == 6)
				break ;
			else
				cnt++;
		}
		free(map_line);
		map_line = get_next_line(fd);
	}
	return (map_line);
}
//이부분은 위 구성요소가 완전하다는 가정하에 검사할 수 있다.

char	*ft_after_space(char *str)
{
	char	*end;

	while (*str && *str != ' ')
		str++;
	if (*str == ' ')
		str++;
	end = str;
	while (*end && *end != '\n')
		end++;
	*end = '\0';
	return (ft_strdup(str));
}//strncpy(ft_strlen(str) -1) 개행을 없애기 위해
