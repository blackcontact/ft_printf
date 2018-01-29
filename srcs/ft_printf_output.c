/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_output.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 14:13:44 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 13:12:20 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_output_align(t_conversion *a)
{
	int		length;

	if ((length = a->min_width - ft_strlen(a->output)) > 0 && !a->flags[2])
		a->output = ft_nbchar_ba(' ', length, a->output, 0);
	else if ((length > 0) && a->flags[2])
		a->output = ft_nbchar_ba(' ', length, a->output, 1);
}

void		ft_printf_output_sign(t_conversion *a, int neg)
{
	if (!neg)
	{
		if (a->flags[3])
			a->output = ft_nbchar_ba('+', 1, a->output, 0);
		else if (a->flags[4])
			a->output = ft_nbchar_ba(' ', 1, a->output, 0);
	}
	else
		a->output = ft_nbchar_ba('-', 1, a->output, 0);
}

void		ft_printf_output_precision(t_conversion *a, int neg)
{
	int		length;
	int		sign;

	sign = (neg | (a->flags[3] ? 1 : 0) | (a->flags[4] ? 1 : 0));
	length = a->precision - ft_strlen(a->output);
	if (a->precision_isset && length > 0)
		a->output = ft_nbchar_ba('0', length, a->output, 0);
	else if (a->min_width > 0 && (length = a->min_width - ft_strlen(a->output)
	- sign) > 0 && a->flags[1] && !a->precision_isset && !a->flags[2])
		a->output = ft_nbchar_ba('0', length, a->output, 0);
}

void		ft_printf_output_precision_hex(t_conversion *a, int zero)
{
	int		length;
	int		prefix;

	prefix = a->flags[0] && !zero ? 2 : 0;
	length = a->precision - ft_strlen(a->output) - prefix;
	if (a->precision_isset && length > 0)
		a->output = ft_nbchar_ba('0', length, a->output, 0);
	else if (a->min_width > 0 && (length = a->min_width - ft_strlen(a->output) -
	prefix) > 0 && a->flags[1] && !a->precision_isset && !a->flags[2])
		a->output = ft_nbchar_ba('0', length, a->output, 0);
}
