/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/10 17:52:44 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:04:52 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*output;

	output = (char *)s;
	while (*output != '\0')
	{
		if (*output == c)
			return (output);
		output++;
	}
	if (*output == c)
		return (output);
	return (NULL);
}
