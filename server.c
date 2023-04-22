#include <signal.h>
#include <stdio.h>

char *str;

void	send_zero(int signum)
{
	// 0を配列に格納する
	exit(1);
}

void	send_one(int signum)
{
	// 1を配列に格納する
	exit(1);
}

int main(void)
{
	signal(SIGUSR1, send_zero);
	signal(SIGUSR2, send_one);
	while (1)
	{
	}
	return (0);
}
