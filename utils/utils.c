/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:40:34 by marberge          #+#    #+#             */
/*   Updated: 2025/11/26 14:52:00 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_manage_sign(char c, char *buffer, va_list args, size_t *char_count)
{
	if (c == 'c')
		ft_add_char(buffer, va_arg(args, int), char_count);
}

void	ft_add_char(char *buffer, char char_to_add, size_t *char_count)
{
	int	len;

	len = ft_strlen(buffer);
	if (len + 1 < 1024)
	{
		buffer[*char_count] = char_to_add;
		*char_count += 1;
		len++;
	}
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

void	ft_add_to_buffer(char *buffer, va_list args, size_t char_count)
{
	(void)buffer;
	(void)args;
	(void)char_count;
	return ;
}
