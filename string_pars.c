/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:58:19 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/09 09:31:18 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char c)
{
	int	count;

	count = 0;
	bool inside_word = false;
	while (*s)
	{
		if (*s == c)
			inside_word = false;
		else if (!inside_word)
		{
			count++;
			inside_word = true;
		}
		s++;
	}
	return count;
}

static char	*get_next_word(char *s, char c)
{
	static int	cursor;
	char	*next_word;
	int len;
	int i;

	cursor = 0;
	len = 0;
	i = 0;
	while (s[cursor] == c)
		cursor++;
	while (s[cursor + len] != c && s[cursor + len])
		len++;
	next_word = malloc((len + 1) * sizeof(char));
	if (!next_word)
		return NULL;
	while (s[cursor] != c && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return next_word;
}

char	**split(char *s, char c)
{
	int		words_count;
	char	**result_array;

	words_count = count_words(s, c);
	result_array = malloc((words_count + 1) * sizeof(char *));
	if (!result_array)
		return NULL;
	int i = 0;
	while (i < words_count)
		result_array[i++] = get_next_word(s, c);
	result_array[i] = NULL;
	return result_array;
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

 long	atoi_v2(const char *s) //Define a function that converts every string into a long value
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}
