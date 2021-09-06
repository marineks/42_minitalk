/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:15:28 by msanjuan          #+#    #+#             */
/*   Updated: 2021/09/06 14:54:51 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int main(int argc, char **argv) 
{

	if (argc == 2)
	{
		int pid = ft_atoi(argv[1]);
		// signal(SIGUSR1, reception_handler);
		if (kill(pid, SIGUSR1) == SUCCESS)
			write(1, "Signal envoyé\n", 15);
		else
			write(1, "KO.\n", 3);
		// pause();
	}
	
	return (0);
}