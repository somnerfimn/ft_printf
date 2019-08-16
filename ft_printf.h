/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 04:04:51 by oorlov            #+#    #+#             */
/*   Updated: 2019/07/31 04:04:52 by oorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>

typedef union			u_value
{
	char				schar;
	wchar_t				swchar;
	short				sshort;
	int					sint;
	long				slong;
	long long			sllong;
	intmax_t			sintmax;

	unsigned char		uchar;
	unsigned short		ushort;
	unsigned int		uint;
	unsigned long		ulong;
	unsigned long long	ullong;
	uintmax_t			uintmax;

	size_t				sizet;
	char				*string;
	wchar_t				*wstring;
}						t_value;

typedef struct			s_flag
{
	char				flag;
	struct s_flag		*next;
}						t_flag;

typedef struct			s_arg
{
	t_value				*value;
	char				type;
	t_flag				*flag;
	int					f_width;
	int					prec;
	char				*modifier;
	int					offset;
}						t_arg;

typedef struct			s_buff
{
	char				*buff;
	int					buff_size;
	char				*value;
	int					v_size;
	char				*sup;
	int					sup_size;
	int					sup_pos;
	int					arg_offset;
	int					resized_value;
}						t_buff;

int						ft_printf(const char *restrict format, ...);

char					*ft_itoa_base_arg(long long n, int base, t_arg *arg);

char					*ft_uitoa_base_arg(unsigned long long n,
		unsigned int base, t_arg *arg);

int						is_type(char c);

int						is_flag(char c);

int						is_modifier(char c);

t_arg					*new_arg(void);

long long				arg_v(t_arg *arg);

unsigned long long		uarg_v(t_arg *arg);

void					set_arg_value(t_arg **a, char t, int off, va_list p);

t_buff					*new_buff();

void					free_buff(t_buff *buffer);

void					resize_value(t_buff **buffer, t_arg *arg);

void					buff_value(t_buff **buffer, t_arg *arg);

void					set_buff_sup(t_buff **buffer, t_arg *arg);

void					buff_size(t_buff **buffer, t_arg *arg);

void					set_buff_sup_pos(t_buff **buffer, t_arg *arg);

t_buff					*percent_buffer(char *format, va_list params);

int						num_type(t_arg *arg);

int						int_type(t_arg *arg);

int						uint_type(t_arg *arg);

void					free_arg(t_arg *arg);

t_arg					*get_arg(char *format, va_list params, int i);

t_flag					*new_flag(char flag);

void					free_flag(t_flag *f);

void					free_flags(t_arg *arg);

int						flag(t_arg *arg, char flag);

int						add_flag(t_arg *arg, char f);

int						hex_type(t_arg *arg);

int						oct_type(t_arg *arg);

int						alpha_type(t_arg *arg);

int						char_type(t_arg *arg);

int						point_type(t_arg *arg);

int						string_type(t_arg *arg);

int						percent_type(t_arg *arg);

char					*ft_set_sym(char c, int len);

char					*char_type_set(char c);

#endif
