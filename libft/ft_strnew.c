/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:16:31 by gbryon            #+#    #+#             */
/*   Updated: 2017/05/09 01:03:56 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t len)
{
	char *mem_str;

	mem_str = malloc(len + 1);
	if (mem_str == NULL)
		return (NULL);
	ft_bzero(mem_str, len);
	mem_str[len++] = '\0';
	return (mem_str);
}
