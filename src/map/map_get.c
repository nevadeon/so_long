#include "so_long.h"

char	**_dim2join_free(char **tab, char *str)
{
	char		**output;
	uint32_t	len;

	len = dim2_len((void **) tab) + 1;
	output = malloc(sizeof(char *) * (len + 1));
	dim2_cpy((void **) output, (void **) tab);
	output[len - 1] = str;
	output[len] = NULL;
	free(tab);
	return (output);
}

char	**get_map(char *file_name)
{
	char	**map;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *));
	map[0] = NULL;
	line = get_next_line(fd);
	while (line)
	{
		line[ft_strclen(line, '\n', false)] = '\0';
		map = _dim2join_free(map, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
