/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoyano <almoyano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:13:56 by almoyano          #+#    #+#             */
/*   Updated: 2024/10/17 17:43:36 by almoyano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_isspace(const char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static char	ft_sign(const char c, char *negative)
{
	if (c == '-' || c == '+')
	{
		*negative = (c == '-');
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long int	num;
	char		negative;

	num = 0;
	negative = 0;
	while (ft_isspace(*nptr))
		++nptr;
	if (ft_sign(*nptr, &negative))
		++nptr;
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = (num * 10) + (*nptr - '0');
		++nptr;
	}
	if (negative)
		return (-num);
	return (num);
}
