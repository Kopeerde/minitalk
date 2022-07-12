/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmendes- <kmendes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 23:30:57 by kmendes-          #+#    #+#             */
/*   Updated: 2022/05/11 17:12:27 by kmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);

void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

size_t	ft_strlen(const char *string);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int		ft_atoi(const char *nptr);
int		ft_printf(const char *string, ...);

char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_char(char *s1, char const s2);
char	*ft_strjoin_fb(char *s1, char *s2);
char	*ft_itoa_overf(int n);
char	*ft_convert_base(unsigned int number, int base);
char	*ft_parse_p(unsigned long pointer);
char	*ft_strjoin_string(char *res, char	*arg);

#endif