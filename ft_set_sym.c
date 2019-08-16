/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sym.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:55:17 by oorlov            #+#    #+#             */
/*   Updated: 2019/07/31 16:55:40 by oorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_set_sym(char c, int len)
{
	int		count;
	char	*str;

	str = (char *)malloc(sizeof(char) * len + 1);
	count = 0;
	while (count != len)
	{
		str[count] = c;
		count++;
	}
	str[count] = '\0';
	return (str);
}

char		*char_type_set(char c)
{
	char	*s;

	if (!(s = ft_strnew(1)))
		return (NULL);
	s[0] = c;
	return (s);
}
