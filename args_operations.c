/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:38:55 by afatimi           #+#    #+#             */
/*   Updated: 2023/03/22 11:40:21 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"helpers.h"
#include"args_operations.h"
#include"libft.h"
#include"helpers.h"
#include"dispatcher.h"

void	split_args(const char *fmt, t_chunck **ds, va_list args)
{
	char		*ptr;
	size_t		len;
	long long	arg;
	char		*format;

	if (!fmt)
		return ;
	ptr = (char *)fmt;
	while (*ptr)
	{
		len = get_format_len(ptr);
		format = ft_substr(ptr, 0, len);
		arg = 0;
		if (validate_fmt(format))
		{
			if (get_format_char(format) == '%')
				arg = '%';
			else
				arg = va_arg(args, long long);
		}
		ft_lstadd_back(ds, ft_lstnew(format, arg));
		ptr += len;
	}
}

void	free_args(t_chunck **ds)
{
	ft_lstclear(ds);
}

int	print_args(t_chunck *ds)
{
	return (dispatcher(ds));
}
