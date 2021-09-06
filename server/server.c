/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:15:34 by msanjuan          #+#    #+#             */
/*   Updated: 2021/09/06 15:27:52 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void reception_handler()
{
	// if (signal == SIGUSR1)
		write(1, "Received SIGUSR1!\n", 18);
}

int main(void)
{
	int pid = getpid();

	write(1, "ID : ", 5);
	ft_putnbr_dec(pid);
	write(1, "\n", 1);
	

	while (1)
	{
		struct sigaction sa;
		sa.sa_handler = reception_handler;

		sigaction(SIGUSR1, &sa, NULL);
	}
		
	return (0);
}
