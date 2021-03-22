/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:16:22 by afulmini          #+#    #+#             */
/*   Updated: 2021/03/19 11:06:42 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_get_string(t_arg *flags, char *str, int *len)
{
	int		space;
	int		zero;

	if (flags->width > (*len) && flags->zero)
		zero = flags->width - (*len);
	else
		zero = 0;
	if (flags->width > (*len) && !zero)
		space = flags->width - (*len);
	else
		space = 0;
	flags->ret = flags->ret + (*len) + space + zero;
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	if (flags->zero)
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
	while ((*len)--)
		ft_putchar_fd(*str++, 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}

void			ft_print_s(va_list param, t_arg *flags)
{
	char	*str;
	char	*str_null;
	int		len;

	str_null = "(null)";
	if (!(str = va_arg(param, char*)))
		str = str_null;
	len = ft_strlen(str);
	if (flags->precision < len && flags->precision > 0)
		len = flags->precision;
	else if (flags->dot && !flags->precision)
		len = 0;
	else
		len = ft_strlen(str);
	ft_get_string(flags, str, &len);
}
