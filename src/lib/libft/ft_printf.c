/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <kmendes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:01:04 by kmendes-          #+#    #+#             */
/*   Updated: 2022/06/13 15:41:51 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_flag(char c, char **res, va_list args)
{
	if (c == 'c')
		*res = ft_strjoin_char(*res, va_arg(args, int));
	else if (c == '%')
		*res = ft_strjoin_char(*res, '%');
	else if (c == 's')
		*res = ft_strjoin_string(*res, va_arg(args, char *));
	else if (c == 'p')
		*res = ft_strjoin_fb(*res, ft_parse_p(va_arg(args, unsigned long)));
	else if (c == 'd' || c == 'i')
		*res = ft_strjoin_fb(*res, ft_itoa(va_arg(args, int)));
	else if (c == 'u')
		*res = ft_strjoin_fb(*res, ft_itoa_overf(va_arg(args, unsigned int)));
	else if (c == 'x')
		*res = ft_strjoin_fb(*res, ft_convert_base(va_arg(args, int), 0));
	else if (c == 'X')
		*res = ft_strjoin_fb(*res, ft_convert_base(va_arg(args, int), 1));
	return ;
}

static void	if_flag(char **buffer, va_list args, const char **string, int *res)
{
	check_flag(*(++(*string)), buffer, args);
	if ((*buffer) == NULL)
		(*res)++;
	else
	{
		(*res) += ft_strlen((*buffer));
		ft_putstr_fd((*buffer), 1);
		free((*buffer));
	}
	(*buffer) = "";
}

int	ft_printf(const char *string, ...)
{
	char	*buffer;
	int		res;
	va_list	args;

	buffer = "";
	res = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
			if_flag(&buffer, args, &string, &res);
		else
		{
			write(1, &string[0], 1),
			res++;
		}
		string++;
	}
	va_end(args);
	return (res);
}
