/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_pars_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:12:38 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/13 18:13:01 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	skip_whitespace_and_sign(char *s, int *sign)
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

long	handle_overflow(int sign)
{
	if (sign == 1)
		return (LONG_MAX);
	else
		return (LONG_MIN);
}
