#include "minitalk.h"

void	transmit_char(char c, int pid)
{
	int	i;
	int	temp;

	i = 7;
	while (i >= 0)
	{
		usleep(50);
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

	if (ac != 3)
	{
		ft_putstr("Error: Arguments\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
		transmit_char(av[2][i++], pid);
	msg = "\nMessage Received\n";
	i = 0;
	while (msg[i])
		transmit_char(msg[i++], pid);
	ft_putstr("Message Sent\n");
	return (0);
}
