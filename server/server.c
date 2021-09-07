/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:15:34 by msanjuan          #+#    #+#             */
/*   Updated: 2021/09/07 13:50:10 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	convertBintoChar(int *bin_array)
{
	int pos[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	int i = 0;
	int result = 0;

	while (i < 8)
	{
		if (bin_array[i] == 1)
			result += pos[i];
		i++;
	}
	putchar(result);
}
void reception_handler(int signal)
{
	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		char *buf;
		int i;
		
		buf = malloc(sizeof(char) * 9);
		if (!buf)
			return;
			
		i = 0;
		while (i <= 8)
		{
			if (signal == SIGUSR1)
			{
				write(1, "1", 1);
				buf[i] = '1';
			}
				
			else if (signal == SIGUSR2)
			{
				write(1, "0", 1);
				buf[i] = '0';
			}
			i++;
		}
		buf[i] = '\0';
		write(1, &buf, 9);
		free(buf);
	}
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
