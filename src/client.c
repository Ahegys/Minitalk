#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
	{
		ft_printf("sended!\n");
		exit(1);
	}
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

void	process(pid_t pid, char *string)
{
 	int i;
    int j;
    
    i = 0;
    while (string[i] != '\0')
    {
      printf("]%c[\n", string[i]);
      j = 7;
      while (j >= 0)
      {
        if (string[i] & (1 << j))
		{	kill (pid, SIGUSR1);
			ft_printf("1");
		}
        else
		{
			ft_printf("0");
          kill (pid, SIGUSR2);
		}
		ft_printf("\n");
       j--; 
      }
      i++;
      printf("\n");
    }
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
