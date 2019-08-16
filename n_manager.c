/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_manager.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 03:56:51 by oorlov            #+#    #+#             */
/*   Updated: 2019/07/31 03:56:52 by oorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		num_type(t_arg *arg)
{
	int		i;
	char	*types;

	i = 0;
	types = "dDioOuUxX";
	while (types[i])
	{
		if (types[i] == arg->type)
			return (1);
		i++;
	}
	return (0);
}

int		int_type(t_arg *arg)
{
	return (arg->type == 'd' || arg->type == 'D' || arg->type == 'i');
}

int		uint_type(t_arg *arg)
{
	return (arg->type == 'u' || arg->type == 'U');
}

int		hex_type(t_arg *arg)
{
	return (arg->type == 'x' || arg->type == 'X');
}

int		oct_type(t_arg *arg)
{
	return (arg->type == 'o' || arg->type == 'O');
}
