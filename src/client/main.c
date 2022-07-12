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

# include "client.h"

int	main(int argc, char **argv)
{
	int	pid_target;

	if (argc == 3)
	{
		pid_target = ft_atoi(argv[1]);
		printf("pid    : %i \nstring : %s", pid_target, argv[2]);
		kill(pid_target, SIGUSR1);
	}
	else
	{
		printf("Error follow that example :\n ./client <pid_host> <string>");
	}
	return (0);
}