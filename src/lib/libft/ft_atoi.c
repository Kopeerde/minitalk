/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <kmendes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:53:49 by kmendes-          #+#    #+#             */
/*   Updated: 2022/05/11 17:12:27 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The function ft_atoi takes a string as parameter, parse it into an integer
 * and return the parsed value as an integer.
 * >>> ft_atoi(269 47852)
 * 269
 * >>> ft_atoi(-6954113)
 * -6954113
*/
int	ft_atoi(const char *nptr)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (9 <= nptr[i] && nptr[i] <= 13))
		i++;
	if (nptr[i] == 45)
		sign *= -1;
	if (nptr[i] == 45 || nptr[i] == 43)
		i++;
	while (48 <= nptr[i] && nptr[i] <= 57)
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return ((int) res * sign);
}
