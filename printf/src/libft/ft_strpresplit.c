/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strpresplit.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:05:00 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 13:13:07 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_strpresplit(char *dest, char const *s, char c)
{
	int index;
	int j;

	j = 0;
	index = 0;
	while (((unsigned char*)s)[index] == c && s[index])
		index++;
	while (((unsigned char*)s)[index + j] != c && s[index + j])
	{
		dest[j] = ((unsigned char*)s)[index + j];
		j++;
	}
	dest[j] = '\0';
}
