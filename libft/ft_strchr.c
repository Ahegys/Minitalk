/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:55:35 by afelipe-          #+#    #+#             */
/*   Updated: 2022/09/12 13:55:38 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *args, int nbr)
{
	char	*ptr;

	ptr = (char *)args;
	if (nbr > 255)
		return (ptr);
	while (*ptr && *ptr != nbr)
		ptr++;
	if (*ptr == nbr)
		return (ptr);
	return (NULL);
}
