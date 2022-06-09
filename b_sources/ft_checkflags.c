/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:27:41 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/06 20:21:28 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_b.h"

void	ft_checkflags(const char **format, t_flags *flag)
{
	while ((**format == '-') || (**format == '+') || (**format == ' ')
		|| (**format == '#') || (**format == '0'))
	{
		if (**format == '-')
		{
			flag->left = 1;
			flag->zero = 0;
		}
		else if (**format == '+')
			flag->plus = 1;
		else if (**format == ' ')
			flag->space = 1;
		else if (**format == '#')
			flag->sharp = 1;
		else if (**format == '0' && !flag->left)
			flag->zero = 1;
		(*format)++;
	}
	while (ft_isdigit(**format))
	{
		flag->width = (10 * flag->width) + (**format - 48);
		(*format)++;
	}
	if (**format == '.')
	{
		flag->dot = 1;
		(*format)++;
		while (ft_isdigit(**format))
		{
			flag->precision = (10 * flag->precision) + (**format - 48);
			(*format)++;
		}
	}
}