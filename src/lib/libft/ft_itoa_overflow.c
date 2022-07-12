/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_overflow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <kmendes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:07:16 by kmendes-          #+#    #+#             */
/*   Updated: 2022/06/13 14:10:00 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Function that takes a number and return how many digits and sign the number
 * 		have.
 * >>> nbr_elements(-2147483648)
 * 10
 * >>> nbr_elements(2748)
 * 4
*/
static int	nbr_elements(int n)
{
	int				i;
	unsigned int	temp;

	i = 0;
	temp = n;
	while (temp > 9)
	{
		i++;
		temp /= 10;
	}
	return (i);
}

/**
 * Function that takes an integer as argument en return the parsed input as
 * 		a string.
 * >>> ft_itoa(-2147483648)
 * "-2147483648"
 * >>> ft_itos(--2147483648)
 * ""
 * >>> ft_itoa(+4857)
 * "4857"
 * >>> ft_itoa(++59674138)
 * ""
*/
char	*ft_itoa_overf(int n)
{
	char			*res;
	int				i;
	unsigned int	buffer;

	i = nbr_elements(n);
	buffer = n;
	res = ft_calloc(i + 2, sizeof(char));
	if (!res)
		return (NULL);
	res[i] = '\0';
	while (buffer >= 10)
	{
		res[i] = (buffer % 10) + '0';
		buffer /= 10;
		i--;
	}
	res[i] = (buffer % 10) + '0';
	return (res);
}
