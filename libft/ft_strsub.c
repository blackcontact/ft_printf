/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/14 08:59:50 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:06:10 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*output;
	unsigned long	i;
	unsigned long	j;

	if (s)
	{
		if (!(output = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		i = start;
		j = 0;
		while (j < len && s[i])
		{
			output[j] = s[i];
			j++;
			i++;
		}
		output[j] = '\0';
		return (output);
	}
	return (NULL);
}
