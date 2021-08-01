#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/libft.h"
#define BUFFER_SIZE 1000

void	ft_print_char(int sig, int *i, int *pid, siginfo_t *st_siginfo)
{
	static int		bit = 0;
	static int		count = 0;
	static char		str_bit[BUFFER_SIZE + 1];

	bit = bit + ((sig == SIGUSR1) << count);
	count++;
	if (count == 8)
	{
		str_bit[++(*i)] = (char)bit;
		if (bit == '\0' || *i >= BUFFER_SIZE)
		{
			if (*i >= 0)
				if (bit == '\0')
					*i = *i + 1;
			write(1, str_bit, *i);
			*i = -1;
			if (bit == '\0')
			{
				*pid = 0;
				kill(st_siginfo->si_pid, SIGUSR1);
			}
		}
		bit = 0;
		count = 0;
	}
}

void	ft_server(int sig, siginfo_t *st_siginfo, void *context)
{
	static int		i = -1;
	static pid_t	pid = 0;

	if (pid == 0)
		pid = st_siginfo->si_pid;
	else if (pid != st_siginfo->si_pid)
	{
		kill(st_siginfo->si_pid, SIGUSR2);
		sleep(2);
		pid = 0;
		i = -1;
		return ;
	}
	ft_print_char(sig, &i, &pid, st_siginfo);
	(void)context;
}

void	ft_success_sigact(struct sigaction *st_sigact)
{
	if (sigaction(SIGUSR1, st_sigact, NULL) < 0)
		exit(1);
	if (sigaction(SIGUSR2, st_sigact, NULL) < 0)
		exit(1);
}

int	main(void)
{
	struct sigaction	st_sigact;
	pid_t				pid;

	pid = getpid();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	sigemptyset(&st_sigact.sa_mask);
	st_sigact.sa_sigaction = ft_server;
	st_sigact.sa_flags = SA_SIGINFO;
	ft_success_sigact(&st_sigact);
	while (1)
		pause();
	return (0);
}
