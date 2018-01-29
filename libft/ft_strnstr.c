/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 16:23:43 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:05:56 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	unsigned long	i;
	unsigned long	j;
	char			*c_haystack;
	char			*c_needle;

	c_haystack = (char *)h;
	c_needle = (char *)n;
	if (ft_strlen(n) == 0)
		return (c_haystack);
	i = 0;
	while (c_haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (c_needle[j] == c_haystack[i + j] && i + j < len)
		{
			if (c_needle[j + 1] == '\0')
			{
				return (c_haystack + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
