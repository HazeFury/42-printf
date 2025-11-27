/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:33:01 by marberge          #+#    #+#             */
/*   Updated: 2025/11/27 12:15:15 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *str, ...);
int		ft_manage_sign(char c, char *buffer, int *buf_index, va_list args);
int		ft_add_char(char *buffer, int *buf_index, char char_to_add);
int		ft_add_to_buffer(char *buffer, int *buf_index, char *str_to_add);
int		ft_parsing_str(const char *str, char *buffer, va_list args);
size_t	ft_strlen(const char *s);
int		ft_is_sign(char c);

#endif
