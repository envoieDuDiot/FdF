/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 08:12:14 by gbryon            #+#    #+#             */
/*   Updated: 2017/05/09 11:22:44 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mem_str;
	char			*str_ret;

	if (!str || !f)
		return (NULL);
	i = 0;
	mem_str = ft_strnew(ft_strlen(str));
	if (mem_str == NULL || *str == '\0')
		return (NULL);
	str_ret = mem_str;
	while (*str)
	{
		*str_ret = f(i, *str);
		str_ret++;
		str++;
		i++;
	}
	return (mem_str);
}
