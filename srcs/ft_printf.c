/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:33:16 by afulmini          #+#    #+#             */
/*   Updated: 2021/03/19 12:28:58 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_init_flags(t_arg *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->zero_per = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->negative = 0;
}

static void	specifiers(const char *format, va_list param, t_arg *flags,
				int *count)
{
	(*count)++;
	ft_verif_flags(format, param, flags, count);
	if (format[(*count)] == 'c')
		ft_print_c(param, flags);
	else if (format[(*count)] == 's')
		ft_print_s(param, flags);
	else if (format[(*count)] == 'd' || format[(*count)] == 'i')
		ft_print_di(param, flags);
	else if (format[(*count)] == 'u')
		ft_print_u(param, flags);
	else if (format[(*count)] == 'p')
		ft_print_p(param, flags);
	else if (format[(*count)] == 'x')
		ft_print_smallx(param, flags);
	else if (format[(*count)] == 'X')
		ft_print_bigx(param, flags);
	else if (format[(*count)] == '%')
		ft_print_percent(flags);
	else
	{
		write(1, "%", 1);
		flags->ret++;
		(*count)--;
	}
	ft_init_flags(flags);
}

int			ft_printf(const char *format, ...)
{
	va_list		param;
	t_arg		flags;
	int			count;

	count = 0;
	flags.ret = 0;
	ft_init_flags(&flags);
	va_start(param, format);
	while (format[count])
	{
		if (format[count] == '%')
			specifiers(format, param, &flags, &count);
		else
		{
			ft_putchar_fd(format[count], 1);
			flags.ret++;
		}
		count++;
	}
	va_end(param);
	return (flags.ret);
}
