/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 11:34:24 by gbryon            #+#    #+#             */
/*   Updated: 2017/05/02 18:43:37 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *same_part)
{
	char	*ptrstr;
	int		i;
	int		j;
	int		begin;

	ptrstr = (char *)str;
	i = 0;
	j = 0;
	begin = 0;
	if (*same_part == '\0')
		return ((char *)str);
	while (str[i])
	{
		begin = i;
		while (str[begin] == same_part[j])
		{
			j++;
			begin++;
			if (same_part[j] == '\0')
				return (&ptrstr[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
