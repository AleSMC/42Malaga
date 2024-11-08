/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoyano <almoyano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:49:11 by almoyano          #+#    #+#             */
/*   Updated: 2024/10/23 19:08:43 by almoyano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int		words;
	int		i;
	char	nueva_palabra;

	i = 0;
	words = 0;
	nueva_palabra = 1;
	while (s[i] != '\0')
	{
		if (nueva_palabra && s[i] != c)
		{
			++words;
			nueva_palabra = 0;
		}
		if (s[i] == c)
		{
			nueva_palabra = 1;
		}
		++i;
	}
	return (words);
}

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
	{
		++len;
	}
	return (len);
}

static void	ft_memory_free(char **strs, int i)
{
	while (i > 0)
		free(strs[--i]);
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;

	strs = malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (ft_word_len(s, c) == 0)
			++s;
		else
		{
			strs[i] = ft_substr(s, 0, ft_word_len(s, c));
			if (!strs[i])
			{
				ft_memory_free(strs, i);
				return (NULL);
			}
			++i;
			s += ft_word_len(s, c);
		}
	}
	strs[i] = NULL;
	return (strs);
}
