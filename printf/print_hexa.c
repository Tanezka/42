/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:33:07 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/03/08 18:14:27 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
void checker (va_list input, char *base, unsigned long long *num, int mod)
{
	va_list copy;
	
	va_copy(copy, input);
	if (va_arg(copy, int) < 0 && ft_strlen(base) == 10 && mod == 0)
	{
		write(1, "-",1);
		*num = (-1 * va_arg(input, int));
	}
	else
		*num = va_arg(input, unsigned long long);
}

void	print_hexa(va_list input, int *input_len, char *base, int mod)
{
	char		*new;
	unsigned long long	num;
	unsigned long long	digit;
	unsigned long long	baser;
	
	digit = 1;
	baser = ft_strlen(base);
	checker (input, base, &num, mod);
	while ((num / baser) != 0)
	{
		digit++;
		baser *= ft_strlen(base);
	}
	baser /= ft_strlen(base);
	new = ft_calloc(digit, sizeof(char));
	while (*input_len < (int)digit)
	{
		new[(*input_len)++] = base[num / baser];
		num -= baser * (num / baser);
		baser /= ft_strlen(base);
	}
	print_str(new, input_len);
	free(new);
}
