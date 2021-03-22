/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 20:04:57 by afulmini          #+#    #+#             */
/*   Updated: 2021/03/19 12:35:29 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_pre_space(t_arg *flags, int *space, int *len_pointer,
						char *pointer)
{
	if (pointer && flags->width > (*len_pointer))
		(*space) = flags->width - (*len_pointer);
	else
		(*space) = 0;
}

static void		ft_pre_zero(t_arg *flags, int *zero, int *len_pointer,
						char *pointer)
{
	if (pointer && flags->precision > (*len_pointer))
		(*zero) = flags->precision - (*len_pointer);
	else
		(*zero) = 0;
	if (pointer && flags->dot && !flags->precision && *pointer == '0')
		(*len_pointer) = 2;
	else
		(*len_pointer) = (*len_pointer) + 2;
}

static void		ft_get_pointer(t_arg *flags, char *pointer)
{
	int	len_pointer;
	int	space;
	int	zero;
	int	i;

	i = 0;
	len_pointer = ft_strlen(pointer);
	ft_pre_zero(flags, &zero, &len_pointer, pointer);
	ft_pre_space(flags, &space, &len_pointer, pointer);
	flags->ret = flags->ret + len_pointer + space + zero;
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	write(1, "0x", 2);
	while (zero-- > 0)
		ft_putchar_fd('0', 1);
	if (len_pointer > 2)
		while (pointer[i])
			ft_putchar_fd(pointer[i++], 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}

void			ft_print_p(va_list param, t_arg *flags)
{
	char	*pointer;

	pointer = ft_itoa_pointers(va_arg(param, unsigned long int), 16);
	ft_get_pointer(flags, pointer);
	free(pointer);
}
