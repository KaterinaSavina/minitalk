#ifndef LIBFT_H
# define LIBFT_H

# include "unistd.h"
# include <limits.h>

void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);

#endif
