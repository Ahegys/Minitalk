/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:54:29 by afelipe-          #+#    #+#             */
/*   Updated: 2022/09/13 01:47:26 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(s);
	i = 0;
	if (start >= str_len)
		return (ft_strdup(""));
	if (str_len - start < len)
		len = str_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[len] = 0;
	return (sub);
}
