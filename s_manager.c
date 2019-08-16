/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_manager.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 03:57:55 by oorlov            #+#    #+#             */
/*   Updated: 2019/07/31 03:57:56 by oorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_type(char c)
{
	int		i;
	char	*types;

	i = 0;
	types = "sSpdDioOuUxXcC%";
	while (types[i])
	{
		if (types[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		is_flag(char c)
{
	int		i;
	char	*flags;

	i = 0;
	flags = "+-#0 ";
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		is_modifier(char c)
{
	int		i;
	char	*modifiers;

	i = 0;
	modifiers = "hljz";
	while (modifiers[i])
	{
		if (modifiers[i] == c)
			return (1);
		i++;
	}
	return (0);
}
