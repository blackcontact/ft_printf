/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 13:16:38 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 10:34:27 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <limits.h>
#include <wchar.h>
#include <math.h>

double		ft_pow(double a, double b)
{
	if (b < 0)
		return ((1.0 / a) * (ft_pow(a, b + 1.0)));
	else if (b == 0)
		return (1.0);
	else if (b == 1.0)
		return (a);
	else
		return (a * a * ft_pow(a, b - 2.0));
}

int			ft_round(double a)
{
	if (a - (int)a > 0.5)
		return ((int)a + 1);
	else
		return ((int)a);
}
/*
char	*ft_itoa_base_double(long double n, int base)
{
	static char			list[] = "0123456789abcdef";
	long double			temp;
	int					digits;
	char				*output;

	temp = n;
	digits = 1;
	while ((temp /= base) && (temp > 1.0))
		digits++;
	output = ft_strnew(digits);
	temp = n;
	while (digits--)
	{
		output[digits] = list[temp % 10.0];
		temp /= 10.0;
	}
	return (output);
}*/
/*
char		*testprecision(double fractional, int precision)
{
	char	*output;
	int		digits;
	double	temp;
	char	*zeros;
	char	*tempstr;

	fractional = fractional * ft_pow(10.0, (double)precision);
	output = ft_itoa_base(ft_round(fractional), 10);
	temp = fractional;
	digits = 1;
	while ((temp /= 10.0) && (temp > 1.0))
		digits++;
	digits = precision - digits;
	if (++digits && (digits > 0))
	{
		zeros = ft_strnew(digits);
		while (digits--)
			zeros[digits] = '0';
		zeros[0] = '.';
		tempstr = output;
		output = ft_strjoin(zeros, output);
		free(zeros);
		free(tempstr);
	}
	return (output);
}

char		*ft_dtoa(double f, int precision)
{
	int		integer;
	double	fractional;
	char	*str_i;
	char	*str_f;
	char	*temp;

	integer = (int)f;
	fractional = f - (double)integer;
	str_i = ft_itoa_base(integer, 10);
	if (precision)
	{
		str_f = testprecision(fractional, precision);
		temp = str_i;
		str_i = ft_strjoin(temp, str_f);
		free(temp);
		free(str_f);
	}
	return (str_i);
}


char		*digits(double f)
{
	int		digits;
	double	temp;
	char	*output;

	digits = 1;
	temp = f;
	while ((temp /= 10.0) && (temp > 1.0))
		digits++;
	output = ft_strnew(digits);
	while (digits--)
	{
		//printf("%d", (int)(f / ft_pow(10, digits)));
		output[digits] = ((int)(f / ft_pow(10, digits))) + '0';
		f = f - ((int)(f / ft_pow(10, digits)) * ft_pow(10, digits));
	}
	return (output);
}*/

int		main(void)
{
	//setbuf(stdout, NULL);
	//setlocale(LC_ALL, "");

	int	test;
	ft_printf("Salut %n GFGDFGDF\n", &test);
	printf("%d", test);
}

