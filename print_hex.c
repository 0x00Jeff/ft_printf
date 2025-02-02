/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:49:58 by afatimi           #+#    #+#             */
/*   Updated: 2023/03/21 20:05:01 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"ft_printf.h"

static void	ft_byte_hex(char *buff, int c)
{
	char			*hex_lookup;
	int				first;
	int				second;

	hex_lookup = "0123456789abcdef";
	first = (c & 0xf0) >> 4;
	second = c & 0x0f;
	buff[0] = hex_lookup[first];
	buff[1] = hex_lookup[second];
}

static char	*ft_full_hex(unsigned long long value)
{
	unsigned long long	mask;
	unsigned int		pair;
	char				*h_buff;

	h_buff = (char *)calloc(17, sizeof(char));
	if (!h_buff)
		return (NULL);
	mask = 0xff00000000000000;
	pair = 7;
	while (mask)
	{
		ft_byte_hex(h_buff + ((7 - pair) << 1), (mask & value) >> (pair << 3));
		mask >>= 8;
		pair--;
	}
	return (h_buff);
}

unsigned int	ft_print_hex(unsigned long long number, int mode)
{
	unsigned int	written;
	char			*hex;
	char			*tmp;

	written = 0;
	hex = ft_full_hex(number);
	if (!hex)
		return (0);
	tmp = hex;
	while (*hex == '0')
		hex++;
	if (!*hex)
		hex = "0";
	if (mode == 1)
		written = ft_putstr(hex, NULL);
	else if (mode == 2)
	{
		while (*hex)
			written += ft_putchar(ft_toupper(*hex++));
	}
	else if (mode == 3)
		written = ft_putstr("0x", NULL) + ft_putstr(hex, NULL);
	free(tmp);
	return (written);
}
