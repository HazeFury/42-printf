/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:33:01 by marberge          #+#    #+#             */
/*   Updated: 2025/11/26 14:50:56 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *str, ...);
int		ft_is_sign(char c);
void	ft_add_to_buffer(char *buffer, va_list args, size_t char_count);
size_t	ft_strlen(const char *s);
void	ft_manage_sign(char c, char *buffer, va_list args, size_t *char_count);
void	ft_add_char(char *buffer, char char_to_add, size_t *char_count);

#endif
