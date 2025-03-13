/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_pars_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:06:08 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/13 16:39:35 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	skip_whitespace_and_sign(char *s, int *sign)
{
	int	x;

	x = 0;
	while ((s[x] >= 9 && s[x] <= 13) || s[x] == 32)
		x++;
	if (s[x] == '-' || s[x] == '+')
	{
		if (s[x] == '-')
			*sign = -1;
		x++;
	}
	return (x);
}

static long	handle_overflow(int sign)
{
	if (sign == 1)
		return (LONG_MAX);
	else
		return (LONG_MIN);
}

long	atoi_v2(char *s)
{
	int		x;
	long	result;
	int		sign;
	long	prev_result;

	sign = 1;
	x = skip_whitespace_and_sign(s, &sign);
	result = 0;
	while (s[x] >= '0' && s[x] <= '9')
	{
		prev_result = result;
		result = result * 10 + (s[x] - '0');
		if (result / 10 != prev_result)
			return (handle_overflow(sign));
		x++;
	}
	return (result * sign);
}

char	*allocate_word(char *s, char c, int *i)
{
	int		start;
	int		len;
	char	*word;

	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	len = *i - start;
	word = malloc((len + 1) * sizeof(char));
	if (word)
		ft_strlcpy(word, &s[start], len + 1);
	return (word);
}
int	count_words(char *s, char c)
{
	int	count;
	int	inside_word;
	int	i;

	count = 0;
	inside_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && !inside_word)
		{
			inside_word = 1;
			count++;
		}
		else if (s[i] == c)
			inside_word = 0;
		i++;
	}
	return (count);
}

char	**split_v2(char *s, char c)
{
	char	**result;
	int		words;
	int		i;
	int		w;

	words = count_words(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			result[w] = allocate_word(s, c, &i);
			if (!result[w])
				return (NULL);
			w++;
		}
	}
	result[w] = NULL;
	return (result);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
