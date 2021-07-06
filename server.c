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

int	main()
{
	int	pid;
//	struct sigaction	a;

	signal(SIGUSR1, signal_convertion);
	signal(SIGUSR2, signal_convertion);
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
