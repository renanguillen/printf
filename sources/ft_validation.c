/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:53:44 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/26 21:38:35 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_validation(const char *format, int len, va_list arg)
{
	char	c;

	c = *format;
	if (c == '%' || c == 'c')
		len = ft_arg1(format, len, arg);
	else if (c == 's' || c == 'd' || c == 'i')
		len = ft_arg2(format, len, arg);
	else if (c == 'p')
		len = ft_arg3(format, len, arg);
	else if (c == 'u' || c == 'x' || c == 'X')
		len = ft_arg4(format, len, arg);
	else
		len = 0;
	return (len);
}