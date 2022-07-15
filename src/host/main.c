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

static int	raise_power(int power)
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

char	bin_to_char(char *bin)
{
	int	res;
	int	i;

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

void	func(int sig, siginfo_t *info, __attribute__((unused)) void *content)
{
	static char	*res;
	static char	*c;
	char		temp;
	int			pid_sender;

	pid_sender = info->si_pid;
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
	signal_handler(sig, res, c);
	res_c_setter(res, c, &temp);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = func;
	ft_printf("pid : %i\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
	while (TRUE)
	{
	}
	return (0);
}
