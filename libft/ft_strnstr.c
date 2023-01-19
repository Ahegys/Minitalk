/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:54:43 by afelipe-          #+#    #+#             */
/*   Updated: 2022/09/12 14:01:02 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*cpy;
	size_t	lent;
	size_t	index;

	cpy = (char *)big;
	lent = ft_strlen(little);
	index = 0;
	if (!*little)
		return (cpy);
	while (big[index] && index < len)
	{
		if (!ft_strncmp(&big[index], little, lent) && (index + lent <= len))
			return (&cpy[index]);
		index++;
	}
	return (NULL);
}
