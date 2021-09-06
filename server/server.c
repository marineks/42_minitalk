/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:15:34 by msanjuan          #+#    #+#             */
/*   Updated: 2021/09/06 18:56:15 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void reception_handler(int signal)
{
	if (signal == SIGUSR2)
		write(1, "1", 1);
	else if (signal == SIGUSR1)
		write(1, "0", 1);
}

int main(void)
{
	int pid = getpid();
	struct sigaction sa;
	sa.sa_handler = reception_handler;

	write(1, "ID : ", 5);
	ft_putnbr_dec(pid);
	write(1, "\n", 1);
	
	while (1)
	{	
		if (sigaction(SIGUSR1, &sa, NULL) == ERROR)
			write(1, "KO\n", 3);
		if (sigaction(SIGUSR2, &sa, NULL) == ERROR)
			write(1, "KO\n", 3);
	}
	return (0);
}
