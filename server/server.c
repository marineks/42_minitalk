/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:15:34 by msanjuan          #+#    #+#             */
/*   Updated: 2021/09/13 15:30:03 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	convert_bin_to_char(int *bin_array)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < 8)
	{
		if (bin_array[i] == 1)
			result += ft_pow(2, (7 - i));
		i++;
	}
	write(1, &result, 1);
}

void	reception_handler(int signal)
{
	static int	stock[8];
	static int	i = 0;

	if (signal == SIGUSR1)
		stock[i] = 1;
	else if (signal == SIGUSR2)
		stock[i] = 0;
	i++;
	if (i == 8)
	{
		convertBintoChar(stock);
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = reception_handler;
	sa.sa_flags = 0;
	print_pid();
	if (sigaction(SIGUSR1, &sa, NULL) == ERROR)
		write(1, "Reception of the signal failed\n", 31);
	if (sigaction(SIGUSR2, &sa, NULL) == ERROR)
		write(1, "Reception of the signal failed\n", 31);
	while (1)
	{
		pause();
	}
	return (0);
}
