/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:33:56 by marberge          #+#    #+#             */
/*   Updated: 2025/11/25 18:15:09 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	char_count;
	char	buffer[1024];
	int	i;

	i = 0;
	while (str[i])
	{

	}
	va_start(args, str);
	printf("%d - %c - %d\n", va_arg(args, int), va_arg(args, int), va_arg(args, int));
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("toto", 2, 'g', 30);
	return (0);
}
