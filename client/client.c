/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:15:28 by msanjuan          #+#    #+#             */
/*   Updated: 2021/09/08 14:13:31 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	convertCharToBits(int pid, char c)
{
	int	bit_index;

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

int	main(int argc, char **argv)
{
	int		pid;
	char	*strToSend;
	int		i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		strToSend = argv[2];
		i = 0;
		while (strToSend[i])
			convertCharToBits(pid, strToSend[i++]);
		write(1, "Message received by the server\n\n", 32);
	}
	else if (argc == 1)
		write(1, "Please fill in the PID and the string to be sent.\n", 50);
	else if (argc == 2)
		write(1, "Please type a string of characters to send to the server.\n",
			58);
	else
		write(1, "This program only accepts 2 arguments (PID + string)\n", 82);
	return (0);
}
