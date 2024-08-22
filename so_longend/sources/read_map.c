/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:34:44 by cde-paiv          #+#    #+#             */
/*   Updated: 2024/08/21 16:47:30 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_line(int fd)
{
	char	*holder;
	char	*holder_map;
	char	*line;

	holder_map = ft_strdup("");
	if (!holder_map)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = holder_map;
		holder_map = ft_strjoin(holder, line);
		free(holder);
		free(line);
		if (!holder_map)
			return (NULL);
	}
	return (holder_map);
}

static char	**convert_map(char *holder_map)
{
	char	**map;

	if (!holder_map)
		return (NULL);
	map = ft_split(holder_map, '\n');
	free(holder_map);
	if (!map)
		return (NULL);
	return (map);
}

char	**read_map(char *path)
{
	int		fd;
	char	*holder_map;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	holder_map = read_line(fd);
	if (!holder_map)
	{
		close(fd);
		return (NULL);
	}
	map = convert_map(holder_map);
	close(fd);
	return (map);
}
