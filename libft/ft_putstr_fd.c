#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	x;

	if (!s)
		return ;
	if (s)
	{
		x = (int)ft_strlen(s);
		write (fd, s, x);
	}
}
