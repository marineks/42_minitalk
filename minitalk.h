/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:37:12 by msanjuan          #+#    #+#             */
/*   Updated: 2021/09/08 12:05:23 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define ERROR -1
# define SUCCESS 0

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>

// UTILS.C SERVER
void	ft_putnbr_dec(int n);
void	ft_putchar(char c);
int		ft_pow(int nb, int power);
// UTILS.C CLIENT
int		ft_atoi(const char *str);
#endif