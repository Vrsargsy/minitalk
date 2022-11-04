/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:08:25 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/14 16:08:28 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(pid_t pid)
{
	char	l;

	if (pid < 0)
	{
		write(1, "-", 1);
		pid *= -1;
	}
	if (pid >= 10)
		ft_putnbr(pid / 10);
	l = '0' + (pid % 10);
	write(1, &l, 1);
}

void	sigrcv(int sig)
{
	static unsigned char	c = 0;
	static int				count = 0;

	c = c << 1;
	++count;
	if (sig == SIGUSR1)
		c = c | 1;
	if (count == 8)
	{
		write(1, &c, 1);
		count = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = &sigrcv;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	write(1, "SERVER PID : ", 14);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
}
