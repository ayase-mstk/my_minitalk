#include "minitalk_bonus.h"

static void	sig_handler(int signum, siginfo_t *info, void *ucontext)
{
	static volatile sig_atomic_t	bit;
	static volatile sig_atomic_t	buf;
	char							c;

	(void)ucontext;
	if (signum == SIGUSR2)
		buf |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		c = buf;
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		else
			write(1, &c, 1);
		bit = 0;
		buf = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					ret;

	ft_printf("%d\n", getpid());
	ret = sigemptyset(&sa.sa_mask);
	if (ret < 0)
		exit(1);
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = 0;
	ret = sigaction(SIGUSR1, &sa, NULL);
	if (ret < 0)
		exit(1);
	ret = sigaction(SIGUSR2, &sa, NULL);
	if (ret < 0)
		exit(1);
	while (1)
	{
		pause();
	}
	return (0);
}