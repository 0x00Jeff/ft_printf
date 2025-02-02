/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:13:35 by afatimi           #+#    #+#             */
/*   Updated: 2023/03/22 11:34:11 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include"ds_operations.h"
#include"libft.h"
//#include"split_args.h"
//#include"print_args.h"
#include"args_operations.h"
#include<limits.h>

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	t_chunck	*ds;
	int			res;

	ds = NULL;
	va_start(args, fmt);
	split_args(fmt, &ds, args);
	res = print_args(ds);
	free_args(&ds);
	va_end(args);
	return (res);
}
