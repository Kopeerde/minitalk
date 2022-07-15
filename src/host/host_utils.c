/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host_ustils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:49:12 by kmendes-          #+#    #+#             */
/*   Updated: 2022/07/13 16:49:13 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "host.h"

void	signal_handler(int sig, char *res, char *c)
{
	if (sig == SIGINT)
	{
		ft_printf("On quitte gracieusement en liberant tout");
		free(c);
		free(res);
		exit(0);
	}
	if (sig == SIGUSR1)
		ft_strlcat(c, "1", 9);
	else if (sig == SIGUSR2)
		ft_strlcat(c, "0", 9);
}

void	res_c_setter(char *res, char *c, char *temp)
{
	if (ft_strlen(c) == 8)
	{
		(*temp) = bin_to_char(c);
		if ((*temp) == '\0')
		{
			ft_printf("%s", res);
			ft_memset(res, '\0', ft_strlen(res));
		}
		else
			ft_strlcat(res, temp, 1000);
		ft_memset(c, '\0', 9);
	}
}
