/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_pars_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:31:34 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/13 15:40:05 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// char	*allocate_word(char *s, int start, int len)
// {
// 	char *word;

// 	word = malloc((len + 1) * sizeof(char));
// 	if (!word)
// 		return (NULL);
// 	ft_strlcpy(word, &s[start], len + 1);
// 	return (word);
// }
