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

void func()
{
	ft_printf("test");
}

int	main()
{
	struct sigaction sa = { 0 };
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &func;
	ft_printf("pid : %i ", getpid());
	while (TRUE)
	{
		sigaction(SIGUSR1, &sa, NULL);
	}

	return (0);
}
