/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 13:10:48 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:06:06 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*c_haystack;
	char	*c_needle;

	c_haystack = (char *)haystack;
	c_needle = (char *)needle;
	if (ft_strlen(needle) == 0)
		return (c_haystack);
	i = 0;
	while (c_haystack[i] != '\0')
	{
		j = 0;
		while (c_needle[j] == c_haystack[i + j])
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
