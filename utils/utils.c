/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:40:34 by marberge          #+#    #+#             */
/*   Updated: 2025/11/25 23:23:10 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_add_to_buffer(char *buffer, va_list args, size_t char_count)
{
	(void)buffer;
	(void)args;
	(void)char_count;
	return ;
}

int	ft_is_sign(char c)
{
	char	*signs;
	int		i;

	i = 0;
	signs = "cspdiuxX%";
	while (signs[i])
	{
		if (signs[i] == c)
			return (1);
		i++;
	}
	return (0);
}
