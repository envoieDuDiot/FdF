/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 00:00:11 by gbryon            #+#    #+#             */
/*   Updated: 2017/05/09 00:32:55 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*returnn;
	t_list		*prev;

	returnn = NULL;
	new = ft_lstnew(f(lst)->content, f(lst)->content_size);
	returnn = new;
	prev = new;
	lst = lst->next;
	while (lst)
	{
		if ((new = (t_list *)malloc(sizeof(*returnn))))
		{
			new->content = f(lst)->content;
			new->content_size = f(lst)->content_size;
			prev->next = new;
			prev = new;
		}
		lst = lst->next;
	}
	return (returnn);
}
