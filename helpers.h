/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:37:05 by afatimi           #+#    #+#             */
/*   Updated: 2023/03/22 11:40:25 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H
# include "ds_operations.h"

unsigned int	get_format_len(char *ptr);
char			get_format_char(char *fmt);
void			split_args(const char *fmt, t_chunck **ds, va_list args);
char			*ft_itoa(long long nbr);
char			*ft_uitoa(unsigned int nbr);
int				in_set(char *set, char c);
int				validate_fmt(char *fmt);
#endif
