/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_process_sunis.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 18:32:59 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 14:08:10 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_wstrlen(wchar_t *s)
{
	size_t		count;

	count = 0;
	while (*s)
		count += ft_wcharlen(*(s++));
	return (count);
}

int				ft_wchartostr(wchar_t c, char *str)
{
	int		count;

	count = 0;
	if (++count && c <= 0x7F)
		str[0] = c;
	else if (++count && c <= 0x7FF)
	{
		str[0] = ((c >> 6) | 0xC0);
		str[1] = ((c & 0x3F) | 0x80);
	}
	else if (++count && c <= 0xFFFF)
	{
		str[0] = ((c >> 12) | 0xE0);
		str[1] = (((c >> 6) & 0x3F) | 0x80);
		str[2] = ((c & 0x3F) | 0x80);
	}
	else if (++count && c <= 0x10FFFF)
	{
		str[0] = ((c >> 18) | 0xF0);
		str[1] = (((c >> 12) & 0x3F) | 0x80);
		str[2] = (((c >> 6) & 0x3F) | 0x80);
		str[3] = ((c & 0x3F) | 0x80);
	}
	return (count);
}

static char		*convert_str(wchar_t *wstr)
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

void			printf_process_string(t_conversion *a)
{
	int		max;
	int		tofree;
	char	*temp;

	if ((tofree = a->value ? 0 : 1))
		a->value = ft_strdup("(null)");
	if (a->precision_isset)
	{
		max = (ft_strlen(a->value) < (size_t)a->precision
		? ft_strlen(a->value) : a->precision);
		temp = a->output;
		a->output = ft_strsub(a->value, 0, max);
		free(temp);
	}
	else
		a->output = ft_strdup(a->value);
	a->size += ft_strlen(a->output);
	if (a->flags[1] && !a->flags[2] && a->min_width > a->size)
	{
		ft_nbchar_bef('0', a->min_width - a->size, a);
		a->size += a->min_width - a->size;
	}
	ft_printf_output_align(a);
	if (tofree)
		ft_memdel(&a->value);
}

void			printf_process_wstring(t_conversion *actual)
{
	int		i;
	wchar_t	*value;

	if (actual->value && actual->precision_isset && MB_CUR_MAX != 1)
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
