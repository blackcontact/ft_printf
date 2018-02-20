/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_process_unic.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 18:26:54 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 19:03:56 by mschneid    ###    #+. /#+    ###.fr     */
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

int			ft_wchartest(int value, int islong)
{
	if (((MB_CUR_MAX == 1 && value > 255)) || ((islong)
	&& ((value > 0x10ffff) || (value > 0xd7ff && value < 0xe000)
	|| (value < 0))))
		return (-1);
	return (0);
}

int			verify_chars(wchar_t *str, t_conversion *actual)
{
	int		limit;

	if (actual->precision_isset)
	{
		limit = actual->precision;
		while (*str && limit)
		{
			if (ft_wchartest(*str, 1))
				return (-1);
			str++;
			limit--;
		}
	}
	else
	{
		while (*str)
		{
			if (ft_wchartest(*str, 1))
				return (-1);
			str++;
		}
	}
	return (0);
}

void		printf_process_char(t_conversion *a)
{
	int		charlen;
	int		islong;

	islong = ((a->type == 'c' && a->length == 'l') || a->type == 'C') ? 1 : 0;
	if (ft_wchartest((int)a->value, islong))
	{
		a->size = -1;
		return ;
	}
	charlen = MB_CUR_MAX == 1 || !islong ? 1 : ft_wcharlen((wchar_t)a->value);
	a->output = ft_strnew(charlen);
	if ((a->type == 'c' && a->length != 'l') || MB_CUR_MAX == 1)
		ft_nbchar_bef((char)a->value, 1, a);
	else
		ft_wchartostr((wchar_t)a->value, a->output);
	a->size += charlen;
	if (a->flags[1])
		ft_printf_output_precision(a, 0);
	else
		ft_printf_output_align(a);
	if (a->min_width > a->size && !a->flags[0])
	{
		ft_nbchar_bef('0', a->min_width - a->size, a);
		a->size += a->min_width - a->size;
	}
}
