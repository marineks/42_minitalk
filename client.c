/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:15:28 by msanjuan          #+#    #+#             */
/*   Updated: 2021/08/11 18:11:52 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// signal handler pour reception:
void reception_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		write(1, "Received SIGUSR1!\n", 18);
	}
}

int main(void) //int argc, char **argv
{
	signal(SIGUSR1, reception_handler);
	raise(SIGUSR1);
	// pause();
	return (0);
}

/* 

Kill command : ne sert pas qu'à tuer, permet de faire differentes actions,
comme envoyer un signal
PID = process id



*/