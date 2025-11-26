/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:33:56 by marberge          #+#    #+#             */
/*   Updated: 2025/11/26 14:50:48 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	char_count;
	char	buffer[1024];
	int		i;
	int		check_err;

	i = 0;
	char_count = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_is_sign(str[i + 1]) == 1)
		{
			ft_manage_sign(str[i + 1], buffer, args, &char_count);
			i += 2;
		}
		else
		{
			buffer[char_count] = str[i];
			char_count++;
			i++;
		}
	}
	check_err = write(1, buffer, char_count);
	va_end(args);
	return (char_count);
}

int	main(void)
{
	ft_printf("toto %c et %c tata\n", 'A', 'U');
	return (0);
}
