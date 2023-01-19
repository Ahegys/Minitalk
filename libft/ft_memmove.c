/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:56:06 by afelipe-          #+#    #+#             */
/*   Updated: 2022/09/12 14:36:32 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char *) src;
	str2 = (char *) dest;
	if (src < dest && (src + n) > dest)
	{
		while (n > 0)
		{
			str2[n - 1] = str1[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(str2, str1, n);
	return (dest);
}
