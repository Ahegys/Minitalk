#include "minitalk.h"
# include <unistd.h>

void	handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
		ft_printf("sended!\n");
}
void init()
{
	struct sigaction sa;

	ft_bzero(&sa,sizeof (sa));
	sa.sa_flags = 0;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

void	putstr(char *c)
{
	while (*c)
		{
			write(1, c, 1);
			c++;
	}
}

void printbit(pid_t pid, char c)
{
  int i;
  
  i = 128;
  while (i)
  {
    if (c & (1 << 7))
	  kill (pid, SIGUSR1);
    else
	  kill (pid, SIGUSR2);
    c <<= 1;
    i >>= 1;
	usleep(100);
  }
}

int main(int ac, char *av[])
{
	int i;
	char *str;	
	i = 0;
	pid_t pid;
	init();
	if (ac != 3)
		ft_printf("./client <process_id> <msg>!\n");
	pid = ft_atoi(av[1]);
	str = av[2];
	while (str[i])
	{
		printbit(pid, str[i]);
		i++;
	}
	while (1)
		pause();
	return (0);
}
