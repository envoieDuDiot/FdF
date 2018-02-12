/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:59:53 by gbryon            #+#    #+#             */
/*   Updated: 2017/05/09 11:42:31 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*new_nod;

	if (!((new) = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new_nod = malloc(content_size)))
		{
			free(new);
			return (NULL);
		}
		new->content_size = content_size;
		new->content = ft_memcpy(new_nod, content, content_size);
	}
	new->next = NULL;
	return (new);
}
