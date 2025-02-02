/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:29:39 by afatimi           #+#    #+#             */
/*   Updated: 2023/03/14 17:44:34 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# include<unistd.h>
# include<stdlib.h>

size_t	ft_putchar(char c);
size_t	ft_putstr(char *s, void (*f)(void *));
int		ft_toupper(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	min(size_t a, size_t b);

#endif
