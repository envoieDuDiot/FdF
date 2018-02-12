/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 11:12:07 by gbryon            #+#    #+#             */
/*   Updated: 2017/05/02 18:22:06 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int tf)
{
	char	*last_value;

	last_value = 0;
	while (*str)
	{
		if (*str == (char)tf)
			last_value = (char *)str;
		str++;
	}
	if (*str == (char)tf)
		last_value = (char *)str;
	return ((char *)last_value);
}
