/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:57:18 by afelipe-          #+#    #+#             */
/*   Updated: 2022/09/12 13:57:20 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	alloc_size;

	alloc_size = nmemb * size;
	if (alloc_size / size != nmemb && size)
		return (NULL);
	alloc = malloc(alloc_size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, alloc_size);
	return (alloc);
}
