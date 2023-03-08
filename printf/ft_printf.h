/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:12:31 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/03/08 18:05:00 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

void	print_hexa(va_list input, int *input_len, char *base, int mod);

void	print_unsigned_decimal(long long num, int *input_len);

void	print_char(char c, int *input_len);

void	print_num(int num, int *input_len);

void	print_str(char *str, int *input_len);

void	type_def(va_list input, const char *type, int *input_len, int *input_len2);

int		ft_printf(const char *type, ...);

#endif
