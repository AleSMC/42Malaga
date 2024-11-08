/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoyano <almoyano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:45:05 by almoyano          #+#    #+#             */
/*   Updated: 2024/10/25 17:52:55 by almoyano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_to_string(char *arr, long num, int *i)
{
	if ((num / 10) > 0)
		ft_to_string(arr, (num / 10), i);
	arr[*i] = (num % 10) + '0';
	++*i;
}

static long	ft_get_sing(int n, char *arr, int *i)
{
	long	num;

	*i = 0;
	if (n < 0)
	{
		num = -(long)n;
		arr[*i] = '-';
		++*i;
	}
	else
		num = n;
	return (num);
}

char	*ft_itoa(int n)
{
	char		*str;
	char		arr[12];
	long		num;
	int			i;

	num = ft_get_sing(n, arr, &i);
	ft_to_string(arr, num, &i);
	arr[i] = '\0';
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, arr, ft_strlen(arr) + 1);
	return (str);
}
