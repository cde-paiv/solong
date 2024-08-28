/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:18:43 by cde-paiv          #+#    #+#             */
/*   Updated: 2024/04/24 09:59:22 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*int	main(void)
{
	char	str[100];

	printf("digite uma string: ");
	scanf("%s", str);

	size_t  len;
	len = ft_strlen(str);
	printf("o comprimento da string e: %zu\n", len);
	return (0);
}*/
