/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 18:53:27 by gbryon            #+#    #+#             */
/*   Updated: 2017/05/08 20:00:50 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tf, size_t n)
{
	size_t len_of_tf;

	len_of_tf = ft_strlen(tf);
	if (*tf == '\0')
		return ((char *)str);
	while (*str && n-- >= len_of_tf)
	{
		if (ft_strncmp(str, tf, len_of_tf) == 0)
			return ((char *)str);
		str++;
	}
	return (0);
}
