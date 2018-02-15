/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoinchar.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 17:28:50 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 13:18:35 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoinchar(char const *s1, char const c)
{
	char		*output;
	int			i;

	if (!s1)
		return (NULL);
	if (!(output = (char *)malloc(sizeof(char) * ft_strlen(s1) + 2)))
		return (NULL);
	i = 0;
	while (*s1)
	{
		output[i] = *s1;
		i++;
		s1++;
	}
	output[i++] = c;
	output[i] = '\0';
	return (output);
}
