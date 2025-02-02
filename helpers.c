/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:21:09 by afatimi           #+#    #+#             */
/*   Updated: 2023/03/22 12:02:26 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"ds_operations.h"
#include"dispatcher.h"
#include"helpers.h"

int	in_set(char *set, char c)
{
	char	*ptr;

	ptr = set;
	while (*ptr)
	{
		if (*ptr == c)
			return (1);
		ptr++;
	}
	return (0);
}

unsigned int	get_format_len(char *ptr)
{
	unsigned len = 0;
	if (*ptr != '%')
	{
		while (ptr[len] && ptr[len] != '%')
			len++;
	}
	else
	{
		len++;
		if (in_set("cspdiuxX%", ptr[len]))
			len++;
		else
		{
			len = 1;
			while (ptr[len] && !in_set("cspdiuxX%", ptr[len]))
				len++;
		}
	}
	return (len);
}

int	has_duplicates(char *ptr)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(ptr) - 1;
	while (i < len)
	{
		if (in_set(&ptr[i + 1], ptr[i]))
			return (1);
		i++;
	}
	return (0);
}

int	validate_fmt(char *fmt)
{
	size_t	fmt_len;
	size_t	i;

	fmt_len = ft_strlen(fmt);
	i = 0;
	if (*fmt != '%')
		return (0);
	while (i < fmt_len)
		if (!in_set("cspdiuxX%", fmt[i++]))
			return (0);
	if (has_duplicates(++fmt))
		return (0);
	return (1);
}

char	get_format_char(char *fmt)
{
	size_t	fmt_len;
	char	fmt_char;

	fmt_len = ft_strlen(fmt);
	fmt_char = fmt[fmt_len - 1];
	return (fmt_char);
}
