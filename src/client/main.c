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

#include "client.h"

static char	*str_to_bin(char *s)
{
	char		*res;
	char		c;
	size_t		i;
	size_t		len;
	int			j;

	if (s == NULL) // Cas ou la chaine est nulle
		return (0);
	len = ft_strlen(s);
	res = ft_calloc(len * 8 + 1, sizeof(char));
	if (!res) // check du malloc
		return (0);
	i = 0;
	while (i < len) // conversion des chars en bits
	{
		c = s[i]; // stocke le charactere
		j = 7;
		while (j >= 0) // check chaque bits du charactere
		{
			if (c & (1 << j)) // si le char existe (en bit) et que le bit vaut 1
				ft_strlcat(res, "1", len * 8 + 1);
			else
				ft_strlcat(res, "0", len * 8 + 1);
			j--;
		}
		i++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int		pid_target;
	size_t	i;
	char	*str_bin;

	if (argc == 3)
	{
		pid_target = ft_atoi(argv[1]);
		if (kill(pid_target, 0) == 0)
		{
			str_bin = str_to_bin(argv[2]);
			printf("pid    : %i \nstring : %s\nconversion : %s\n", pid_target, argv[2], str_bin);
			i = 0;
			while (str_bin[i])
			{
				if (str_bin[i] == '1')
					kill(pid_target, SIGUSR1);
				else
					kill(pid_target, SIGUSR2);
				i++;
				usleep(500000);
			}
			i = -1;
			while (++i < 8) // Permet de renvoyer le char null pour signaler fin de chaine
			{
				kill(pid_target, SIGUSR2);
				usleep(600000);
			}

			free(str_bin);
		}
		else
			ft_printf("Mauvais pid");
	}
	else
		ft_printf("Err: follow that example :\n ./client <pid_host> <string>");
	return (0);
}
