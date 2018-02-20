/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_process.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 15:10:12 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 17:43:32 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_nbchar_bef(char c, int i, t_conversion *actual)
{
	char	*s1;
	char	*temp;
	int		j;
	int		k;

	s1 = ft_strnew(i);
	j = i;
	while (j--)
		s1[j] = c;
	temp = actual->output;
	actual->output = ft_strnew(i + actual->size);
	j = 0;
	while (j < i)
	{
		actual->output[j] = s1[j];
		j++;
	}
	k = 0;
	while (j < i + actual->size)
		actual->output[j++] = temp[k++];
	free(temp);
	free(s1);
}

void		ft_nbchar_aft(char c, int i, t_conversion *actual)
{
	char	*s1;
	char	*temp;
	int		j;
	int		k;

	s1 = ft_strnew(i);
	j = i;
	while (j--)
		s1[j] = c;
	temp = actual->output;
	actual->output = ft_strnew(i + actual->size);
	j = 0;
	while (j < actual->size)
	{
		actual->output[j] = temp[j];
		j++;
	}
	k = 0;
	while (j < i + actual->size)
		actual->output[j++] = s1[k++];
	free(temp);
	free(s1);
}

void		printf_process_decimal(t_conversion *actual)
{
	int		neg;
	char	*temp;

	if (actual->type == 'D')
		actual->length = 'l';
	actual->output = ft_printf_int(actual);
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
	actual->output = ft_printf_uint(actual);
	actual->size += ft_strlen(actual->output);
	ft_printf_output_precision(actual, 0);
	ft_printf_output_align(actual);
}

void		printf_process_modulo(t_conversion *actual)
{
	actual->output = ft_strdup("%");
	actual->size++;
	if (actual->flags[1] && actual->min_width > actual->size)
	{
		ft_nbchar_bef('0', actual->min_width - actual->size, actual);
		actual->size += actual->min_width - actual->size;
	}
	ft_printf_output_align(actual);
}

void		printf_process_hex(t_conversion *actual)
{
	int		i;
	char	*temp;
	int		zero;

	i = 0;
	actual->output = ft_printf_hex(actual);
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
	actual->output = ft_printf_oct(actual);
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

int			ft_wchartest(int value, int islong)
{
	if (((MB_CUR_MAX == 1 && value > 255)) || ((islong)
	&& ((value > 0x10ffff) || (value > 0xd7ff && value < 0xe000)
	|| (value < 0))))
		return (-1);
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
	charlen = MB_CUR_MAX == 1 ? 1 : ft_wcharlen((wchar_t)a->value);
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

void		printf_process_string(t_conversion *actual)
{
	int		max;
	int		tofree;
	char	*temp;

	if ((tofree = actual->value ? 0 : 1))
		actual->value = ft_strdup("(null)");
	if (actual->precision_isset)
	{
		max = (ft_strlen(actual->value) < (size_t)actual->precision
		? ft_strlen(actual->value) : actual->precision);
		temp = actual->output;
		actual->output = ft_strsub(actual->value, 0, max);
		free(temp);
	}
	else
		actual->output = ft_strdup(actual->value);
	actual->size += ft_strlen(actual->output);
	if (actual->flags[1] && actual->min_width > actual->size)
	{
		ft_nbchar_bef('0', actual->min_width - actual->size, actual);
		actual->size += actual->min_width - actual->size;
	}
	ft_printf_output_align(actual);
	if (tofree)
		ft_memdel(&actual->value);
}

char		*convert_str(wchar_t *wstr)
{
	char	*output;
	size_t	count;

	if (!wstr)
		return (NULL);
	if (!(output = (char *)malloc(sizeof(char) * ft_wstrlen(wstr) + 1)))
		return (NULL);
	count = 0;
	while (*wstr)
	{
		if (MB_CUR_MAX == 1)
		{
			output[count] = (int)*wstr;
			count++;
			wstr++;
		}
		else
			count += ft_wchartostr(*(wstr++), (output + count));
	}
	output[count] = '\0';
	return (output);
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

void		printf_process_wstring(t_conversion *actual)
{
	int		i;
	wchar_t	*value;

	if (actual->precision_isset && MB_CUR_MAX != 1)
	{
		i = 0;
		value = actual->value;
		while (i < actual->precision)
		{
			if (ft_wcharlen(*value) + i > actual->precision)
				break ;
			i += ft_wcharlen(*(value++));
		}
		actual->precision = i;
	}
	if (actual->value && verify_chars((wchar_t *)actual->value, actual))
	{
		actual->size = -1;
		return ;
	}
	actual->value = (convert_str((wchar_t *)actual->value));
	printf_process_string(actual);
	if (actual->value)
		ft_memdel(&actual->value);
}

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

void		printf_process_unknown(t_conversion *actual)
{
	long	test;

	test = actual->type;
	actual->value = (void *)test;
	printf_process_char(actual);
}
