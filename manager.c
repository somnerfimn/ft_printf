/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 03:51:47 by oorlov            #+#    #+#             */
/*   Updated: 2019/07/31 03:51:48 by oorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		alpha_type(t_arg *arg)
{
	int		i;
	char	*types;

	i = 0;
	types = "sScCp";
	while (types[i])
	{
		if (types[i] == arg->type)
			return (1);
		i++;
	}
	return (0);
}

int		char_type(t_arg *arg)
{
	return (arg->type == 'c' || arg->type == 'C');
}

int		string_type(t_arg *arg)
{
	return (arg->type == 's' || arg->type == 'S');
}

int		point_type(t_arg *arg)
{
	return (arg->type == 'p');
}

int		percent_type(t_arg *arg)
{
	return (arg->type == '%');
}
