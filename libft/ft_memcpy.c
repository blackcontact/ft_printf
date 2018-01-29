/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/09 10:05:27 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 10:03:58 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*output;

	output = dst;
	while (n--)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		dst += sizeof(unsigned char);
		src++;
	}
	return (output);
}
