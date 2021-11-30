#include "minitalk.h"

int     calcul_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * calcul_power(nb, power - 1));
}

void	handler(int signum)
{
	static int	current_bit = 0;
	static int	char_value = 0;

	if (signum == SIGUSR2)
		char_value += calcul_power(2, current_bit);
	if (current_bit == 7)
	{
		ft_putchar_fd(char_value, 0);
		current_bit = 0;
		char_value = 0;
		return ;
	}
	current_bit++;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, STDIN_FILENO);
	ft_putchar_fd('\n', STDIN_FILENO);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		usleep(100);
}
