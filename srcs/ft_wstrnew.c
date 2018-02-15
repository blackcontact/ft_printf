/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrnew.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 17:44:47 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 17:48:32 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t	*output;

	if (!(output = (wchar_t *)malloc(sizeof(wchar_t) * size + 1)))
		return (NULL);
	output = ft_memset(output, 0, size + 1);
	return (output);
}
