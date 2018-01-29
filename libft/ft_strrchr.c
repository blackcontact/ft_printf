/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 09:13:43 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:05:58 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*output;
	char	*lastout;

	output = (char *)s;
	lastout = NULL;
	while (*output != '\0')
	{
		if (*output == c)
			lastout = output;
		output++;
	}
	if (*output == c)
		return (output);
	return (lastout);
}
