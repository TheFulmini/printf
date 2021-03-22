/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:31:19 by afulmini          #+#    #+#             */
/*   Updated: 2021/03/19 12:28:26 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_arg
{
	int	minus;
	int	zero;
	int	zero_per;
	int	width;
	int	dot;
	int	precision;
	int	negative;
	int	ret;
}				t_arg;

int				ft_printf(const char *format, ...);
void			ft_verif_flags(const char *format, va_list param, t_arg *flags,
						int *count);
void			ft_print_c(va_list param, t_arg *flags);
void			ft_print_s(va_list param, t_arg *flags);
void			ft_print_di(va_list param, t_arg *flags);
void			ft_print_u(va_list param, t_arg *flags);
void			ft_print_p(va_list param, t_arg *flags);
void			ft_print_bigx(va_list param, t_arg *flags);
void			ft_print_smallx(va_list param, t_arg *flags);
void			ft_print_percent(t_arg *flags);

#endif
