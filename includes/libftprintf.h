/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:33:01 by marberge          #+#    #+#             */
/*   Updated: 2025/11/27 13:16:09 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_manage_sign(char c, char *buffer, int *buf_index, va_list args);
int		ft_add_char(char *buffer, int *buf_index, char char_to_add);
int		ft_add_to_buffer(char *buffer, int *buf_index, char *str_to_add);
int		ft_add_number(char *buffer, int *buf_index, int nb);
int		ft_parsing_str(const char *str, char *buffer, va_list args);
int		ft_is_sign(char c);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);

#endif
