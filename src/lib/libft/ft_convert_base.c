/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <kmendes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:29:17 by kopeerde          #+#    #+#             */
/*   Updated: 2022/06/13 13:55:13 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_elements(unsigned int n)
{
	int				i;
	unsigned int	temp;

	if (n <= 15)
		return (1);
	i = 0;
	temp = n;
	while (temp > 0)
	{
		i++;
		temp /= 16;
	}
	return (i);
}

char	*ft_convert_base(unsigned int number, int casse)
{
	char	*res;
	int		i;
	int		res_i;
	char	*base_lower;
	char	*base_upper;

	res = ft_calloc(10, sizeof(char));
	res_i = nbr_elements(number);
	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	while (res_i > 0)
	{
		res_i--;
		i = number % 16;
		number /= 16;
		if (!casse)
			res[res_i] = base_lower[i];
		else
			res[res_i] = base_upper[i];
	}
	return (res);
}
