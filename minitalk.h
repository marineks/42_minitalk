/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:37:12 by msanjuan          #+#    #+#             */
/*   Updated: 2021/09/09 16:12:52 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define ERROR -1
# define SUCCESS 0

# ifdef __MACH__
#  define TIME 100
# elif __APPLE__
#	define TIME 100
# elif __linux__
#  define TIME 400
# endif

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>

typedef struct	s_data_stock
{
    int pid;
    char c;
	int bit_index;
}				t_data_stock;


// UTILS.C SERVER
void	ft_putnbr_dec(int n);
void	ft_putchar(char c);
int		ft_pow(int nb, int power);
void	print_pid();
// UTILS.C CLIENT
int		ft_atoi(const char *str);
#endif