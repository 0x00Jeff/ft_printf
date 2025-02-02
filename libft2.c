/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:16:03 by afatimi           #+#    #+#             */
/*   Updated: 2023/03/14 17:46:19 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<unistd.h>

size_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_putstr(char *s, void (*f)(void *))
{
	size_t	ret;

	if (!s)
		return (write(1, "(null)", 6));
	ret = write(1, s, ft_strlen(s));
	if (f)
		f(s);
	return (ret);
}

static int	ft_islower(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (ch >= 'a' && ch <= 'z')
		return (1);
	return (0);
}

int	ft_toupper(int c)
{
	unsigned char	ch;
	int				toggle;

	ch = (unsigned char)c;
	toggle = ft_islower(ch);
	return (c - 32 * toggle);
}
