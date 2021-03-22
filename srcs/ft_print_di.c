/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:24:00 by afulmini          #+#    #+#             */
/*   Updated: 2021/03/19 12:08:20 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_pre_di(t_arg *flags, int *space, int *zero, int *len)
{
	if (flags->precision > (*len))
		(*zero) = flags->precision - (*len);
	else if (flags->width > (*len) && !flags->precision && flags->dot)
		flags->zero = 0;
	else if (flags->width > (*len) && flags->zero)
		(*zero) = flags->width - (*len);
	else
		(*zero) = 0;
	if ((*zero) > 0)
		(*len) = (*len) + (*zero);
	if (flags->width > (*len) && !flags->zero)
		(*space) = flags->width - (*len);
	else
		(*space) = 0;
}

static void		ft_get_di(t_arg *flags, char *nbr, int *len)
{
	int	space;
	int	zero;
	int	i;

	i = 0;
	ft_pre_di(flags, &space, &zero, len);
	flags->ret = flags->ret + space + (*len);
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	if (flags->negative)
		ft_putchar_fd(nbr[i++], 1);
	while (zero-- > 0)
		ft_putchar_fd('0', 1);
	if (*len)
		while (nbr[i])
			ft_putchar_fd(nbr[i++], 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}

void			ft_print_di(va_list param, t_arg *flags)
{
	char	*nbr;
	int		len;
	int		i;

	i = 0;
	nbr = ft_itoa(va_arg(param, int));
	len = ft_strlen(nbr);
	if (nbr && nbr[i] == '-')
	{
		flags->negative = 1;
		if (flags->precision > 0)
			flags->precision += 1;
	}
	if (nbr && flags->dot && !flags->precision && nbr[0] == '0')
		len = 0;
	ft_get_di(flags, nbr, &len);
	free(nbr);
}
