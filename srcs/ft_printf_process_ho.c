/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_process_ho.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 18:18:29 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 18:50:17 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_output_precision_hex(t_conversion *a, int zero)
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

void		printf_process_hex(t_conversion *actual)
{
	int		i;
	char	*temp;
	int		zero;

	i = 0;
	actual->output = ft_printf_value_hex(actual);
	actual->size += ft_strlen(actual->output);
	zero = actual->output[0] == '0' || !actual->output[0] ? 1 : 0;
	ft_printf_output_precision_hex(actual, zero);
	if (actual->flags[0] && !zero)
	{
		temp = actual->output;
		actual->output = ft_strjoin("0x", actual->output);
		actual->size += 2;
		free(temp);
	}
	if (actual->type == 'X')
		while (actual->output[i])
		{
			actual->output[i] = ft_toupper(actual->output[i]);
			i++;
		}
	ft_printf_output_align(actual);
}

void		printf_process_oct(t_conversion *actual)
{
	int		i;
	char	*temp;
	int		zero;

	i = 0;
	if (actual->type == 'O')
		actual->length = 'l';
	actual->output = ft_printf_value_oct(actual);
	if (!actual->output[0] && (!actual->precision_isset || actual->flags[0]))
		actual->output = ft_strdup("0");
	actual->size += ft_strlen(actual->output);
	zero = actual->output[0] == '0' || !actual->output[0] ? 1 : 0;
	ft_printf_output_precision_hex(actual, zero);
	if ((actual->flags[0] && !zero && actual->output[0] != '0'))
	{
		temp = actual->output;
		actual->output = ft_strjoin("0", actual->output);
		actual->size++;
		free(temp);
	}
	ft_printf_output_align(actual);
}

char		*ft_printf_value_hex(t_conversion *actual)
{
	if (((signed int)actual->value) == 0 && actual->precision_isset)
		return (ft_strnew(0));
	else
	{
		if (!actual->length)
			return (ft_uitoa_base((unsigned int)actual->value, 16));
		else if (actual->length == 'h')
			return (ft_uitoa_base((int)actual->value, 16));
		else if (actual->length == 'H')
			return (ft_uitoa_base((unsigned char)actual->value, 16));
		else if (actual->length == 'l')
			return (ft_uitoa_base((signed long)actual->value, 16));
		else if (actual->length == 'L')
			return (ft_uitoa_base((signed long long)actual->value, 16));
		else if (actual->length == 'j')
			return (ft_uitoa_base((intmax_t)actual->value, 16));
		else if (actual->length == 'z')
			return (ft_uitoa_base((size_t)actual->value, 16));
	}
	return (NULL);
}

char		*ft_printf_value_oct(t_conversion *actual)
{
	if (((signed int)actual->value) == 0 && actual->precision_isset)
		return (ft_strnew(0));
	else
	{
		if (!actual->length)
			return (ft_uitoa_base((unsigned int)actual->value, 8));
		else if (actual->length == 'h')
			return (ft_uitoa_base((unsigned short)actual->value, 8));
		else if (actual->length == 'H')
			return (ft_uitoa_base((unsigned char)actual->value, 8));
		else if (actual->length == 'l')
			return (ft_uitoa_base((signed long)actual->value, 8));
		else if (actual->length == 'L')
			return (ft_uitoa_base((signed long long)actual->value, 8));
		else if (actual->length == 'j')
			return (ft_uitoa_base((intmax_t)actual->value, 8));
		else if (actual->length == 'z')
			return (ft_uitoa_base((size_t)actual->value, 8));
	}
	return (NULL);
}
