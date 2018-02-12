/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 10:22:30 by gbryon            #+#    #+#             */
/*   Updated: 2017/04/29 14:57:25 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int i, size_t len)
{
	const unsigned char		*ptr;

	ptr = str;
	if (len)
	{
		while (len--)
		{
			if (*ptr != (unsigned char)i)
				ptr++;
			else
				return ((void *)(ptr));
		}
	}
	return (NULL);
}
