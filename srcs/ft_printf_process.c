/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_process.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 15:10:12 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 16:36:37 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_nbchar_ba(char c, int i, char *s2, int position)
{
	char	*s1;
	char	*temp;

	s1 = ft_strnew(i);
	while (i--)
		s1[i] = c;
	temp = s1;
	s1 = !position ? ft_strjoin(s1, s2) : ft_strjoin(s2, s1);
	ft_strdel(&temp);
	ft_strdel(&s2);
	return (s1);
}

int			printf_process_decimal(t_conversion *actual)
{
	int		neg;
	char	*temp;

	ft_printf_int(actual);
	neg = 0;
	if (actual->output[0] == '-')
	{
		neg = 1;
		temp = actual->output;
		actual->output = ft_strsub(temp, 1, ft_strlen(temp) - 1);
		free(temp);
	}
	ft_printf_output_precision(actual, neg);
	ft_printf_output_sign(actual, neg);
	ft_printf_output_align(actual);
	ft_putstr(actual->output);
	return (ft_strlen(actual->output));
}

int			printf_process_u_decimal(t_conversion *actual)
{
	if (actual->type == 'U')
		actual->length = 'l';
	ft_printf_uint(actual);
	ft_printf_output_precision(actual, 0);
	ft_printf_output_align(actual);
	ft_putstr(actual->output);
	return (ft_strlen(actual->output));
}

int			printf_process_modulo(t_conversion *actual)
{
	actual->output = ft_nbchar_ba('%', 1, ft_strnew(0), 0);
	ft_printf_output_precision(actual, 0);
	ft_printf_output_align(actual);
	ft_putstr(actual->output);
	return (ft_strlen(actual->output));
}

int			printf_process_hex(t_conversion *actual)
{
	int		i;
	char	*temp;
	int		zero;

	i = 0;
	ft_printf_hex(actual);
	zero = actual->output[0] == '0' || !actual->output[0] ? 1 : 0;
	ft_printf_output_precision_hex(actual, zero);
	if (actual->flags[0] && !zero)
	{
		temp = actual->output;
		actual->output = ft_strjoin("0x", actual->output);
		free(temp);
	}
	if (actual->type == 'X')
		while (actual->output[i])
		{
			actual->output[i] = ft_toupper(actual->output[i]);
			i++;
		}
	ft_printf_output_align(actual);
	ft_putstr(actual->output);
	return (ft_strlen(actual->output));
}

int			printf_process_oct(t_conversion *actual)
{
	int		i;
	char	*temp;
	int		zero;

	i = 0;
	ft_printf_oct(actual);
	zero = actual->output[0] == '0' || !actual->output[0] ? 1 : 0;
	ft_printf_output_precision_hex(actual, zero);
	if (actual->flags[0])
	{
		temp = actual->output;
		actual->output = ft_strjoin("0", actual->output);
		free(temp);
	}
	ft_printf_output_align(actual);
	ft_putstr(actual->output);
	return (ft_strlen(actual->output));
}

int			printf_process_char(t_conversion *actual)
{
	int		length;
	int		count;

	count = 1;
	if (!actual->flags[2] && (length = actual->min_width - 1) > 0)
		while (length--)
		{
			ft_putchar(' ');
			count++;
		}
	if (actual->type == 'C' || actual->length == 'l')
		count += ft_putwchar((wchar_t)actual->value);
	else
		ft_putchar((char)actual->value);
	if (actual->flags[2] && (length = actual->min_width - 1) > 0)
		while (length--)
		{
			ft_putchar(' ');
			count++;
		}
	return (count);
}

int			printf_process_string(t_conversion *actual)
{
	int		max;
	int		i;
	char	*value;
	int		tofree;

	if ((tofree = actual->value ? 0 : 1))
		actual->value = ft_strdup("(null)");
	value = actual->value;
	if (actual->precision_isset)
	{
		max = (ft_strlen(actual->value) < (size_t)actual->precision ?
		ft_strlen(actual->value) : actual->precision);
		actual->output = ft_strnew(max);
		i = -1;
		while (++i < max)
			actual->output[i] = value[i];
	}
	else
		actual->output = ft_strdup(actual->value);
	ft_printf_output_align(actual);
	ft_putstr(actual->output);
	if (tofree)
		free(actual->value);
	return (ft_strlen(actual->output));
}
