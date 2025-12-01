/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:33:56 by marberge          #+#    #+#             */
/*   Updated: 2025/12/01 12:42:37 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

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
	ft_bzero(buffer, 1024);
	count = ft_parsing_str(str, buffer, args);
	count = write(1, buffer, count);
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	// void	*ptr;
// 	unsigned int	nb;

// 	nb = -756389;
// 	// ptr = NULL;
// 	// printf("--%d--\n", ft_printf(">>%p<<\n", &ptr));
// 	// printf("--%d--\n", printf(">>%p<<\n", &ptr));
// 	printf("%d\n", ft_printf(" %p %p ", (void *)0, (void *)0));
// 	printf("%d\n", printf(" %p %p ", (void *)0, (void *)0));
// 	return (0);
// }
// printf("%d\n", ft_printf("toto %s%% et %s tata \n", "HELLO", "MARCO"));
// printf("%d\n", printf("toto %s%% et %s tata \n", "HELLO", "MARCO"));

// printf("%d\n", ft_printf("%%d = %d et %%i = %i et %%u = %u\n", 5, 5, ui));
// printf("%d\n", printf("%%d = %d et %%i = %i et %%u = %u\n", 5, 5, ui));