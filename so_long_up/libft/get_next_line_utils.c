/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:49:27 by cde-paiv          #+#    #+#             */
/*   Updated: 2024/06/19 19:52:40 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		count;

	if (s == NULL)
		return (NULL);
	count = -1;
	while (s[++count] != '\0')
		if (s[count] == (char)c)
			return (&s[count]);
	if ((char)c == '\0')
		return (&s[count]);
	return (NULL);
}

char	*ft_strjoin(char *next_line, char *temp)
{
	char	*dest;
	size_t	next_line_len;
	size_t	temp_len;
	int		count;

	if (next_line == NULL)
	{
		next_line = malloc(1 * sizeof(char));
		next_line[0] = '\0';
	}
	next_line_len = ft_strlen(next_line);
	temp_len = ft_strlen(temp);
	dest = malloc((next_line_len + temp_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	count = -1;
	while (next_line[++count] != '\0')
		dest[count] = next_line[count];
	count = -1;
	while (temp[++count] != '\0')
		dest[count + next_line_len] = temp[count];
	dest[count + next_line_len] = '\0';
	free(next_line);
	return (dest);
}
