/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:56:28 by afelipe-          #+#    #+#             */
/*   Updated: 2022/09/12 13:56:30 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*uc_s;

	uc_s = (unsigned char *) s;
	while (n--)
	{
		if (*uc_s == (unsigned char) c)
			return (uc_s);
		uc_s++;
	}
	return (NULL);
}
