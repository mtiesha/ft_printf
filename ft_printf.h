#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_print_dori(int dig);
int	ft_print_u(unsigned int dig);
int	ft_print_xX(char c, unsigned int dig);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_ptr(unsigned long p);
int	ft_printf(const char *format, ...);
#endif