#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				neg;
	unsigned long	number;

	i = 0;
	neg = 0;
	number = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
		if (str[i++] == '-')
			neg = 1;
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + (str[i++] - '0');
	if (((number) > LONG_MAX) && (neg == 0))
		return ((int)LONG_MAX);
	if (((number - 1) > LONG_MAX) && (neg == 1))
		return (0);
	if (neg == 1)
		return ((int) - number);
	return ((int)number);
}
