#include "minitalk.h"

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

void	send_fin(pid_t pid)
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

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "Message sent\n", 13);
	exit(0);
}

int main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	if (ac != 3)
		exit(1);
	i = 0;
	signal(SIGUSR1, sig_handler);
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		send_signal(av[2][i], pid);
		i++;
	}
	send_fin(pid);
	while(1)
	{
		pause();
	}
	return (0);
}

// 演算子	 記述例			  意味
// &		a = b & 0x4F	ビットAND
// |		a = b | 0x0F	ビットOR
// ^		a = b ^ 0xFF	ビットXOR
// ~		a = ~a			ビットNOT
// <<=		a = a << 2		左シフト
// >>=		a = a >> 2		右シフト
