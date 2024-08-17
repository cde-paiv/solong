/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:49:37 by cde-paiv          #+#    #+#             */
/*   Updated: 2024/06/20 18:14:21 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_lines(int fd, char *str);
char	*ft_current_line(char *str, char *line);
char	*ft_get_rest(char *str);

char	*get_next_line(int fd)
{
	static char	*next_lines;
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_lines = ft_get_lines(fd, next_lines);
	if (next_lines == NULL)
		return (NULL);
	current_line = NULL;
	current_line = ft_current_line(next_lines, current_line);
	next_lines = ft_get_rest(next_lines);
	return (current_line);
}

char	*ft_get_lines(int fd, char *str)
{
	char	*temp;
	int		len_temp;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	len_temp = 1;
	while (ft_strchr(str, '\n') == NULL && len_temp != 0)
	{
		len_temp = read(fd, temp, BUFFER_SIZE);
		if (len_temp < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[len_temp] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

char	*ft_current_line(char *str, char *line)
{
	int	count;

	count = 0;
	if (str[count] == '\0')
		return (NULL);
	while (str[count] != '\n' && str[count] != '\0')
		count++;
	if (str[count] == '\n')
		line = malloc((count + 2) * sizeof(char));
	else if (str[count] == '\0')
		line = malloc((count + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	count = -1;
	while (str[++count] != '\n' && str[count] != '\0')
		line[count] = str[count];
	if (str[count] == '\n')
		line[count++] = '\n';
	line[count] = '\0';
	return (line);
}

char	*ft_get_rest(char *str)
{
	size_t	count;
	size_t	str_len;
	size_t	res_count;
	char	*rest;

	count = 0;
	while (str[count] != '\n' && str[count] != '\0')
		count++;
	if (str[count] == '\0')
	{
		free(str);
		return (NULL);
	}
	str_len = ft_strlen(str);
	rest = malloc((str_len - count) * sizeof(char));
	if (rest == NULL)
		return (NULL);
	count++;
	res_count = 0;
	while (str[count] != '\0')
		rest[res_count++] = str[count++];
	rest[res_count] = '\0';
	free(str);
	return (rest);
}
