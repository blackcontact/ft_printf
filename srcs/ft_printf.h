/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 11:58:37 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 19:40:45 by mschneid    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

# define TYPES "sSpdDioOuUxXcC%"
# define FLAGS "#0-+ "
# define LENGTH "hljzL"

# define ERROR "Error Error Error"

/*
** Flags:
** 0 - (#) alternate form
** 1 - (0) fill with 0 if width
** 2 - (-) left align output
** 3 - (+) positive sign
** 4 - ( ) space sign if plus
*/

/*
** Length:
** h  -> h
** hh -> H
** l  -> l
** ll -> L
** L  -> m
** j  -> j
** z  -> z
*/

typedef struct	s_output
{
	int			size;
	int			lastgood;
	char		*output;
}				t_output;

typedef struct	s_conversion
{
	char		flags[5];
	int			min_width;
	int			precision;
	int			precision_isset;
	char		length;
	char		type;
	void		*value;
	char		*output;
	int			size;
}				t_conversion;

char			*ft_itoa_base(long long n, int base);
char			*ft_uitoa_base(unsigned long long n, int base);
void			ft_outputaddchar(t_output *o, char c);
void			ft_strstructjoin(t_conversion *a, t_output *o);
void			printf_process_type(t_conversion *actual);
int				ft_printf_start(const char **nav, va_list ap, t_output *output);
int				ft_printf(const char *format, ...);
void			ft_printf_output_align(t_conversion *a);
void			ft_printf_output_sign(t_conversion *a, int neg);
void			ft_printf_output_precision(t_conversion *a, int neg);
char			*ft_printf_value_hex(t_conversion *actual);
char			*ft_printf_value_oct(t_conversion *actual);
char			*ft_printf_value_int(t_conversion *actual);
char			*ft_printf_value_uint(t_conversion *actual);
void			ft_nbchar_bef(char c, int i, t_conversion *actual);
void			ft_nbchar_aft(char c, int i, t_conversion *actual);
void			printf_process_decimal(t_conversion *actual);
void			printf_process_u_decimal(t_conversion *actual);
void			printf_process_hex(t_conversion *actual);
void			printf_process_oct(t_conversion *actual);
void			printf_process_char(t_conversion *a);
void			printf_process_string(t_conversion *a);
void			printf_process_wstring(t_conversion *actual);
void			printf_process_pointer(t_conversion *actual);
void			struct_blank(t_conversion *ret);
int				parse_false(t_conversion *result);
t_conversion	*printf_parsing(const char **nav, va_list ap);
int				ft_wcharlen(wchar_t c);
int				ft_wchartostr(wchar_t c, char *str);
int				verify_chars(wchar_t *str, t_conversion *actual);

#endif
