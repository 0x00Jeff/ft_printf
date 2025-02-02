/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:56:43 by afatimi           #+#    #+#             */
/*   Updated: 2023/03/22 11:43:58 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ds_operations.h"
#include"libft.h"
#include"helpers.h"
#include"print_hex.h"

int	handle_bonus_chars(t_chunck *chunck)
{
	char	*fmt;
	char	fmt_char;
	size_t	written;

	fmt = chunck -> fmt;
	written = 0;
	fmt_char = get_format_char(fmt);
	if (fmt_char == 'd' || fmt_char == 'i')
	{
		if (chunck -> content.nbr >= 0)
		{
			if (in_set(fmt, ' '))
				written = write(1, " ", 1);
			else if (in_set(fmt, '+'))
				written = write(1, "+", 1);
		}
	}
	else if (in_set(fmt, '#'))
	{
		if (fmt_char == 'x' && chunck -> content.hex)
			written = write(1, "0x", 2);
		else if (fmt_char == 'X' && chunck -> content.hex)
			written = write(1, "0X", 2);
	}
	return (written);
}

int	dispatcher2(t_chunck *chunck)
{
	int			res;
	char		c;

	res = 0;
	c = get_format_char(chunck -> fmt);
	if (c == 'c')
		res = ft_putchar(chunck -> content.c);
	else if (c == 'x' || c == 'X')
		res = ft_print_hex(chunck -> content.hex, (c == 'X') + 1);
	else if (c == 'p')
		res = ft_print_hex((long long)chunck -> content.address, 3);
	else if (c == 'u')
		res = ft_putstr(ft_uitoa(chunck -> content.u), free);
	else if (c == '%')
		res = ft_putchar(c);
	return (res);
}

int	dispatcher(t_chunck *chunck)
{
	t_chunck	*ptr;
	int			res;
	char		c;

	res = 0;
	ptr = chunck;
	while (ptr)
	{
		c = get_format_char(ptr -> fmt);
		if (ptr -> valide_fmt)
		{
			res += handle_bonus_chars(ptr);
			if (c == 's')
				res += ft_putstr(ptr -> content.str, NULL);
			else if (c == 'd' || c == 'i')
				res += ft_putstr(ft_itoa(ptr -> content.nbr), free);
			else
				res += dispatcher2(ptr);
		}
		else
			res += write(1, ptr -> fmt, ft_strlen(ptr -> fmt));
		ptr = ptr -> next;
	}
	return (res);
}
