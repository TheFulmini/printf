/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:33:01 by afulmini          #+#    #+#             */
/*   Updated: 2021/03/19 15:05:53 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_pre_u(t_arg *flags, int *space, int *zero, int *len)
{
	if (flags->precision > (*len))
		(*zero) = flags->precision - (*len);
	else if (!flags->precision && flags->dot && flags->width > (*len))
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

static void		ft_get_u(t_arg *flags, char *nbr_uns, int *len)
{
	int	space;
	int	zero;
	int	i;

	i = 0;
	ft_pre_u(flags, &space, &zero, len);
	flags->ret = flags->ret + space + (*len);
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	while (zero-- > 0)
		ft_putchar_fd('0', 1);
	if (*len)
		while (nbr_uns[i])
			ft_putchar_fd(nbr_uns[i++], 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}

void			ft_print_u(va_list param, t_arg *flags)
{
	char	*nbr_uns;
	int		len;

	nbr_uns = ft_itoa_uns(va_arg(param, unsigned int));
	len = ft_strlen(nbr_uns);
	if (nbr_uns && flags->dot && !flags->precision && nbr_uns[0] == '0')
		len = 0;
	ft_get_u(flags, nbr_uns, &len);
	free(nbr_uns);
}
