/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/14 15:20:20 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:06:13 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	beg;
	size_t	end;
	size_t	i;
	char	*output;

	if (!s)
		return (NULL);
	beg = 0;
	while ((s[beg] == ' ' || s[beg] == '\n' ||
	s[beg] == '\t') && s[beg] != '\0')
		beg++;
	end = ft_strlen(s) - 1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end > beg)
		end--;
	if (!(output = (char *)malloc(sizeof(char) * end - beg + 2)))
		return (NULL);
	i = 0;
	while (i + beg < end + 1)
	{
		output[i] = s[beg + i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
