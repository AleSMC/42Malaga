/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoyano <almoyano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:58:00 by almoyano          #+#    #+#             */
/*   Updated: 2024/10/16 16:54:42 by almoyano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *scr, size_t n)
{
	size_t	i;

	if (!dest && !scr)
	{
		return (0);
	}
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)scr)[i];
		++i;
	}
	return (dest);
}
