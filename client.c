#include "minitalk.h"

void	decimal_conversion(char ascii, int power, int pid)
{
	usleep(100);
	if (power > 0)
		decimal_conversion(ascii / 2, power--, pid);
	if ((ascii % 2) == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	pid = ft_atoi(av[1]);
	if (ac != 3 || pid < 1)
	{
		ft_putstr("Error: Arguments");
		return (0);
	}
	i = 0;
	while (av[2][i])
		decimal_conversion(av[2][i++], 7, pid);
	return (0);
}
