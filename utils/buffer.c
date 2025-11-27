/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:11:15 by marberge          #+#    #+#             */
/*   Updated: 2025/11/27 12:13:52 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_add_to_buffer(char *buffer, int *buf_index, char *str_to_add)
{
	int	len_buff;
	int	len_str_to_add;
	int	i;

	i = 0;
	len_buff = ft_strlen(buffer);
	len_str_to_add = ft_strlen(str_to_add);
	if (len_buff + len_str_to_add < 1024)
	{
		while (str_to_add[i])
		{
			buffer[*buf_index] = str_to_add[i];
			i++;
			*buf_index += 1;
		}
	}
	return (len_str_to_add);
}

int	ft_add_char(char *buffer, int *buf_index, char char_to_add)
{
	int	len;

	len = ft_strlen(buffer);
	if (len + 1 < 1024)
	{
		buffer[*buf_index] = char_to_add;
		*buf_index += 1;
	}
	return (1);
}
