/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <kmendes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:02:12 by kmendes-          #+#    #+#             */
/*   Updated: 2022/05/20 18:19:14 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function takes two parameters, a string and a char as an integer.
 * It will then return a pointer towrd the first time the character appear
 * in the string. If the character is not found, it will return a NULL pointer.
 * >>> ft_strchr("Hello World", 'o')
 * "o World"
 * >>> ft_strchr("Hello World", '\0')
 * ""
 * >>> ft_strchr("Hello World", 'k')
 * (NULL)
*/
char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = (char *)s;
	while (*res)
	{
		if (*res == (unsigned char) c)
			return (res);
		res++;
	}
	if (*res == (unsigned char) c)
		return (res);
	return (NULL);
}
