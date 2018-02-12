/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:51:51 by gbryon            #+#    #+#             */
/*   Updated: 2017/04/29 14:46:20 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	len_of_str;

	len_of_str = ft_strlen(str) + 1;
	ptr = NULL;
	ptr = malloc(sizeof(char) * (len_of_str));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, str, len_of_str);
	return (ptr);
}
