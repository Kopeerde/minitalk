/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <kmendes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:19:19 by kmendes-          #+#    #+#             */
/*   Updated: 2022/05/09 15:14:43 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function takes 3 parameters, a void *, an integer and the size.
 * It will then set all the memory up to n to the integer parameter casted as a
 * char.
 * The changes are made on the original memory.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	res = s;
	while (i < n)
	{
		*res = (unsigned char) c;
		i++;
		res++;
	}
	return (s);
}
