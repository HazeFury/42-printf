/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:33:56 by marberge          #+#    #+#             */
/*   Updated: 2025/11/26 16:28:35 by marberge         ###   ########.fr       */
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
	int		check_err;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	count = ft_parsing_str(str, buffer, args);
	check_err = write(1, buffer, count);
	va_end(args);
	return (count);
}

int	main(void)
{
	printf("toto %c et %c tata \n", 'A', 'U');
	// printf("%d\n", ft_printf("toto %c et %c tata\n", 'A', 'U'));
	// printf("%d\n", printf("toto %c et %c tata\n", 'A', 'U'));
	return (0);
}
