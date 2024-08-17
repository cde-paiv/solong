/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:38:02 by cde-paiv          #+#    #+#             */
/*   Updated: 2024/04/24 16:08:01 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*alloc;

	len = ft_strlen(s) + 1;
	alloc = (char *)malloc(len * sizeof(char));
	if (alloc == NULL)
		return (NULL);
	ft_memcpy(alloc, s, len);
	return (alloc);
}

/*int main(void)
{
	const char *original = "Hello, world!";
	char *copia = strdup(original);

	if (copia != NULL)
	{
		printf("String original: %s\n", original);
		printf("Cópia da string: %s\n", copia);
	}
	free(copia);
	return 0;
}*/
