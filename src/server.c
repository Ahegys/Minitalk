#include "minitalk.h"

void	signal_handle(int signum, siginfo_t *info, void *context)
{

	if (signum == SIGUSR1)
		ft_printf("1\n");
	if (signum == SIGUSR2)
		ft_printf("0\n");
	(void)context;
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
