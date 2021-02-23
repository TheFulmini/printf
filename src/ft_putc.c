/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:07:47 by afulmini          #+#    #+#             */
/*   Updated: 2020/12/17 10:18:47 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_putc(t_arg *flags, va_list param, char c)
{
    int     i;

    i = 1;
    if (c != '%')
        c = (char)va_arg(param, int);
    if (flags->left == 1)
    {
        write(1, &c, 1);
        i += ft_putnchar(' ', flags->width - 1);
    }
    else if (flags->left == 0)
    {
        if (flags->zero == 1)
            i += ft_putnchar('0', flags->width - 1);
        else
            i += ft_putnchar(' ', flags->width - 1);
        write(1, &c, 1);
    }
    return (i);
}