#include "minitalk.h"

static int BIT;

void	putstr(char *c)
{
	while (*c)
		{
			write(1, c, 1);
			c++;
	}
}
void	signal_handle(int signum, siginfo_t *info, void *context)
{
	static char temp;

	if (BIT <= 8)
	{
		if (signum == SIGUSR1)
			temp += 1 << BIT;
		if (signum == SIGUSR2)
			temp += 0 << BIT;
		BIT++;
	}
	if (BIT == 8)
	{
		write(1, &temp, 1);
		temp = '\0';
		BIT = 0;
		kill (info->si_pid, SIGUSR1);
	}
	
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
