/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:15:28 by msanjuan          #+#    #+#             */
/*   Updated: 2021/09/08 11:24:10 by msanjuan         ###   ########.fr       */
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
			if (kill(pid, SIGUSR1) == SUCCESS)
				usleep(100);
			else
				write(1, "Kill function failed\n", 21);
		}	
		else
		{
			if (kill(pid, SIGUSR2) == SUCCESS)
				usleep(100);
			else
				write(1, "Kill function failed\n", 21);
		}
		bit_index--;
	}
}

int main(int argc, char **argv) 
{
	if (argc == 3)
	{
		int pid = ft_atoi(argv[1]);
		char *strToSend = argv[2];
		int i = 0;

		while (strToSend[i])
			convertCharToBits(pid, strToSend[i++]);
		write(1, "Message envoyé\n\n", 16);
	}
	else if (argc == 1)
		write(1, "Please fill in the PID and the string you want to send.\n", 56);
	else if (argc == 2)
		write(1, "Please type a string of characters to send to the server.\n", 58);
	else
		write(1, "This program only accepts two arguments: the server's PID and the string to send.\n", 82);
	return (0);
}