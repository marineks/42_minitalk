/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:15:28 by msanjuan          #+#    #+#             */
/*   Updated: 2021/08/10 17:08:38 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int main(int argc, char **argv)
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
		
	// }
	return (0);
}

/* 

Kill command : ne sert pas qu'à tuer, permet de faire differentes actions,
comme envoyer un signal
PID = process id



*/