/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 13:58:05 by gbryon            #+#    #+#             */
/*   Updated: 2017/04/29 15:19:22 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str1, const char *str2, size_t len)
{
	unsigned int i;
	unsigned int len_of_str1;

	len_of_str1 = ft_strlen(str1);
	i = 0;
	while (str2[i] && i < len)
	{
		str1[len_of_str1 + i] = str2[i];
		i++;
	}
	str1[len_of_str1 + i] = '\0';
	return (str1);
}
