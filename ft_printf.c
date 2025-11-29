/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:33:56 by marberge          #+#    #+#             */
/*   Updated: 2025/11/28 18:55:51 by marberge         ###   ########.fr       */
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
	count = ft_parsing_str(str, buffer, args);
	count = write(1, buffer, count);
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	// void	*ptr;
// 	unsigned int	nb;

// 	nb = 756389;
// 	// ptr = NULL;
// 	// printf("--%d--\n", ft_printf(">>%p<<\n", &ptr));
// 	// printf("--%d--\n", printf(">>%p<<\n", &ptr));
// 	printf("%d\n", ft_printf("%X\n", nb));
// 	printf("%d\n", printf("%X\n", nb));
// 	return (0);
// }
// printf("%d\n", ft_printf("toto %s%% et %s tata \n", "HELLO", "MARCO"));
// printf("%d\n", printf("toto %s%% et %s tata \n", "HELLO", "MARCO"));

// printf("%d\n", ft_printf("%%d = %d et %%i = %i et %%u = %u\n", 5, 5, ui));
// printf("%d\n", printf("%%d = %d et %%i = %i et %%u = %u\n", 5, 5, ui));