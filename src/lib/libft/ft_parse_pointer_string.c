/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_pointer_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <kmendes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 09:49:35 by kmendes-          #+#    #+#             */
/*   Updated: 2022/06/13 14:08:46 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_elements(unsigned long n)
{
	int				i;
	unsigned long	temp;

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

static char	*ft_convert_base_parse(unsigned long number)
{
	char	*res;
	int		i;
	int		res_i;
	char	*base_lower;

	res = ft_calloc(20, sizeof(char));
	res_i = nbr_elements(number);
	base_lower = "0123456789abcdef";
	while (res_i > 0)
	{
		res_i--;
		i = number % 16;
		number /= 16;
		res[res_i] = base_lower[i];
	}
	return (res);
}

char	*ft_parse_p(unsigned long pointer)
{
	char	*res;

	if (pointer)
	{
		res = ft_calloc(15, sizeof(char));
		res[0] = '0';
		res[1] = 'x';
		res = ft_strjoin_fb(res, ft_convert_base_parse(pointer));
	}
	else
		res = ft_strjoin("", "(nil)");
	return (res);
}
