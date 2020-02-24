/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countword.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qbarrier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:06:34 by qbarrier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 13:11:17 by qbarrier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_countword(char *s, char c)
{
	int index;
	int string;

	string = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == c && s[index])
			index++;
		if (s[index] != c && s[index])
		{
			while (s[index] != c && s[index])
				index++;
			string++;
		}
	}
	return (string);
}
