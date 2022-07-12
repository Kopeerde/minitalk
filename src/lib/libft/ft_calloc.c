/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <kmendes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:59:47 by kmendes-          #+#    #+#             */
/*   Updated: 2022/05/24 15:33:38 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function takes 2 parameters, the numbers of ele;ents, as a size_t type,
 * and the size of the elements (in bytes).
 * It then returns a pointer that allocate enough size ot fit all the elements
 * and initialize the whole memory with null bytes.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*heap_ptr;

	if (!nmemb || !size)
		return (malloc(0));
	if ((nmemb * size) / nmemb != size)
		return (NULL);
	heap_ptr = malloc(size * nmemb);
	if (!heap_ptr)
		return (NULL);
	ft_memset(heap_ptr, 0, nmemb * size);
	return (heap_ptr);
}
