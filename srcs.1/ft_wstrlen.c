/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 17:09:20 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 12:03:01 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_wstrlen(wchar_t *s)
{
	size_t		count;

	count = 0;
	while (*s)
		count += ft_wcharlen(*(s++));
	return (count);
}
