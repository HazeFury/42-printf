/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:21:59 by marberge          #+#    #+#             */
/*   Updated: 2025/11/28 11:50:59 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	ft_count_len(unsigned long n)
{
	int	size;

	size = 1;
	if (n < 16)
		return (size);
	while (n / 16 > 0)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(unsigned long n)
{
	char	*str;
	int		len;
	char	*base;	

	base = "0123456789abcdef";
	len = ft_count_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[len--] = base[n % 16];
		n = n / 16;
	}
	return (str);
}
