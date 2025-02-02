/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:30:31 by afatimi           #+#    #+#             */
/*   Updated: 2023/03/14 17:44:30 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static void	*ft_fast_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long long	*word_src;
	unsigned long long	*word_dst;
	unsigned char		*byte_src;
	unsigned char		*byte_dst;
	size_t				i;

	word_src = (unsigned long long *)src;
	word_dst = (unsigned long long *)dst;
	i = n >> 3;
	while (i)
	{
		*word_dst++ = *word_src++;
		i--;
	}
	n -= i << 3;
	i = n & 7;
	byte_src = (unsigned char *)word_src;
	byte_dst = (unsigned char *)word_dst;
	while (i--)
		*byte_dst++ = *byte_src++;
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	if (!((size_t)dst & 7) && !((size_t)src & 7))
		return (ft_fast_memcpy(dst, src, n));
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

size_t	min(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*result;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		size = 0;
	else
		size -= start;
	size = min(size, len);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_memcpy(result, s + start, size);
	result[size] = 0;
	return (result);
}
