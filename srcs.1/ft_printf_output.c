/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_output.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 14:13:44 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 17:02:59 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_output_align(t_conversion *a)
{
	int		length;

	if ((length = a->min_width - a->size) > 0 && !a->flags[2])
	{
		ft_nbchar_bef(' ', length, a);
		a->size += length;
	}
	else if ((length > 0) && a->flags[2])
	{
		ft_nbchar_aft(' ', length, a);
		a->size += length;
	}
}

void	ft_printf_output_sign(t_conversion *a, int neg)
{
	if (!neg)
	{
		if (a->flags[3])
			ft_nbchar_bef('+', 1, a);
		else if (a->flags[4])
			ft_nbchar_bef(' ', 1, a);
		if (a->flags[3] || a->flags[4])
			a->size++;
	}
	else
	{
		ft_nbchar_bef('-', 1, a);
		a->size++;
	}
}

void	ft_printf_output_precision(t_conversion *a, int neg)
{
	int		length;
	int		sign;

	sign = (neg | (a->flags[3] ? 1 : 0) | (a->flags[4] ? 1 : 0));
	length = a->precision - a->size;
	if (a->precision_isset && length > 0)
	{
		ft_nbchar_bef('0', length, a);
		a->size += length;
	}
	else if (a->min_width > 0 && (length = a->min_width - a->size
	- sign) > 0 && a->flags[1] && !a->precision_isset && !a->flags[2])
	{
		ft_nbchar_bef('0', length, a);
		a->size += length;
	}
}

void	ft_printf_output_precision_hex(t_conversion *a, int zero)
{
	int		length;
	int		prefix;

	prefix = a->flags[0] && !zero ? 2 : 0;
	length = a->precision - a->size;
	if (a->precision_isset && length > 0)
	{
		ft_nbchar_bef('0', length, a);
		a->size += length;
	}
	else if (a->min_width > 0 && (length = a->min_width - a->size -
	prefix) > 0 && a->flags[1] && !a->precision_isset && !a->flags[2])
	{
		ft_nbchar_bef('0', length, a);
		a->size += length;
	}
}
