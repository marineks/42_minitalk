/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:52:58 by msanjuan          #+#    #+#             */
/*   Updated: 2021/09/06 14:06:54 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putnbr_dec(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr_dec(n * -1);
	}
	else if (n >= 0 && n > 9)
	{
		ft_putnbr_dec(n / 10);
		ft_putnbr_dec(n % 10);
	}
}
