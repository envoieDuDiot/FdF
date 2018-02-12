/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:07:58 by gbryon            #+#    #+#             */
/*   Updated: 2017/05/05 16:16:24 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			len_of_src;

	i = 0;
	j = 0;
	len_of_src = ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	if (size > 0)
		while (src[j] && i < size - 1)
			dst[i++] = src[j++];
	if (j > 0)
	{
		dst[i] = 0;
		return (len_of_src + i - j);
	}
	return (len_of_src + i);
}
