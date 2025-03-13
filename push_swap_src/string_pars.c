/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:58:19 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/13 09:52:49 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


#include "push_swap.h"

// static int	skip_whitespace_and_sign(char *s, int *sign)
// {
// 	int	x;

// 	x = 0;
// 	while ((s[x] >= 9 && s[x] <= 13) || s[x] == 32)
// 		x++;
// 	if (s[x] == '-' || s[x] == '+')
// 	{
// 		if (s[x] == '-')
// 			*sign = -1;
// 		x++;
// 	}
// 	return (x);
// }

// static long	handle_overflow(int sign)
// {
// 	if (sign == 1)
// 		return (LONG_MAX);
// 	else
// 		return (LONG_MIN);
// }

#include <limits.h>
#include <errno.h>
#include <stdio.h>

long atoi_v2(char *s) {
    int x = 0;
    long result = 0;
    int sign = 1;

    while (s[x] == ' ' || s[x] == '\t' || s[x] == '\n' || s[x] == '\r' || s[x] == '\v' || s[x] == '\f') {
        x++;
    }
    if (s[x] == '-' || s[x] == '+') {
        if (s[x] == '-') {
            sign = -1;
        }
        x++;
    }
    while (s[x] >= '0' && s[x] <= '9') {
        if (result > (LONG_MAX - (s[x] - '0')) / 10) {
            errno = ERANGE;
            return (sign == 1) ? LONG_MAX : LONG_MIN;
        }
        result = result * 10 + (s[x] - '0');
        x++;
    }
    return (result * sign);
}



// long	atoi_v2(char *s)
// {
// 	int		x;
// 	long	result;
// 	int		sign;
// 	long	prev_result;

// 	sign = 1;
// 	x = skip_whitespace_and_sign(s, &sign);
// 	result = 0;
// 	while (s[x] >= '0' && s[x] <= '9')
// 	{
// 		prev_result = result;
// 		result = result * 10 + (s[x] - '0');
// 		if (result / 10 != prev_result)
// 			return (handle_overflow(sign));
// 		x++;
// 	}
// 	return (result * sign);
// }


// static int	count_words(char *s, char c)
// {
// 	int	x;
// 	int	count;
// 	int	inside_word;

// 	x = 0;
// 	count = 0;
// 	while (s[x])
// 	{
// 		inside_word = 0;
// 		while (s[x] == c)
// 			++x;
// 		while (s[x] != c && s[x])
// 		{
// 			if (!inside_word)
// 			{
// 				++count;
// 				inside_word = 1;
// 			}
// 			++x;
// 		}
// 	}
// 	return (count);
// }

// static char	*get_next_word(char *s, char c)
// {
// 	static int	cursor = 0;
// 	char		*next_word;
// 	int			len;
// 	int			x;

// 	len = 0;
// 	x = 0;
// 	while (s[cursor] == c)
// 		++cursor;
// 	while ((s[cursor + len] != c) && s[cursor + len])
// 		++len;
// 	next_word = malloc((size_t)len * sizeof(char) + 1);
// 	if (!next_word)
// 		return (NULL);
// 	while ((s[cursor] != c) && s[cursor])
// 		next_word[x++] = s[cursor++];
// 	next_word[x] = '\0';
// 	return (next_word);
// }

// char	**split_v2(char *s, char c)
// {
// 	int		x;
// 	int		words_count;
// 	char	**result_array;

// 	x = 0;
// 	words_count = count_words(s, c);
// 	if (!words_count)
// 		exit(1);
// 	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
// 	if (!result_array)
// 		return (NULL);
// 	while (words_count-- >= 0)
// 	{
// 		if (x == 0)
// 		{
// 			result_array[x] = malloc(sizeof(char));
// 			if (!result_array[x])
// 				return (NULL);
// 			result_array[x++][0] = '\0';
// 			continue ;
// 		}
// 		result_array[x++] = get_next_word(s, c);
// 	}
// 	result_array[x] = NULL;
// 	return (result_array);
// }

// static int count_words(char *s, char c)
// {
// 	int x = 0;
// 	int count = 0;
// 	int inside_word = 0;
// 	int inside_quotes = 0;
// 	char quote_type = 0;

// 	while (s[x])
// 	{
//         // Handle quotes
// 		if ((s[x] == '"' || s[x] == '\'') && !inside_quotes)
// 		{
// 			inside_quotes = 1;
// 			quote_type = s[x];
// 			if (!inside_word)
// 			{
// 				++count;
// 				inside_word = 1;
// 			}
// 		}
// 		else if (s[x] == quote_type && inside_quotes)
// 		{
// 			inside_quotes = 0;
// 			quote_type = 0;
// 		}
//         // Handle normal words
// 		else if (s[x] == c && !inside_quotes)
// 		{
// 			inside_word = 0;
// 		}
// 		else if (!inside_word)
// 		{
// 			++count;
// 			inside_word = 1;
// 		}
// 		++x;
// 	}
// 	return (count);
// }

// static char *get_next_word(char *s, char c, int *cursor)
// {
// 	char *next_word;
// 	int len = 0;
// 	int x = 0;
// 	int inside_quotes = 0;
// 	char quote_type = 0;

//     // Skip delimiter
// 	while (s[*cursor] == c)
// 		++(*cursor);
//     // Calculate word length
// 	while (s[*cursor + len])
// 	{
// 		if ((s[*cursor + len] == '"' || s[*cursor + len] == '\'') && !inside_quotes)
// 		{
// 			inside_quotes = 1;
// 			quote_type = s[*cursor + len];
// 		}
// 		else if (s[*cursor + len] == quote_type && inside_quotes)
// 		{
// 			inside_quotes = 0;
// 			quote_type = 0;
// 		}
// 		else if (s[*cursor + len] == c && !inside_quotes)
// 			break;
// 		++len;
// 	}
// 	// Allocate and copy word
// 	next_word = malloc((size_t)len * sizeof(char) + 1);
// 	if (!next_word)
// 		return (NULL);
//     // Copy word without quotes
// 	inside_quotes = 0;
// 	while (x < len)
// 	{
// 		if ((s[*cursor] == '"' || s[*cursor] == '\'') && !inside_quotes)
// 		{
// 			inside_quotes = 1;
// 			quote_type = s[*cursor];
// 			++(*cursor);
// 			continue;
// 		}
// 		else if (s[*cursor] == quote_type && inside_quotes)
// 		{
// 			inside_quotes = 0;
// 		quote_type = 0;
// 			++(*cursor);
// 			continue;
// 		}
// 		next_word[x++] = s[(*cursor)++];
// 	}
// 	next_word[x] = '\0';
//     // Skip delimiter after word
// 	if (s[*cursor] == c)
// 		++(*cursor);
// 	return (next_word);
// }

// char **split_v2(char *s, char c)
// {
//     int x = 0;
//     int cursor = 0;
//     int words_count = count_words(s, c);
//     char **result_array;

//     if (!words_count)
//         exit(1);
//     result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
//     if (!result_array)
//         return (NULL);

//     // Empty first element
//     result_array[x] = malloc(sizeof(char));
//     if (!result_array[x])
//         return (NULL);
//     result_array[x++][0] = '\0';

//     // Get actual words
//     while (x <= words_count)
//     {
//         result_array[x++] = get_next_word(s, c, &cursor);
//     }
//     result_array[x] = NULL;
//     return (result_array);
// }


static int count_words(char *s, char c)
{
    int x = 0;
    int count = 0;
    int inside_word = 0;
    int inside_quotes = 0;
    char quote_type = 0;

    while (s[x])
    {
        if ((s[x] == '"' || s[x] == '\'') && !inside_quotes)
        {
            inside_quotes = 1;
            quote_type = s[x];
            if (!inside_word)
            {
                ++count;
                inside_word = 1;
            }
        }
        else if (s[x] == quote_type && inside_quotes)
        {
            inside_quotes = 0;
            quote_type = 0;
        }
        else if (s[x] == c && !inside_quotes)
        {
            inside_word = 0;
        }
        else if (!inside_word)
        {
            ++count;
            inside_word = 1;
        }
        ++x;
    }
    return count;
}

/* Extracts the next word from the string s starting at *cursor,
   stopping when the delimiter (outside of quotes) is reached. */
static char *get_next_word(char *s, char c, int *cursor)
{
    char *next_word;
    int len = 0;
    int x = 0;
    int inside_quotes = 0;
    char quote_type = 0;

    /* Skip leading delimiters */
    while (s[*cursor] == c)
        (*cursor)++;

    /* Calculate length until next delimiter (accounting for quotes) */
    while (s[*cursor + len])
    {
        if ((s[*cursor + len] == '"' || s[*cursor + len] == '\'') && !inside_quotes)
        {
            inside_quotes = 1;
            quote_type = s[*cursor + len];
        }
        else if (s[*cursor + len] == quote_type && inside_quotes)
        {
            inside_quotes = 0;
            quote_type = 0;
        }
        else if (s[*cursor + len] == c && !inside_quotes)
            break;
        len++;
    }

    next_word = malloc((size_t)len + 1);
    if (!next_word)
        return NULL;

    inside_quotes = 0;
    while (x < len)
    {
        if ((s[*cursor] == '"' || s[*cursor] == '\'') && !inside_quotes)
        {
            inside_quotes = 1;
            quote_type = s[*cursor];
            (*cursor)++;
            continue;
        }
        else if (s[*cursor] == quote_type && inside_quotes)
        {
            inside_quotes = 0;
            quote_type = 0;
            (*cursor)++;
            continue;
        }
        next_word[x++] = s[(*cursor)++];
    }
    next_word[x] = '\0';

    if (s[*cursor] == c)
        (*cursor)++;
    return next_word;
}

/* Splits the string s by delimiter c into an array of strings.
   Returns a NULL-terminated array of words. */
char **split_v2(char *s, char c)
{
    int x = 0;
    int cursor = 0;
    int words_count = count_words(s, c);
    char **result_array;

    if (!words_count)
        return NULL;
    result_array = malloc(sizeof(char *) * (words_count + 1));
    if (!result_array)
        return NULL;

    while (x < words_count)
    {
        result_array[x] = get_next_word(s, c, &cursor);
        if (!result_array[x])
        {
            while (x > 0)
                free(result_array[--x]);
            free(result_array);
            return NULL;
        }
        x++;
    }
    result_array[x] = NULL;
    return result_array;
}
