/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:39:25 by cde-paiv          #+#    #+#             */
/*   Updated: 2024/05/02 17:17:08 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ctword(const char *s, char c)
{
	unsigned int	count;

	count = 0;
	if (!s)
		return (0);
	if (!c)
		return (*s != '\0');
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*saveword(const char *s, char c)
{
	char	*str;
	int		n;
	int		i;

	i = 0;
	n = 0;
	while (s[n] && s[n] != c)
		n++;
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[n] = '\0';
	return (str);
}

static void	*free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;

	i = 0;
	array = (char **)malloc(sizeof(char *) * (ctword(s, c) + 1));
	if (!array || !s)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			array[i] = saveword(s, c);
			if (array[i] == NULL)
			{
				return (free_array(array));
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	array[i] = NULL;
	return (array);
}

/*int	main(void)
{
	char const *str = "hello      world";
	char **result;
	int i = 0;
	char delimiter = ' ';

	result = ft_split(str, delimiter);
	if (result == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	while (result[i] != NULL)
	{
		printf("result[%d]: %s\n", i, result[i]);
		i++;
	}
	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return 0;
}*/
