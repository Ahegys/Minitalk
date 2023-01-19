/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:55:40 by afelipe-          #+#    #+#             */
/*   Updated: 2022/09/13 07:58:40 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_insertstr(char **list, char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	start;

	i = 0;
	len = 0;
	start = 0;
	while (s[start + len])
	{
		while (s[start] == c && s[start])
			start++;
		while (s[start + len] != c && s[start + len])
			len++;
		if (len)
		{
			list[i] = ft_substr(s, start, len);
			start = start + len;
			len = 0;
			i++;
		}
	}
	list[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (!s)
	{
		list = malloc(sizeof(char *) * (1));
		list[0] = NULL;
		return (list);
	}
	while (s[i])
	{
		if (s[i] == c && i != 0 && s[i - 1] != c)
		count++;
		i++;
	}
	if (i != 0 && s[i - 1] != c && ft_strlen(s) > 0)
		count++;
	list = malloc(sizeof(char *) * (count + 1));
	if (!list)
		return (NULL);
	ft_insertstr(list, s, c);
	return (list);
}
