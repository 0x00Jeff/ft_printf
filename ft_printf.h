/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:15:40 by afatimi           #+#    #+#             */
/*   Updated: 2023/03/20 10:39:38 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# include<unistd.h>

size_t			ft_putchar(char c);
int				ft_toupper(int c);
size_t			ft_strlen(const char *s);
size_t			ft_putstr(char *s, void (*f)(void *));
char			*ft_itoa(long long nbr);
char			*ft_uitoa(unsigned long nbr);
char			*ft_itoa_wrapu(unsigned long nbr);
char			*ft_strdup(const char *s1);
unsigned int	ft_print_hex(unsigned long long number, int mode);
int				ft_printf(const char *fmt, ...);
# define FREE		0
# define DONT_FREE	1
# define PRINTF_H
#endif
