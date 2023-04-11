/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errormsg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkandiyi <rkandiyi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:46:42 by rkandiyi          #+#    #+#             */
/*   Updated: 2023/01/09 19:21:57 by rkandiyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// To print error message if input is in uppercase or any other letter

#include "ft_printf.h"

int	ft_errormsg(char s)
{
	if (s == 'S' || s == 'D' || s == 'I' || s == 'P' || s == 'U')
	{
		write (1, "(Input should be in lowercase)", 28);
		return (28);
	}
	else
	{
		write(1, "(Invalid input to print)", 22);
		return (22);
	}
}
