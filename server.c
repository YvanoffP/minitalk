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

void	handler(int signum, siginfo_t *siginfo, void *room)
{
	static int	current_bit = 0;
	static int	char_value = 0;

	(void)room;
	if (signum == SIGUSR2)
		char_value += calcul_power(2, current_bit);
	if (current_bit >= 7)
	{
		ft_putchar_fd(char_value, 0);
		current_bit = 0;
		char_value = 0;
		kill(siginfo->si_pid, SIGUSR2);
		return ;
	}
	current_bit++;
	kill(siginfo->si_pid, SIGUSR2);
}

int	main(void)
{
	int	pid;
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	pid = getpid();
	ft_putnbr_fd(pid, STDIN_FILENO);
	ft_putchar_fd('\n', STDIN_FILENO);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
