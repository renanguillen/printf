/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_x_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:51:33 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/06/22 23:20:51 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/ft_printf_bonus.h"

static void	ft_identation_l(const char *format, unsigned int u, t_flags *flag)
{
	if (*format == 'x')
	{
		if (u == 0)
			write(1, "0", 1);
		else
		{
			if (flag->sharp)
				write(1, "0x", 2);
			ft_putbase(u, HEXA_LOWER);
		}
	}
	else
	{
		if (u == 0)
			write(1, "0", 1);
		else
		{
			if (flag->sharp)
				write(1, "0X", 2);
			ft_putbase(u, HEXA_UPPER);
		}
	}
	while (flag->width-- > 0)
		ft_putchar(' ');
}

static void	ft_identation_r(const char *format, unsigned int u, t_flags *flag)
{
	while (flag->width-- > 0)
		ft_putchar(' ');
	if (*format == 'x')
	{
		if (u == 0)
			write(1, "0", 1);
		else
		{
			if (flag->sharp)
				write(1, "0x", 2);
			ft_putbase(u, HEXA_LOWER);
		}
	}
	else
	{
		if (u == 0)
			write(1, "0", 1);
		else
		{
			if (flag->sharp)
				write(1, "0X", 2);
			ft_putbase(u, HEXA_UPPER);
		}
	}
}

int	ft_arg_x(const char *format, int len, va_list arg, t_flags *flag)
{
	unsigned int	u;
	int				hexalen;

	u = va_arg(arg, unsigned int);
	hexalen = ft_countdigits(u, 16);
	flag->width -= hexalen;
	if (flag->sharp)
	{
		len += 2;
		flag->width -= 2;
	}
	if (flag->width > 0)
		len += flag->width;
	if (u == 0)
		len -= 2;
	if (flag->left)
		ft_identation_l(format, u, flag);
	else
		ft_identation_r(format, u, flag);
	len += hexalen;
	return (len);
}