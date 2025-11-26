/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:11:15 by marberge          #+#    #+#             */
/*   Updated: 2025/11/26 17:02:53 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_add_to_buffer(char *str, char *buffer, va_list args, int *count)
{
	int	len_buff;
	int	len_str;
	int	i;

	i = 0;
	len_buff = ft_strlen(buffer);
	len_str = ft_strlen(str);
	if (len_buff + len_str < 1024)
	{
		while (str[i])
		{
			buffer[*count] = str[i];
			i++;
		}
		*count += i;
		len_buff++;
	}
}

int	ft_add_char(char *buffer, char char_to_add, int *index)
{
	int	len;

	len = ft_strlen(buffer);
	if (len + 1 < 1024)
	{
		buffer[*index] = char_to_add;
		*index += 1;
	}
	return (1);
}
