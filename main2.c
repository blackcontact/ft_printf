/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main2.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 11:45:35 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 15:37:55 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*int		ft_wchartostr(wchar_t c, char *str)
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

char		*convert_str(wchar_t *wstr)
{
	char	*output;
	size_t	count;

	if (!(output = (char *)malloc(sizeof(char) * ft_wstrlen(wstr) + 1)))
		return (NULL);
	count = 0;
	while (*wstr)
		count += ft_wchartostr(*(wstr++), (output + count));
	return (output);
}

size_t			ft_wstrlen(wchar_t *s)
{
	size_t		count;

	count = 0;
	while (*s)
		count += ft_wcharlen(*(s++));
	return (count);
}

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		main(void)
{
	wchar_t test[] = L"Salut 米 Oh 米 LOL";
	char		*output;

	output = convert_str(test);
	setlocale(LC_ALL, "");
	printf("%s\n", output);
	printf("%S\n", test);
	printf("out=%zu, w=%zu\n", ft_strlen(output), ft_wstrlen(test));
	printf("%d\n", ft_wcharlen(L'米'));
	return (0);
}*/