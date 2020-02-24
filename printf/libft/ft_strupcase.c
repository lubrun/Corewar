/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strupcase.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 20:32:28 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/06 20:43:40 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int chaine;

	chaine = 0;
	while (str[chaine] != '\0')
	{
		if (str[chaine] >= 97 && str[chaine] <= 122)
			str[chaine] -= 32;
		chaine++;
	}
	return (str);
}
