/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_pars_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:06:08 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/11 18:28:41 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long	atoi_v2(char *s)
{
	int		x;
	long	result;
	int		sign;

	x = 0;
	result = 0;
	sign = 1;
	while (s[x] == ' ' || s[x] == '\t' || s[x] == '\n'
		|| s[x] == '\r' || s[x] == '\f' || s[x] == '\v')
		x++;
	if (s[x] == '-' || s[x] == '+')
	{
		if (s[x] == '-')
			sign = -1;
		x++;
	}
	while (s[x] >= 48 && s[x] <= 57)
	{
		result = result * 10 + (s[x] - '0');
		x++;
	}
	return (result * sign);
}

static int	count_words(char *s, char c)
{
	int	x;
	int	count;
	int	inside_word;

	x = 0;
	count = 0;
	while (s[x])
	{
		inside_word = 0;
		while (s[x] == c)
			++x;
		while (s[x] != c && s[x])
		{
			if (!inside_word)
			{
				++count;
				inside_word = 1;
			}
			++x;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			x;

	len = 0;
	x = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[x++] = s[cursor++];
	next_word[x] = '\0';
	return (next_word);
}

char	**split_v2(char *s, char c)
{
	int		x;
	int		words_count;
	char	**result_array;

	x = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (x == 0)
		{
			result_array[x] = malloc(sizeof(char));
			if (!result_array[x])
				return (NULL);
			result_array[x++][0] = '\0';
			continue ;
		}
		result_array[x++] = get_next_word(s, c);
	}
	result_array[x] = NULL;
	return (result_array);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
