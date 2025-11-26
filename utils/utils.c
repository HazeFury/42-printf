/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:40:34 by marberge          #+#    #+#             */
/*   Updated: 2025/11/26 16:31:53 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_parsing_str(const char *str, char *buffer, va_list args, int *count)
{
	int	i;
	int	res;
	
	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_is_sign(str[i + 1]) == 1)
		{
			res += ft_manage_sign(str[i + 1], buffer, args, count);
			i += 2;
		}
		else
		{
			buffer[*count] = str[i];
			*count += 1;
			i++;
		}
	}
	return (res);
}

int	ft_manage_sign(char c, char *buffer, va_list args, int *count)
{
	int	res;

	res = 0;
	if (c == 'c')
		res = ft_add_char(buffer, va_arg(args, int), count);
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
