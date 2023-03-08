/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_s_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:44:22 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/03/08 16:57:52 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void	print_char(char c, int *input_len)
{
	write(1, &c, 1);
	*input_len = 1;
}

void	print_num(int num, int *input_len)
{
	int		len;
	char	*str;

	*input_len = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	len = ft_strlen((ft_itoa(num)));
	str = ft_calloc(len - 1, sizeof(char));
	str = ft_itoa(num);
	while (len-- != 0 && ft_isdigit(str[*input_len]) == 1)
	{
		write(1, &str[*input_len], 1);
		(*input_len)++;
	}
	free(str);
}

void	print_str(char *str, int *input_len)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		*input_len = 6;
		return ;
	}
	len = (int)ft_strlen(str);
	*input_len = 0;
	while (len-- != 0)
	{
		write(1, &str[*input_len], 1);
		(*input_len)++;
	}
}
