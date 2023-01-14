#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
		ft_printf("sended!\n");
}

void init()
{
	struct sigaction sa;

	bzero(&sa,sizeof (sa));
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

void	process(pid_t pid, char *msg)
{
	ft_printf("%s\n", msg);
	kill (pid, SIGUSR1);
//	kill (pid, SIGUSR2);
}

int main(int ac, char *av[])
{
	pid_t pid;
	init();
	if (ac != 3)
		ft_printf("./client <process_id> <msg>!\n");
	pid = ft_atoi(av[1]);
	process(pid, av[2]);
	while (1)
		pause();
	return (0);
}
