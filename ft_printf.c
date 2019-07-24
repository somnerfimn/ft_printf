/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:27:07 by oorlov            #+#    #+#             */
/*   Updated: 2019/07/24 11:27:09 by oorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				count_flag(char *format)
{
	int			count;
	int			result;

	count = 0;
	result = 0;
	while (format[count])
		if(format[count++] == '%')
			result++;
	return (result);
}

int				ft_printf(char *format, ...)
{
	va_list		ap;
	int			d;
	char		*p;

	va_start(ap, format);
	printf("%d\n", count_flag(format));
	if(format[0] == '%' && format[1] == 'd')
	{
		d = va_arg(ap, int);
		printf("%s\n", "this is decimal");
	}
	if(format[0] == '%' && format[1] == 's')
	{
		p = va_arg(ap, char *);
		printf("%s\n", p);
	}
	va_end(ap);
	return (0);
}
