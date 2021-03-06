/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:59:01 by afulmini          #+#    #+#             */
/*   Updated: 2020/12/18 12:39:43 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void     flags_init(t_arg *flags)
{
    flags->zero = 0;
    flags->left = 0;
    flags->precision = -1;
    flags->width = 0;
}

static int      padding(t_arg *flags, const char *format, va_list param)
{
    int         i;
    int         arg_width;

    i = 0;
    arg_width = 0;
    if (ft_isdigit(format[i]))
        flags->width = ft_atoi(&format[i]);
    else 
    {
        arg_width = (int)va_arg(param, int);
        if (arg_width < 0)
        {
            arg_width = -arg_width;
            flags->left = 1;
            flags->zero = 0;
        }
        flags->width = arg_width;
        return (1);
    }
    while (ft_isdigit(format[i]))
        i++;
    return (i);
}

static int      precision(t_arg *flags, const char *format, va_list param)
{
    int         i;
    int         arg_precis;

    i = 1;
    arg_precis = 0;
    if (ft_isdigit(format[i]))
    {
        flags->precision = ft_atoi(&format[i]);
        if (flags->precision < 0)
            flags->precision = -1;
    }
    else if (format[i] == '*')
    {
        arg_precis = (int)va_arg(param, int);
        if (arg_precis < 0)
            flags->precision = -1;
        else 
            flags->precision = arg_precis;
        return (i + 1);
    }
    else
        flags->precision = 0;
    while (ft_isdigit(format[i]))
        i++;
    return (i);
}

int             ft_set_flags(t_arg *flags, const char *format, va_list param)
{
    int         i;

    i = 1;
    flags_init(flags);
    while ((ft_isdigit(format[i]) || ft_strchr("-*.", format[i])) && format[i])
    {
        if (format[i] == '0' && !flags->left)
        {
            flags->zero = 1;
            i++;
        }
        else if (format[i] == '-')
        {
            flags->zero = 0;
            flags->left = 1;
            i++;
        }
        else if (ft_isdigit(format[i]) || format[i] == '*')
            i += padding(flags, &(format[i]), param);
        else if (format[i] == '.')
            i += precision(flags, &(format[i]), param);
    }
    return (i);
}