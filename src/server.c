#include "minitalk.h"

void	signal_handle(int signum, siginfo_t *info, void *context)
{
	pid_t pid;
	(void)context;
	
	usleep(1000);
	if (signum == SIGUSR1)
		ft_printf("1");
	if (signum == SIGUSR2)
		ft_printf("0");
	ft_printf("\n");
	pid = info->si_pid;
	kill(pid, SIGUSR1);
}

void init(void)
{
	struct sigaction sa;
	
	bzero(&sa, sizeof(sa));
	sa.sa_sigaction = signal_handle;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int main(void)
{
	init();

	ft_printf("server process = [%d]\n", getpid());
	while (1)
		pause();
	return (0);
}
