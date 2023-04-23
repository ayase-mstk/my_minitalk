#include "client.h"

void	send_signal(int c, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		i++;
		usleep(100);
	}
}

int main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	if (ac != 3)
		exit(1);
	i = 0;
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		send_signal(av[2][i], pid);
		i++;
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
