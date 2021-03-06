/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:54:59 by afulmini          #+#    #+#             */
/*   Updated: 2020/12/18 12:36:00 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int         ft_print_arg(const char *format, t_arg *flags, va_list param)
{
    int		i;

    i = 0;
    if (*format == '%')
        i += ft_putc(flags, param, '%');
    else if (*format == 'c')
        i += ft_putc(flags, param, (char)0);
    else if (*format == 's')
        i += ft_puts(flags, param);
    else if (*format == 'd' || *format == 'i')
        i += ft_putdi(flags, param);
    else if (*format == 'u')
        i += ft_putu(flags, param);
    else if (*format == 'x')
        i += ft_putx(flags, param, "0123456789abcdef");
    else if (*format == 'X')
        i += ft_putx(flags, param, "0123456789ABCDEF");
    else if (*format == 'b')
        i += ft_putx(flags, param, "01");
    else if (*format == 'o')
        i += ft_putx(flags, param, "01234567");
    else if (*format == 'p')
        i += ft_putp(flags, param);
    return (i);
}