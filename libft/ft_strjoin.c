/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 09:41:28 by gbryon            #+#    #+#             */
/*   Updated: 2017/05/09 11:54:35 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*mem_str;

	if (!str1 || !str2)
		return (NULL);
	if (!(mem_str = ft_strnew(ft_strlen(str1) + ft_strlen(str2))))
		return (NULL);
	mem_str = ft_strcpy(mem_str, str1);
	mem_str = ft_strcat(mem_str, str2);
	return (mem_str);
}
