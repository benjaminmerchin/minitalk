#include "minitalk.h"

void	convert_char(char c, int pid)
{
	int	i;
	int	temp;

	i = 7;
	while (i >= 0)
	{
		usleep(100);
		temp = c >> i;
		if (temp & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	*msg;

	pid = ft_atoi(av[1]);
	if (ac != 3 || pid < 1)
	{
		ft_putstr("Error: Arguments");
		return (0);
	}
	i = 0;
	while (av[2][i])
		convert_char(av[2][i++], pid);
	msg = "\nMessage Received\n";
	i = 0;
	while (msg[i])
		convert_char(msg[i++], pid);
	ft_putstr("Message Sent\n");
	return (0);
}
