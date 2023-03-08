/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:39:08 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/03/08 17:54:21 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void	print_unsigned_decimal(long long num, int *input_len)
{
	unsigned int	final;
	char			*str;
	int				digit;
	
	final = 4294967295 + num + 1;
	digit = 0;
	while ((final / 10) > 0)
	{
		digit++;
		final /= 10;
	}
	final = 4294967295 + num + 1;
	str = (char *)malloc(digit * sizeof(char));
	while (digit >= 0)
	{
		ft_memcpy(&str[digit], &ft_itoa(final % 10)[0], 1);
		final = final / 10;
		digit--;
	}
	while (str[++digit] && digit <= 10)
		write(1, &str[digit], 1);
	*input_len = digit;
	free (str);
}
