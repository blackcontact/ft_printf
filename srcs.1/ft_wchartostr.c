/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wchartostr.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 20:16:58 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 11:59:10 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wchartostr(wchar_t c, char *str)
{
	int		count;

	count = 0;
	if (++count && c <= 0x7F)
		str[0] = c;
	else if (++count && c <= 0x7FF)
	{
		str[0] = ((c >> 6) | 0xC0);
		str[1] = ((c & 0x3F) | 0x80);
	}
	else if (++count && c <= 0xFFFF)
	{
		str[0] = ((c >> 12) | 0xE0);
		str[1] = (((c >> 6) & 0x3F) | 0x80);
		str[2] = ((c & 0x3F) | 0x80);
	}
	else if (++count && c <= 0x10FFFF)
	{
		str[0] = ((c >> 18) | 0xF0);
		str[1] = (((c >> 12) & 0x3F) | 0x80);
		str[2] = (((c >> 6) & 0x3F) | 0x80);
		str[3] = ((c & 0x3F) | 0x80);
	}
	return (count);
}
