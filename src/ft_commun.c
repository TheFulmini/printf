/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:55:12 by afulmini          #+#    #+#             */
/*   Updated: 2020/12/18 13:10:09 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int         ft_len_nbr_base(long nbr, char *base)
{
    int     i;
    int     len_base;

    i = 0;
    if (nbr == 0)
        return (1);
    if (nbr < 0)
        nbr = -nbr;
    len_base = ft_strlen(base);
    if (len_base == 0)
        return (0);
    while (nbr > 0)
    {
        i++;
        nbr = nbr / len_base;
    }
    return (i);
}

int         ft_print_nbr_base(long nbr, char *base)
{
    int     i;
    int     len_base;

    i = 0;
    len_base = ft_strlen(base);
    if (nbr >= len_base)
    {
        ft_print_nbr_base(nbr / len_base, base);
        ft_print_nbr_base(nbr % len_base, base);
    }
    else
        ft_putchar_fd(base[nbr % len_base], 1);
    return (ft_len_nbr_base(nbr, base));
}
