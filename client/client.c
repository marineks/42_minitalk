/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:15:28 by msanjuan          #+#    #+#             */
/*   Updated: 2021/09/06 18:59:00 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	convertCharToBits(int pid, char c)
{
	int bit_index;
	bit_index = 7;
	while (bit_index >= 0)
	{
		if (c & (1 << bit_index))
		{
			if (kill(pid, SIGUSR2) == SUCCESS)
			{
				write(1, "Signal '1' envoyé\n", 19);
				usleep(100);
			}
			else
				write(1, "KO.\n", 3);
		}	
		else
		{
			if (kill(pid, SIGUSR1) == SUCCESS)
			{
				write(1, "Signal '0' envoyé\n", 19);
				usleep(100);
			}
			else
				write(1, "KO.\n", 3);
		}
		bit_index--;
	}
}


int main(int argc, char **argv) 
{

	if (argc == 3)
	{
		int pid = ft_atoi(argv[1]);
		// signal(SIGUSR1, reception_handler);
		char *strToSend = argv[2];
		int i = 0;

		while (strToSend[i])
		{
			convertCharToBits(pid, strToSend[i]);
			i++;
		}
	}
	
	return (0);
}