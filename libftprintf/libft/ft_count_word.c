/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:09:25 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:52:41 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_word(char const *s, char c)
{
	int		n;
	int		word;

	n = 0;
	word = 0;
	while (s[n] != '\0')
	{
		if ((s[n] == c && s[n + 1] != c && s[n + 1] != '\0')
				|| (n == 0 && s[n] != c && s[n] != '\0'))
		{
			word++;
			n++;
			while (s[n] != c && s[n] != '\0')
				n++;
		}
		else
			n++;
	}
	return (word);
}
