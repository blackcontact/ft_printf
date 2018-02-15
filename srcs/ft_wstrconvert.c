/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrconvert.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:33:23 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 17:00:19 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t			*ft_wstrconvert(const char *s)
{
	size_t		i;
	wchar_t		*output;

	if (!(output = (wchar_t *)malloc(sizeof(wchar_t) * ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		output[i] = s[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
