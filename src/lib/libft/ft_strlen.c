/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <kmendes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:09:16 by kmendes-          #+#    #+#             */
/*   Updated: 2022/05/20 18:15:19 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function takes a string as parameter and return the number of characters
 * the string have.
 * >>> ft_strlen("Hello World")
 * 11
 * >>> ft_strlen("foo bar")
 * 6
 * >>> ft_strlen("")
 * 0
*/
size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}
