/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:50:10 by gbryon            #+#    #+#             */
/*   Updated: 2017/05/02 18:01:20 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t len)
{
	void	*mem_allouee;

	mem_allouee = malloc(len);
	if (mem_allouee == NULL)
		return (NULL);
	ft_bzero(mem_allouee, len);
	return (mem_allouee);
}
