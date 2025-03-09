/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:58:19 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/09 14:23:22 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	count_words(char *s, char c)
// {
// 	int	count;

// 	count = 0;
// 	bool inside_word = false;
// 	while (*s)
// 	{
// 		if (*s == c)
// 			inside_word = false;
// 		else if (!inside_word)
// 		{
// 			count++;
// 			inside_word = true;
// 		}
// 		s++;
// 	}
// 	return count;
// }

// static char	*get_next_word(char *s, char c)
// {
// 	static int	cursor;
// 	char	*next_word;
// 	int len;
// 	int i;

// 	cursor = 0;
// 	len = 0;
// 	i = 0;
// 	while (s[cursor] == c)
// 		cursor++;
// 	while (s[cursor + len] != c && s[cursor + len])
// 		len++;
// 	next_word = malloc((len + 1) * sizeof(char));
// 	if (!next_word)
// 		return NULL;
// 	while (s[cursor] != c && s[cursor])
// 		next_word[i++] = s[cursor++];
// 	next_word[i] = '\0';
// 	return next_word;
// }

// char	**split(char *s, char c)
// {
// 	int		words_count;
// 	char	**result_array;

// 	words_count = count_words(s, c);
// 	result_array = malloc((words_count + 1) * sizeof(char *));
// 	if (!result_array)
// 		return NULL;
// 	int i = 0;
// 	while (i < words_count)
// 		result_array[i++] = get_next_word(s, c);
// 	result_array[i] = NULL;
// 	return result_array;
// }

// static int	count_words(const char *str, char c)
// {
// 	int	i;
// 	int	trigger;

// 	i = 0;
// 	trigger = 0;
// 	while (*str)
// 	{
// 		if (*str != c && trigger == 0)
// 		{
// 			trigger = 1;
// 			i++;
// 		}
// 		else if (*str == c)
// 			trigger = 0;
// 		str++;
// 	}
// 	return (i);
// }

// static char	*word_dup(const char *str, int start, int finish)
// {
// 	char	*word;
// 	int		i;

// 	i = 0;
// 	word = malloc((finish - start + 1) * sizeof(char));
// 	while (start < finish)
// 		word[i++] = str[start++];
// 	word[i] = '\0';
// 	return (word);
// }

// char	**ft_split_the_av(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		index;
// 	char	**splited;

// 	splited = malloc((count_words(s, c) + 1) * sizeof(char *));
// 	if (!s || !splited)
// 		return (0);
// 	i = 0;
// 	j = 0;
// 	index = -1;
// 	while (i <= ft_strlen(s))
// 	{
// 		if (s[i] != c && index < 0)
// 			index = i;
// 		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
// 		{
// 			splited[j++] = word_dup(s, index, i);
// 			index = -1;
// 		}
// 		i++;
// 	}
// 	splited[j] = 0;
// 	return (splited);
// }

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
