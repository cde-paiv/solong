/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:19:25 by cde-paiv          #+#    #+#             */
/*   Updated: 2024/08/17 18:50:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

size_t	ft_strlen(char const *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);

#endif
