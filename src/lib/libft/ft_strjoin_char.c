/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:44:01 by kmendes-          #+#    #+#             */
/*   Updated: 2022/06/09 13:44:04 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function takes two strings as arguments and concatenate them into a
 * new variable while freeing s1 and keeping s2 untouched.
 */
char	*ft_strjoin_char(char *s1, char const s2)
{
	char	*res;
	size_t	len_s1;
	size_t	i;

	if (s2 == 0)
	{
		write(1, "\0", 1);
		return (NULL);
	}
	len_s1 = ft_strlen(s1);
	res = malloc(sizeof(char) * (len_s1 + 1) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	res[i] = s2;
	i++;
	if (*s1)
		free(s1);
	res[i] = 0;
	return (res);
}
