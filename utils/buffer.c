/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:11:15 by marberge          #+#    #+#             */
/*   Updated: 2025/11/28 12:30:50 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

int	ft_add_to_buffer(char *buffer, int *buf_index, char *str_to_add)
{
	int	len_buff;
	int	len_str_to_add;
	int	i;

	i = 0;
	len_buff = ft_strlen(buffer);
	len_str_to_add = ft_strlen(str_to_add);
	if (len_buff + len_str_to_add >= 1024)
		ft_flush_buffer(buffer, buf_index);
	while (str_to_add[i])
	{
		buffer[*buf_index] = str_to_add[i];
		i++;
		*buf_index += 1;
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

int	ft_add_number(char *buffer, int *buf_index, int nb)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	if (!str)
		return (0);
	len = ft_add_to_buffer(buffer, buf_index, str);
	free(str);
	return (len);
}

int	ft_add_adress(char *buffer, int *buf_index, void *ptr, int is_lowercase)
{
	char			*str;
	int				len;
	unsigned long	ptr_as_ulong;

	ptr_as_ulong = (unsigned long)ptr;
	str = ft_itoa_base(ptr_as_ulong, is_lowercase);
	if (!str)
		return (0);
	len = ft_add_to_buffer(buffer, buf_index, "0x");
	len += ft_add_to_buffer(buffer, buf_index, str);
	free(str);
	return (len);
}

int	ft_add_hexa(char *buffer, int *buf_index, int nb, int is_lowercase)
{
	char			*str;
	int				len;
	unsigned long	int_as_ulong;

	int_as_ulong = (unsigned long)nb;
	str = ft_itoa_base(int_as_ulong, is_lowercase);
	if (!str)
		return (0);
	len = ft_add_to_buffer(buffer, buf_index, str);
	free(str);
	return (len);
}
