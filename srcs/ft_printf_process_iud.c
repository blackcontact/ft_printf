/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_process_iud.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 18:11:53 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 18:50:04 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		printf_process_decimal(t_conversion *actual)
{
	int		neg;
	char	*temp;

	if (actual->type == 'D')
		actual->length = 'l';
	actual->output = ft_printf_value_int(actual);
	neg = 0;
	if (actual->output[0] == '-')
	{
		neg = 1;
		temp = actual->output;
		actual->output = ft_strsub(temp, 1, ft_strlen(temp) - 1);
		free(temp);
	}
	actual->size += ft_strlen(actual->output);
	ft_printf_output_precision(actual, neg);
	ft_printf_output_sign(actual, neg);
	ft_printf_output_align(actual);
}

void		printf_process_u_decimal(t_conversion *actual)
{
	if (actual->type == 'U')
		actual->length = 'l';
	actual->output = ft_printf_value_uint(actual);
	actual->size += ft_strlen(actual->output);
	ft_printf_output_precision(actual, 0);
	ft_printf_output_align(actual);
}

char		*ft_printf_value_int(t_conversion *actual)
{
	if (((signed int)actual->value) == 0 && actual->precision_isset)
		return (ft_strnew(0));
	else
	{
		if (!actual->length)
			return (ft_itoa_base((signed int)actual->value, 10));
		else if (actual->length == 'h')
			return (ft_itoa_base((signed short)actual->value, 10));
		else if (actual->length == 'H')
			return (ft_itoa_base((signed char)actual->value, 10));
		else if (actual->length == 'l')
			return (ft_itoa_base((signed long)actual->value, 10));
		else if (actual->length == 'L')
			return (ft_itoa_base((signed long long)actual->value, 10));
		else if (actual->length == 'j')
			return (ft_itoa_base((intmax_t)actual->value, 10));
		else if (actual->length == 'z')
			return (ft_itoa_base((size_t)actual->value, 10));
	}
	return (NULL);
}

char		*ft_printf_value_uint(t_conversion *actual)
{
	if (((signed int)actual->value) == 0 && actual->precision_isset)
		return (ft_strnew(0));
	else
	{
		if (!actual->length)
			return (ft_uitoa_base((unsigned int)actual->value, 10));
		else if (actual->length == 'h')
			return (ft_uitoa_base((unsigned short)actual->value, 10));
		else if (actual->length == 'H')
			return (ft_uitoa_base((unsigned char)actual->value, 10));
		else if (actual->length == 'l')
			return (ft_uitoa_base((unsigned long)actual->value, 10));
		else if (actual->length == 'L')
			return (ft_uitoa_base((unsigned	long long)actual->value, 10));
		else if (actual->length == 'j')
			return (ft_uitoa_base((uintmax_t)actual->value, 10));
		else if (actual->length == 'z')
			return (ft_uitoa_base((size_t)actual->value, 10));
	}
	return (NULL);
}
