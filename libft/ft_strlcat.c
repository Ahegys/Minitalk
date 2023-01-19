/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:55:11 by afelipe-          #+#    #+#             */
/*   Updated: 2022/09/12 13:55:12 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	sz;

	if (size > ft_strlen(dst))
	{
		sz = ft_strlen(dst) + ft_strlen(src);
		while (*dst)
		{
			dst++;
			size--;
		}
		i = 0;
		while (i < (size - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else
	{
		sz = ft_strlen(src) + size;
	}
	return (sz);
}
