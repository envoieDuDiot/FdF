/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 21:04:57 by gbryon            #+#    #+#             */
/*   Updated: 2017/05/09 11:21:49 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	char	*mem_str;
	char	*str_ret;

	if (!str || !f)
		return (NULL);
	mem_str = ft_strnew(ft_strlen(str));
	if (mem_str == NULL || *str == '\0')
		return (NULL);
	str_ret = mem_str;
	while (*str)
	{
		*str_ret = f(*str);
		str_ret++;
		str++;
	}
	return (mem_str);
}
