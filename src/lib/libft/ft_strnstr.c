/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <kmendes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:50:17 by kmendes-          #+#    #+#             */
/*   Updated: 2022/05/17 12:30:42 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function takes 3 arguments, a haystack (char *), a needle (char *) and a
 * size.
 * It then search if it find the needle in the haystack. The whole needle needs
 * to be in the haystack in the maximum size imposed, if the needle starts under
 * the limits of the size and ends outside, it's considered not in the haystack.
 * The return value is a pointer to the first character in the haystack that
 * correspond to the first character of the needle. If the needle is not found
 * in that size limit, the returned value is NULL.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len && little[j])
			j++;
		if (little[j] == '\0')
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
