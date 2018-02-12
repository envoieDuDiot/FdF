/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 13:43:19 by gbryon            #+#    #+#             */
/*   Updated: 2017/04/29 14:25:21 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str1, const char *str2)
{
	char	*ptr_str1;

	ptr_str1 = str1;
	while (*ptr_str1)
		ptr_str1++;
	while (*str2)
	{
		*ptr_str1 = *str2;
		ptr_str1++;
		str2++;
	}
	*ptr_str1 = '\0';
	return (str1);
}
