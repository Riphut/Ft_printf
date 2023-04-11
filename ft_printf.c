/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkandiyi <rkandiyi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:11:57 by rkandiyi          #+#    #+#             */
/*   Updated: 2023/01/09 19:21:36 by rkandiyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char s, va_list ap)
{
	int	sum;

	sum = 0;
	if (s == 'c')
		sum += ft_putchar(va_arg(ap, int));
	else if (s == '%')
		sum += ft_putchar('%');
	else if (s == 's')
		sum += ft_putstr(va_arg(ap, char *));
	else if (s == 'd' || s == 'i')
		sum += ft_putnbr(va_arg(ap, int));
	else if (s == 'u')
		sum += ft_putunbr(va_arg(ap, unsigned int));
	else if (s == 'x' || s == 'X')
		sum += ft_puthexa(s, (va_arg(ap, unsigned int)));
	else if (s == 'p')
	{
		sum += write(1, "0x", 2);
		sum += ft_puthexa('x', va_arg(ap, unsigned long));
	}
	else
		sum += ft_errormsg(s);
	return (sum);
}

int	ft_printf(const char *s, ...)
{
	int		sum;
	int		i;
	va_list	ap;

	i = 0;
	sum = 0;
	va_start(ap, s);
	while (s[i] != 0)
	{
		if (s[i] == '%')
			sum += ft_check(s[++i], ap);
		else
			sum += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (sum);
}
