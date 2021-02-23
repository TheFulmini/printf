/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:16:22 by afulmini          #+#    #+#             */
/*   Updated: 2020/12/18 12:48:43 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int  ft_print_s(char *str, t_arg *flags, int len)
{
    int     i;

    i = 0;
    if (flags->precision == 0)
    {
        i += ft_putnchar(' ', len);
        return (i);
    }
    else if (flags->precision > 0)
    {
        while (i < flags->precision && str[i])
        {
            ft_putchar(str[i]);
            i++;
        }
        return (i);
    }
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    return (i);
}

int         ft_puts(t_arg *flags, va_list param)
{
    int     i;
    char    *str;
    int     len;

    i = 0;
    str = va_arg(param, char *);
    if (!str)
        str = "(null)";
    len = ft_strlen(str);
    if (flags->precision >= 0 && flags->precision < len)
        len = flags->precision;
    if (flags->left)
    {
        i += ft_print_s(str, flags, len);
        i += ft_putnchar(' ', flags->width - len);
    }
    else 
    {
        if (flags->zero)
            i += ft_putnchar('0', flags->width - len);
        else
            i += ft_putnchar(' ', flags->width - len);
        i += ft_print_s(str, flags, len);
    }
    return (i);
}
