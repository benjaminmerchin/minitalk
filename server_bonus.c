#include "minitalk.h"

void	signal_convertion(int signum)
{
	static int	ascii;
	static int	power;

	if (signum == SIGUSR1)
		ascii += 1 << (7 - power);
	power++;
	if (power == 8)
	{
		ft_putchar(ascii);
		power = 0;
		ascii = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_handler = signal_convertion;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
