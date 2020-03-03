/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_2dtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabouama <kabouama@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:17:57 by lubrun            #+#    #+#             */
/*   Updated: 2020/03/03 18:55:44 by kabouama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_2dtab(char **tab, int len)
{
	int		compteur;

	compteur = 0;
	while (compteur < len)
		ft_putendl(tab[compteur++]);
}
