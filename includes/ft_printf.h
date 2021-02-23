/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:31:19 by afulmini          #+#    #+#             */
/*   Updated: 2020/12/17 17:43:43 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdarg.h>

typedef struct  s_arg
{
    int         zero;
    int         width;
    int         precision;
    int         left;
    
}               t_arg;

int             ft_printf(const char *format, ...);
int             ft_set_flags(t_arg *flags, const char *format, va_list param);
int             ft_print_arg(const char *format, t_arg *flags, va_list param);
int             ft_len_nbr_base(long nbr, char *base);
int             ft_print_nbr_base(long nbr, char *base);
int             ft_putc(t_arg *flags, va_list param, char c);
int             ft_puts(t_arg *flags, va_list param);
int             ft_putdi(t_arg *flags, va_list param);
int             ft_putx(t_arg *flags, va_list param, char *base);
int             ft_putu(t_arg *flags, va_list param);
int             ft_putp(t_arg *flags, va_list param);

#endif
