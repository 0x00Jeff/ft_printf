/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:12:51 by afatimi           #+#    #+#             */
/*   Updated: 2023/03/22 11:38:47 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"ft_printf.h"
#include"libft.h"

static int	ft_get_ten_pow(long long nbr)
{
	int			base;
	long long	devide;

	devide = 10;
	if (nbr < 0)
		devide = -10;
	base = 0;
	while (nbr != 0)
	{
		nbr = nbr / devide;
		base++;
		if (devide < 10)
			devide = devide * -1;
	}
	return (base - 1);
}

static long long	ft_ten_pow(int power, int sign)
{
	int			i;
	long long	result;

	i = 0;
	result = 1;
	if (!power && sign == 1)
		return (1);
	while (i < power)
	{
		result = result * 10;
		i++;
	}
	return (result * sign);
}

static void	ft_fill_buffer(long long n, int power, char *result)
{
	unsigned int	i;
	int				sign;

	i = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		result[i++] = '-';
	}
	while (power >= 0)
	{
		result[i++] = '0' + n / ft_ten_pow(power, sign);
		n %= ft_ten_pow(power, sign);
		power = power - 1;
	}
	result[i] = 0;
}

char	*ft_itoa(long long nbr)
{
	long long		n;
	char			*result;
	int				power;

	if (!nbr)
		return (ft_strdup("0"));
	n = (long long)nbr;
	power = ft_get_ten_pow(n);
	result = (char *)malloc(((power + 2 + (n < 0))) * sizeof(char));
	if (!result)
		return (NULL);
	ft_fill_buffer(n, power, result);
	return (result);
}

char	*ft_uitoa(unsigned long nbr)
{
	return (ft_itoa((unsigned long)nbr));
}
