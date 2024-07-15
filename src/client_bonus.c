#include "minitalk_bonus.h"

static void	send_signal(int c, pid_t pid)
{
	int	i;
	int	ret;

	i = 0;
	while (i < 8)
	{
		if ((c & 1) == 0)
		{
			ret = kill(pid, SIGUSR1);
			if (ret < 0)
				exit(1);
		}
		else
		{
			ret = kill(pid, SIGUSR2);
			if (ret < 0)
				exit(1);
		}
		c >>= 1;
		i++;
		usleep(100);
	}
}

static void	send_fin(pid_t pid)
{
	int	ret;
	int	i;

	i = 8;
	while (i--)
	{
		ret = kill(pid, SIGUSR1);
		if (ret < 0)
			exit(1);
	}
}

static void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "Message sent\n", 13);
	exit(0);
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	if (ac != 3)
		exit(1);
	i = 0;
	if (signal(SIGUSR1, sig_handler) == SIG_ERR)
		exit(1);
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		send_signal(av[2][i], pid);
		i++;
	}
	send_fin(pid);
	while (1)
	{
		pause();
	}
	return (0);
}
