/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:33:56 by marberge          #+#    #+#             */
/*   Updated: 2025/11/25 23:11:46 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		char_count;
	char	buffer[1024];
	int		i;

	i = 0;
	char_count = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_is_sign(str[i + 1]) == 1)
		{
			ft_add_to_buffer(buffer, args, char_count);
		}
		buffer[char_count] = str[i];
		char_count++;
		i++;
	}
	write(1, buffer, char_count);
	va_end(args);
	return (char_count);
}

// printf("%d\n", va_arg(args, int));
int	main(void)
{
	ft_printf("toto");
	return (0);
}
