/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wcharlen.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 17:08:35 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 17:52:27 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_wcharlen(wchar_t c)
{
	if (c <= 0x007F)
		return (1);
	if (c <= 0x07FF)
		return (2);
	if (c <= 0xFFFF)
		return (3);
	return (4);
}
