/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:15:34 by msanjuan          #+#    #+#             */
/*   Updated: 2021/08/11 18:14:10 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void reception_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		write(1, "Received SIGUSR1!\n", 18);
	}
}

int main(void) //int argc, char **argv
{
	int pid = getpid();
	printf("coucou cest l'id : %d\n", pid);
	// if (pid == -1)
	// 	return (ERROR);
	// if (pid == 0)
	// {
	// 	// Child process
	// 	usleep(600);
	// 	// kill(getpid(), SIGUSR1);
	// } else {
	// 	// Parent process
	// 	printf("coucou cest l'id : %d\n", pid);
	signal(SIGUSR1, reception_handler);
	// }
	kill(pid, SIGUSR1);
	usleep(1600);

	
	
	return (0);
}