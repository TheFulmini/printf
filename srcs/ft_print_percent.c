/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:53:36 by afulmini          #+#    #+#             */
/*   Updated: 2021/03/19 12:00:54 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_percent_end(t_arg *flags, int *zero)
{
	int	space;

	if (flags->width > 1 && !(*zero))
		space = flags->width - 1;
	else
		space = 0;
	flags->ret = flags->ret + 1 + space + (*zero);
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	if (flags->zero)
		while ((*zero)-- > 0)
			ft_putchar_fd('0', 1);
	ft_putchar_fd('%', 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}

void			ft_print_percent(t_arg *flags)
{
	int	zero;

	if (flags->minus && flags->width > 1)
		zero = 0;
	else if (flags->width > 1 && !flags->zero_per)
		zero = 0;
	else if (flags->width > 1 && flags->dot && flags->zero_per)
	{
		zero = flags->width - 1;
		flags->zero = 1;
	}
	else if (flags->width > 1 && flags->dot && flags->precision > 0 &&
				!flags->zero)
	{
		zero = flags->width - 1;
		flags->zero = 1;
	}
	else if (flags->width > 1 && flags->zero)
		zero = flags->width - 1;
	else
		zero = 0;
	ft_percent_end(flags, &zero);
}
