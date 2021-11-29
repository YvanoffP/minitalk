#include "minitalk.h"

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("%i\n", pid);
	sleep(10);
}
