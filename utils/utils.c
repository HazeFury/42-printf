/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:40:34 by marberge          #+#    #+#             */
/*   Updated: 2025/11/27 12:52:36 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_parsing_str(const char *str, char *buffer, va_list args)
{
	int	i;
	int	buf_index;
	int	res;

	i = 0;
	buf_index = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_is_sign(str[i + 1]) == 1)
		{
			res += ft_manage_sign(str[i + 1], buffer, &buf_index, args);
			i += 2;
		}
		else
		{
			buffer[buf_index] = str[i];
			buf_index += 1;
			i++;
			res += 1;
		}
	}
	return (res);
}

int	ft_manage_sign(char c, char *buffer, int *buf_index, va_list args)
{
	int	res;

	res = 0;
	if (c == 'c')
		res = ft_add_char(buffer, buf_index, va_arg(args, int));
	if (c == 's')
		res = ft_add_to_buffer(buffer, buf_index, va_arg(args, char *));
	if (c == '%')
		res = ft_add_char(buffer, buf_index, '%');
	return (res);
}

int	ft_is_sign(char c)
{
	char	*signs;
	int		i;

	i = 0;
	signs = "cspdiuxX%%";
	while (signs[i])
	{
		if (signs[i] == c)
			return (1);
		i++;
	}
	return (0);
}
