/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:40:34 by marberge          #+#    #+#             */
/*   Updated: 2025/12/01 14:05:59 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
			res += ft_add_char(buffer, &buf_index, str[i++]);
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
	if (c == 'd' || c == 'i')
		res = ft_add_number(buffer, buf_index, va_arg(args, int));
	if (c == 'u')
		res = ft_add_unsigned_nb(buffer, buf_index, va_arg(args, unsigned int));
	if (c == 'p')
		res = ft_add_adress(buffer, buf_index, va_arg(args, void *), 1);
	if (c == 'x')
		res = ft_add_hexa(buffer, buf_index, va_arg(args, unsigned int), 1);
	if (c == 'X')
		res = ft_add_hexa(buffer, buf_index, va_arg(args, unsigned int), 0);
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

int	ft_add_unsigned_nb(char *buffer, int *buf_index, unsigned int nb)
{
	char	*str;
	int		len;

	str = ft_unsigned_itoa(nb);
	if (!str)
		return (0);
	len = ft_add_to_buffer(buffer, buf_index, str);
	free(str);
	return (len);
}

int	ft_flush_buffer(char *buffer, int *buf_index)
{
	int	count;

	count = write(1, buffer, *buf_index);
	if (count == -1)
		return (count);
	ft_bzero(buffer, 1024);
	*buf_index = 0;
	return (0);
}
