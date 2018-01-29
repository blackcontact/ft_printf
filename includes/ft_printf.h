/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mschneid <mschneid@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 13:15:21 by mschneid     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 15:54:17 by mschneid    ###    #+. /#+    ###.fr     */
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
}				t_conversion;

/*
** debug.c
*/
void			debug(t_conversion *test);
/*
** ft_itoa_base.c
*/
char			*ft_itoa_base(long long n, int base);
char			*ft_uitoa_base(unsigned long long n, int base);
/*
** ft_printf_output.c
*/
void			ft_printf_output_align(t_conversion *a);
void			ft_printf_output_sign(t_conversion *a, int neg);
void			ft_printf_output_precision(t_conversion *a, int neg);
void			ft_printf_output_precision_hex(t_conversion *a, int zero);
/*
** ft_printf_parsing.c
*/
void			parse_flags(const char **nav, t_conversion *result);
void			parse_minwidth(const char **nav, t_conversion *result);
void			parse_precision(const char **nav, t_conversion *result);
void			parse_length(const char **nav, t_conversion *result);
void			parse_type(const char **nav, t_conversion *result);
/*
** ft_printf_print.c
*/
void			ft_printf_hex(t_conversion *actual);
void			ft_printf_oct(t_conversion *actual);
void			ft_printf_int(t_conversion *actual);
void			ft_printf_uint(t_conversion *actual);
/*
** ft_printf_process.c
*/
char			*ft_nbchar_ba(char c, int i, char *s2, int position);
int				printf_process_decimal(t_conversion *a);
int				printf_process_u_decimal(t_conversion *a);
int				printf_process_modulo(t_conversion *actual);
int				printf_process_hex(t_conversion *actual);
int				printf_process_oct(t_conversion *actual);
int				printf_process_char(t_conversion *actual);
int				printf_process_string(t_conversion *actual);
/*
** ft_printf_struct.c
*/
void			struct_blank(t_conversion *ret);
int				parse_verif(t_conversion *result);
t_conversion	*printf_parsing(const char **nav, va_list ap);
/*
** ft_printf.c
*/
int				printf_process_type(t_conversion *actual);
int				ft_printf(const char *format, ...);
/*
** ft_putwchar.c
*/
int				ft_putwchar(wchar_t c);

#endif
