/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 10:19:38 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 14:30:06 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int chaine;

	chaine = 0;
	while (s1[chaine] || s2[chaine])
	{
		if ((s1[chaine] - s2[chaine]) != 0)
			return ((unsigned char)s1[chaine] - (unsigned char)s2[chaine]);
		chaine++;
	}
	return (0);
}
