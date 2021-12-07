#include "minitalk.h"

void	send_char_by_bit(char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
		else
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		c = c >> 1;
		usleep(100);
	}
}

void	handler_client(int signal)
{
	printf("coou");
	write(1, "ok", 2);
	(void)signal;
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	char *str_send;
	struct sigaction sa;

	i = 0;
	if (argc != 3)
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	str_send = argv[2];
	sa.sa_handler = &handler_client;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR2, &sa, NULL);
	while (str_send[i] != '\0')
		send_char_by_bit(str_send[i++], pid);
	send_char_by_bit('\n', pid);
}
