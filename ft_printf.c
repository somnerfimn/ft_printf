/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 03:46:49 by oorlov            #+#    #+#             */
/*   Updated: 2019/07/31 03:46:50 by oorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		main_buffer(char *format, va_list params, int *printed)
{
	int		i;
	t_buff	*p_buff;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!(p_buff = percent_buffer(format + i, params)))
				return ;
			write(1, p_buff->buff, p_buff->buff_size);
			*printed += p_buff->buff_size;
			i += p_buff->arg_offset;
			free_buff(p_buff);
		}
		else
		{
			ft_putchar(format[i]);
			*printed += 1;
		}
		i++;
	}
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		params;
	int			printed;
	char		*f;

	f = (char *)format;
	va_start(params, format);
	printed = 0;
	main_buffer(f, params, &printed);
	va_end(params);
	return (printed);
}
