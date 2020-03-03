/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:18:13 by qbarrier          #+#    #+#             */
/*   Updated: 2020/02/29 19:27:07 by qbarrier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coreware.h"

void		ft_exit_free_error(char *txt, t_info *info)
{
	ft_free_all(info);
	ft_putendl(txt);
	exit(0);
}

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
