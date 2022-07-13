/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:32:01 by kmendes-          #+#    #+#             */
/*   Updated: 2022/07/07 11:32:02 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HOST main.c

#include "host.h"

static int raise_power(int power)
{
	int	res;

	res = 1;
	while (power)
	{
		res *= 2;
		power--;
	}
	return (res);
}

static char bin_to_char(char *bin)
{
	int	res;
	int		i;

	res = 0;
	i = 0;
	while (i < 8)
	{
		if (bin[i] == '1')
			res += raise_power(7 - i);
		i++;
	}
	return ((char) res);
}

void	func(int sig)
{
	static char	*res;
	static char	*c;
	char 		temp;

	if (!c)
	{
		c = ft_calloc(9, sizeof(char));
		if (!c)
			return ;
	}
	if (!res)
	{
		res = ft_calloc(1000, sizeof(char));
		if (!res)
			return ;
	}
	if (sig == SIGINT)
	{
		ft_printf("On quitte gracieusement en liberant tout"); // TODO : remove line
		free(c);
		free(res);
		exit(0);
	}
	if (sig == SIGUSR1)
	{
		//ft_printf("1");
		ft_strlcat(c, "1", 9);
	}
	else if (sig == SIGUSR2)
	{
		//ft_printf("0");
		ft_strlcat(c, "0", 9);
	}
	if (ft_strlen(c) == 8)
	{
		temp = bin_to_char(c);
		if (temp == '\0')
		{
			//ft_printf("\nFin de chaine detectee\n"); // TODO : Remove line
			ft_printf("%s", res); // TODO : print la chaine
			ft_memset(res, '\0', ft_strlen(res));
		}
		else
		{
			//ft_printf("\n%s\n", &temp);
			ft_strlcat(res, &temp, 1000); // TODO : ajouter le charactere converti dans res
		}
		ft_memset(c, '\0', 9);
	}
}

int	main(void)
{
	struct sigaction	sa = {0};

	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &func;
	ft_printf("pid : %i\n", getpid());
	while (TRUE)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGINT, &sa, NULL);
	}
	return (0);
}
