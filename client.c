#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;
	char *str_send;

	if (argc != 3)
		printf("ERROR\n");
	pid = ft_atoi(argv[1]);
	str_send = argv[2];
	printf("PID is %i\nSTR to send is %s\n", pid, str_send);

	return (0);
}
