/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:31:36 by kmendes-          #+#    #+#             */
/*   Updated: 2022/07/07 11:31:44 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOST_H
# define HOST_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

# include "../lib/libft/libft.h"

# define TRUE 1

void	func(int sig);
void	signal_handler(int sig, char *res, char *c);
void	res_c_setter(char *res, char *c, char *temp);

char	bin_to_char(char *bin);

#endif //HOST_H
