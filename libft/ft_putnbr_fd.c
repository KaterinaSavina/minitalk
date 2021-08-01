#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	a;

	a = '-';
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(fd, &a, 1);
		nb = -nb;
	}
	if (nb <= 9)
	{
		nb = nb + 48;
		write(fd, &(nb), 1);
		nb = nb - 48;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
