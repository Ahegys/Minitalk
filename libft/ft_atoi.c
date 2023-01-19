/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:57:29 by afelipe-          #+#    #+#             */
/*   Updated: 2022/09/12 13:57:31 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		n;
	char	signal;

	n = 0;
	signal = 1;
	while (nptr && *nptr >= 9 && *nptr <= 32 && *nptr != '\e')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal *= -signal;
		nptr++;
	}
	while (ft_isdigit(*nptr))
		n = n * 10 + (*nptr++ - 48);
	return (n * signal);
}
