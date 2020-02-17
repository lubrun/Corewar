/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:13 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/17 15:57:18 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

char		*ft_chars_error(char *ret, char *str)
{
	ft_putstr(str);
	return (ret);
}

int			ft_close_error(int ret, char *str, int fd)
{
	close(fd);
	ft_putstr(str);
	return (ret);
}

int			ft_error(int ret, char *str)
{
	ft_putstr(str);
	return (ret);
}
