/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:46:01 by gbryon            #+#    #+#             */
/*   Updated: 2017/05/09 02:14:20 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wd_len(char const *str, char c)
{
	unsigned int	len_of_word;
	unsigned int	i;

	i = 0;
	len_of_word = 0;
	while (str[i] && str[i] != c)
	{
		len_of_word++;
		i++;
	}
	return (len_of_word);
}

static int	ft_tab_len(char const *str, char c)
{
	unsigned int	len_of_tab;
	unsigned int	i;
	unsigned int	reading;

	reading = 0;
	i = 0;
	len_of_tab = 0;
	while (str[i])
	{
		if (str[i] != c && reading == 0)
		{
			reading = 1;
			len_of_tab++;
		}
		if (str[i] == c)
			reading = 0;
		i++;
	}
	return (len_of_tab);
}

char		**ft_strsplit(char const *str, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	if (!str || !c)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_tab_len(str, c) + 1))))
		return (NULL);
	while (str[i] && j < (unsigned int)ft_tab_len(str, c))
	{
		while (str[i] == c && str[i])
			i++;
		if (!(tab[j] = (char *)malloc(sizeof(char) * wd_len(&str[i], c) + 1)))
			return (NULL);
		k = 0;
		while (str[i] && str[i] != c)
			tab[j][k++] = str[i++];
		tab[j++][k] = '\0';
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
