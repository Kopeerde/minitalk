/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_both.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <kmendes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:20:14 by kmendes-          #+#    #+#             */
/*   Updated: 2022/06/13 14:07:36 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function takes two strings as arguments and concatenate them into a
 * new variable while freeing s1 and keeping s2 untouched.
 */
char	*ft_strjoin_fb(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;
	size_t	len_s2;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j] && (unsigned long)(i + j) < len_s1 + len_s2)
		res[i + j] = s2[j];
	if (*s1)
		free(s1);
	if (*s2)
		free(s2);
	res[i + j] = 0;
	return (res);
}
