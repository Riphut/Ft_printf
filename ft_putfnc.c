/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfnc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkandiyi <rkandiyi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:31:45 by rkandiyi          #+#    #+#             */
/*   Updated: 2023/01/09 19:20:38 by rkandiyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char	c;
	int		sum;

	sum = 0;
	if (n == -2147483648)
	{
		sum += ft_putnbr(n / 10);
		sum += ft_putchar('8');
	}
	else if (n < 0)
	{
		sum += ft_putchar('-');
		sum += ft_putnbr(n / (-1));
	}
	else
	{
		if (n >= 10)
			sum += ft_putnbr(n / 10);
		c = n % 10 + '0';
		sum += ft_putchar(c);
	}
	return (sum);
}

int	ft_putunbr(unsigned int n)
{
	char	c;
	int		sum;

	sum = 0;
	if (n == 0)
	{
		sum += ft_putchar('0');
		return (sum);
	}
	else if (n >= 10)
		sum += ft_putunbr(n / 10);
	c = n % 10 + '0';
	sum += ft_putchar(c);
	return (sum);
}

int	ft_puthexa(char s, unsigned long n)
{
	char	*a;	
	int		sum;

	sum = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (s == 'x')
		a = "0123456789abcdef";
	else if (s == 'X')
		a = "0123456789ABCDEF";
	if (n > 15)
	{
		sum += ft_puthexa(s, (n / 16));
		sum += ft_puthexa(s, (n % 16));
	}
	else
		sum += ft_putchar(a[n]);
	return (sum);
}
