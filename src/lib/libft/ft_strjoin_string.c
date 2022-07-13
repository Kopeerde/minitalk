/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <kmendes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:21:16 by kmendes-          #+#    #+#             */
/*   Updated: 2022/06/13 13:58:49 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_string(char *res, char	*arg)
{
	if (arg == NULL)
		res = ft_strjoin(res, "(null)");
	else
		res = ft_strjoin(res, arg);
	return (res);
}
