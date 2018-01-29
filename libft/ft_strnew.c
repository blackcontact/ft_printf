/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 18:08:26 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:05:51 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*output;

	if (!(output = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	output = ft_memset(output, 0, size + 1);
	return (output);
}
