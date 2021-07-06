#include "minitalk.h"

void	decimal_conversion(char ascii, int power, int pid)
{
	if (power > 0)
		decimal_conversion(ascii / 2, power - 1, pid);
	if ((ascii % 2) == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(1);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	pid = ft_atoi(av[1]);
	if (ac != 3)
	{
		ft_putstr("Error: Wrong number of arguments");
		return (0);
	}
	i = 0;
	while (av[2][i])
	{
		//ft_putchar(av[2][i]);
		decimal_conversion(av[2][i++], 7, pid);
	}
	ft_putchar('\n');
	return (0);
}
