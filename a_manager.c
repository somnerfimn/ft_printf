/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_manager.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oorlov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 03:53:17 by oorlov            #+#    #+#             */
/*   Updated: 2019/07/31 03:53:18 by oorlov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	*new_arg(void)
{
	t_arg	*new;
	t_value	*new_value;

	if (!(new = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	if (!(new_value = (t_value *)malloc(sizeof(t_value))))
		return (NULL);
	new->value = new_value;
	new->type = '\0';
	new->flag = NULL;
	new->f_width = 0;
	new->prec = -1;
	new->modifier = NULL;
	return (new);
}

void	free_arg(t_arg *arg)
{
	ft_memdel((void **)&(arg->value));
	ft_strdel(&(arg->modifier));
	free_flags(arg);
	ft_memdel((void **)&arg);
}

t_buff	*new_buff(void)
{
	t_buff	*buffer;

	if (!(buffer = (t_buff *)malloc(sizeof(t_buff))))
		return (NULL);
	buffer->buff = NULL;
	buffer->buff_size = 0;
	buffer->value = NULL;
	buffer->v_size = 0;
	buffer->sup = NULL;
	buffer->sup_size = 0;
	buffer->sup_pos = 0;
	buffer->arg_offset = 0;
	buffer->resized_value = 0;
	return (buffer);
}

void	free_buff(t_buff *buffer)
{
	ft_memdel((void **)&(buffer->buff));
	ft_memdel((void **)&(buffer->value));
	ft_memdel((void **)&(buffer));
}
