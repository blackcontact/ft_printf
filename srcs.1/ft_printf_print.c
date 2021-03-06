/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_print.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 12:53:29 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 11:32:15 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_hex(t_conversion *actual)
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

char	*ft_printf_oct(t_conversion *actual)
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

char	*ft_printf_int(t_conversion *actual)
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

char	*ft_printf_uint(t_conversion *actual)
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
