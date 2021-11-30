#include "minitalk.h"

void	send_char_by_bit(char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	char *str_send;

	i = 0;
	if (argc != 3)
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	str_send = argv[2];
	while (str_send[i] != '\0')
	{
		send_char_by_bit(str_send[i], pid);
		i++;
	}
}
