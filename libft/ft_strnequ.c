/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 08:31:59 by gbryon            #+#    #+#             */
/*   Updated: 2017/05/09 11:50:54 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *str1, char const *str2, size_t len)
{
	if (!str1 || !str2)
		return (0);
	if (ft_strncmp(str1, str2, len) == 0)
		return (1);
	else
		return (0);
}
