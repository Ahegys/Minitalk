/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelipe- <afelipe->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:57:20 by afelipe-          #+#    #+#             */
/*   Updated: 2023/01/19 15:51:40 by afelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

char	g_wait;

void	handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
		ft_printf("char sended!\n");
	else
		g_wait = 0;
}

void	init(void)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_flags = 0;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

void	sendbit(pid_t pid, char c)
{
	int			i;
	static int	error;

	error = 0;
	i = 0;
	while (i < 8 && error == 0)
	{
		if (!g_wait)
		{
			g_wait = 1;
			if (c & 1)
				error = kill(pid, SIGUSR1);
			else
				error = kill(pid, SIGUSR2);
			c >>= 1;
			i++;
			usleep(5000);
		}
	}
	if (error)
		exit(1);
}

int	main(int ac, char *av[])
{
	char	*str;
	pid_t	pid;
	size_t	i;

	i = 0;
	g_wait = 0;
	init();
	if (ac != 3)
		return (ft_printf("./client <process_id> <msg>!\n"));
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (ft_printf("Invalid PID!\n"));
	str = av[2];
	while (str[i] != '\0')
	{
		sendbit(pid, str[i]);
		i++;
	}
	sendbit(pid, '\n');
	exit(0);
	while (1)
		pause();
	return (0);
}
