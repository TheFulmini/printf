/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 14:58:30 by afulmini          #+#    #+#             */
/*   Updated: 2020/08/23 16:20:45 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		sized(int n)
{
	int	result;

	if (n == -2147483648)
		return (11);
	result = 1;
	if (n < 0)
	{
		result++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char			*ft_itoa(int n)
{
	char			*result;
	int				i;
	unsigned int	nbr;

	i = sized(n);
	if (!(result = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	result[i--] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		nbr = -1 * n;
		result[0] = '-';
	}
	else
		nbr = n;
	while (nbr > 0)
	{
		result[i--] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (result);
}
