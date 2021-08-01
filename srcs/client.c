#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/libft.h"

void	ft_success_massage(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("OK: String sent and received\n", 1);
	if (sig == SIGUSR2)
		ft_putstr_fd("KO: error pid\n", 1);
	exit(1);
}

void	ft_message(pid_t pid, char c)
{
	int	count;
	int	bit;

	count = -1;
	while (++count < 8)
	{
		bit = (c >> count) & 1;
		if (bit == 1)
			bit = kill(pid, SIGUSR1);
		else
			bit = kill(pid, SIGUSR2);
		if (bit == -1)
		{
			ft_putstr_fd("KO: Error: not sent and not received", 1);
			exit(1);
		}
		usleep(100);
	}
}

void	ft_client(char **av)
{
	pid_t	pid;
	int		i;

	i = -1;
	pid = (pid_t)ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("KO: error PID\n", 1);
		return ;
	}
	while (av[2][++i] != '\0')
		ft_message(pid, av[2][i]);
	ft_message(pid, av[2][i]);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (signal(SIGUSR1, ft_success_massage) == SIG_ERR)
			return (1);
		if (signal(SIGUSR2, ft_success_massage) == SIG_ERR)
			return (1);
		ft_client(av);
	}
	else
		ft_putstr_fd("KO: error number of arguments\n", 1);
}
