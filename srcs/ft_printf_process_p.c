/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_process_p.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 18:21:45 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 18:23:29 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		printf_process_pointer(t_conversion *actual)
{
	char		*temp;

	if (!(unsigned long long)actual->value && actual->precision_isset)
		actual->output = ft_strnew(0);
	else
		actual->output = ft_uitoa_base((unsigned long long)actual->value, 16);
	actual->size += ft_strlen(actual->output);
	if ((actual->size < actual->min_width) && actual->flags[1])
	{
		ft_nbchar_aft('0', actual->min_width - actual->size - 2, actual);
		actual->size += actual->min_width - actual->size - 2;
	}
	if (actual->precision_isset && actual->precision > actual->size)
	{
		ft_nbchar_bef('0', actual->precision - actual->size, actual);
		actual->size += actual->precision - actual->size;
	}
	temp = actual->output;
	actual->output = ft_strjoin("0x", actual->output);
	actual->size += 2;
	free(temp);
	ft_printf_output_align(actual);
}
