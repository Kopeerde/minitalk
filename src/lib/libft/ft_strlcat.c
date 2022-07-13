/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:37:15 by kmendes-          #+#    #+#             */
/*   Updated: 2022/07/12 16:37:17 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	start;
	size_t	i;
	size_t	len_src;
	size_t	len_dst;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	start = len_dst;
	if (!size)
		return (len_src);
	if (size < len_dst)
		return (len_src + size);
	while (src[i] && (len_dst + i) < size && i == 0)
	{
		dst[start] = src[i];
		start++;
		i++;
	}
	if ((len_dst + i) == size && len_dst < size)
		dst[--start] = '\0';
	else
		dst[start] = '\0';
	return (len_src + len_dst);
}
