/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paramters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:59:01 by afulmini          #+#    #+#             */
/*   Updated: 2021/03/19 12:33:50 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_minus_zero(const char *format, t_arg *flags, int *count)
{
	while (format[(*count)] == '-' || format[(*count)] == '0')
	{
		if (format[(*count)] == '-')
			flags->minus = 1;
		if (format[(*count)] == '0' && !flags->minus)
		{
			flags->zero_per = 1;
			flags->zero = 1;
		}
		else
			flags->zero = 0;
		(*count)++;
	}
}

static int		ft_len(const char *format, int *count)
{
	int	nbr;

	nbr = 0;
	while (ft_isdigit(format[(*count)]))
	{
		nbr = nbr * 10 + format[(*count)] - '0';
		(*count)++;
	}
	return (nbr);
}

static void		ft_width(const char *format, va_list param, t_arg *flags,
					int *count)
{
	if (format[(*count)] == '*')
	{
		flags->width = va_arg(param, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->zero = 0;
			flags->width *= -1;
		}
		(*count)++;
	}
	else
		flags->width = ft_len(format, count);
}

static void		ft_precision(const char *format, va_list param, t_arg *flags,
					int *count)
{
	while (format[(*count)] == '.')
	{
		flags->dot = 1;
		(*count)++;
	}
	if (format[(*count)] == '*')
	{
		flags->precision = va_arg(param, int);
		if (flags->precision >= 0)
			flags->zero = 0;
		(*count)++;
	}
	else
	{
		if (ft_isdigit(format[(*count)]))
			flags->zero = 0;
		flags->precision = ft_len(format, count);
	}
}

void			ft_verif_flags(const char *format, va_list param, t_arg *flags,
					int *count)
{
	if (format[(*count)] == '-' || format[(*count)] == '0')
		ft_minus_zero(format, flags, count);
	ft_width(format, param, flags, count);
	if (format[(*count)] == '.')
		ft_precision(format, param, flags, count);
}
