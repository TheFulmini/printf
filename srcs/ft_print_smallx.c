/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_smallx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:45:30 by afulmini          #+#    #+#             */
/*   Updated: 2021/03/19 14:24:12 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_pre_smallx(t_arg *flags, int *space, int *zero, int *len_x)
{
	if (flags->precision > (*len_x))
		(*zero) = flags->precision - (*len_x);
	else if (flags->width > (*len_x) && flags->dot && !flags->precision)
		flags->zero = 0;
	else if (flags->width > (*len_x) && flags->zero)
		(*zero) = flags->width - (*len_x);
	else
		(*zero) = 0;
	if ((*zero) > 0)
		(*len_x) = (*len_x) + (*zero);
	if (flags->width > (*len_x) && !flags->zero)
		(*space) = flags->width - (*len_x);
	else
		(*space) = 0;
}

static void		ft_get_smallx(t_arg *flags, char *x, int *len_x)
{
	int	space;
	int	zero;
	int	i;

	i = 0;
	ft_pre_smallx(flags, &space, &zero, len_x);
	flags->ret = flags->ret + space + (*len_x);
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	while (zero-- > 0)
		ft_putchar_fd('0', 1);
	if (*len_x)
		while (x[i])
			ft_putchar_fd(x[i++], 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}

void			ft_print_smallx(va_list param, t_arg *flags)
{
	char	*x;
	int		len_x;

	x = ft_itoa_hex(va_arg(param, unsigned int), 16);
	len_x = ft_strlen(x);
	if (x && flags->dot && !flags->precision && x[0] == '0')
		len_x = 0;
	ft_get_smallx(flags, x, &len_x);
	free(x);
}
