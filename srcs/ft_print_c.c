/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:07:47 by afulmini          #+#    #+#             */
/*   Updated: 2021/03/19 10:45:50 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_c(va_list param, t_arg *flags)
{
	char	c;
	int		space;
	int		zero;

	c = va_arg(param, int);
	if (flags->width > 1 && !flags->zero)
		space = flags->width - 1;
	else
		space = 0;
	if (flags->zero && flags->width > 1)
		zero = flags->width - 1;
	else
		zero = 0;
	flags->ret = flags->ret + 1 + space + zero;
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	if (flags->zero)
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
	ft_putchar_fd(c, 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}
