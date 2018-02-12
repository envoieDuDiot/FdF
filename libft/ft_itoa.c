/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:54:10 by gbryon            #+#    #+#             */
/*   Updated: 2017/05/05 23:52:50 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				sign;
	int				size;
	char			*str;

	sign = (n >= 0) ? 1 : -1;
	nb = n * sign;
	size = (sign == -1) ? 2 : 1;
	while (nb /= 10)
		size++;
	str = ft_strnew(size);
	if (str == NULL)
		return (NULL);
	str[size] = 0;
	nb = n * sign;
	while (size--)
	{
		str[size] = nb % 10 + 48;
		nb /= 10;
	}
	str[0] = (sign == -1) ? '-' : str[0];
	return (str);
}
