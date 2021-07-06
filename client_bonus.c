#include "minitalk.h"

void	convert_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		usleep(100);
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
	}
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
	{
		//ft_putchar(av[2][i]);
		decimal_conversion(av[2][i++], 7, pid);
		//convert_char(av[2][i++], pid);
	}
	ft_putchar('\n');
	return (0);
}
