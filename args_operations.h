/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_operations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:23:48 by afatimi           #+#    #+#             */
/*   Updated: 2023/03/22 11:29:15 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_OPERATIONS_H
# define ARGS_OPERATIONS_H
# include<unistd.h>

void	split_args(const char *fmt, t_chunck **ds, va_list args);
void	free_args(t_chunck **ds);
int		print_args(t_chunck *ds);
int		validate_fmt(char *fmt);

#endif
