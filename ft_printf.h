#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_printf(const char *format, ...);
typedef struct s_print
{
	va_list	param;//# arg to print out
	int	wdt;//width
	int	prc;//precision
	int	zero;//zero padding
	int	dot;//.
	int	dash;//-
	int	len;//total_length (return value)
	int	sign;//pos or neg number
	int	is_zero;//is number zero
	int	per;//%
	int	sp;//space flag ' '
}	t_print;
#endif