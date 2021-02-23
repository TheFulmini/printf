/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:33:16 by afulmini          #+#    #+#             */
/*   Updated: 2020/12/18 12:46:01 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int             ft_printf(const char *format, ...)
{
    va_list     param;
    size_t      written_char;
    int         i;
    t_arg       *flags;

    va_start(param, format);
    flags = malloc(sizeof(t_arg));
    written_char = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] != '%' && (written_char += 1))
            ft_putchar(format[i]);
        else
        {
            i += ft_set_flags(flags, &(format[i]), param);
            written_char += ft_print_arg(&(format[i]), flags, param);
        }
        if (format[i])
            i++;
    }
    free(flags);
    va_end(param);
    return (written_char);
}
