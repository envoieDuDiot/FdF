/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 10:06:47 by gbryon            #+#    #+#             */
/*   Updated: 2017/05/09 13:06:27 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (ptr_dst > ptr_src)
	{
		while (len--)
			ptr_dst[len] = ptr_src[len];
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
