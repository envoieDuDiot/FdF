/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:21:41 by gbryon            #+#    #+#             */
/*   Updated: 2017/05/09 11:32:02 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	char		*ptr_str;
	size_t		i;
	size_t		start;
	size_t		end;

	if (!str)
		return (NULL);
	ptr_str = (char *)str;
	i = 0;
	while (ptr_str[i] && (ptr_str[i] == '\t' || ptr_str[i] == '\n' ||
				ptr_str[i] == ' ' || ptr_str[i] == '\r' || ptr_str[i] == '\v' ||
				ptr_str[i] == '\f'))
		i++;
	if (ptr_str[i] == '\0')
		return (ft_strdup(""));
	start = i;
	i = 0;
	while (ptr_str[i])
		i++;
	while (i > 0 && (ptr_str[i] == '\t' || ptr_str[i] == '\n' ||
				ptr_str[i] == ' ' || ptr_str[i] == '\0' || str[i] == '\r' ||
				ptr_str[i] == '\v' || ptr_str[i] == '\f'))
		i--;
	end = i;
	return (ft_strsub(str, start, end - start + 1));
}
