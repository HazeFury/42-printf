/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:33:56 by marberge          #+#    #+#             */
/*   Updated: 2025/11/27 12:51:58 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	char	buffer[1024];
	int		i;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	count = ft_parsing_str(str, buffer, args);
	count = write(1, buffer, count);
	va_end(args);
	return (count);
}

int	main(void)
{
	printf("%d\n", ft_printf("toto %s%% et %s tata \n", "HELLO", "MARCO"));
	printf("%d\n", printf("toto %s%% et %s tata \n", "HELLO", "MARCO"));
	return (0);
}
