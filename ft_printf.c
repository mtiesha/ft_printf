#include "ft_printf.h"

static long	ft_pars(const char *str, va_list arg)
{
	if (*str)
	{
		if (*str == 'd' || *str == 'i')
			return (ft_print_dori(va_arg(arg, int)));
		if (*str == 'u')
			return (ft_print_u(va_arg(arg, unsigned int)));
		if (*str == 'x' || *str == 'X')
			return (ft_print_xX(*str, va_arg(arg, unsigned int)));
		if (*str == 'c')
			return (ft_print_char(va_arg(arg, int)));
		if (*str == '%')
			return (ft_print_char('%'));
		if (*str == 's')
			return (ft_print_str(va_arg(arg, char *)));
		if (*str == 'p')
			return (ft_print_ptr(va_arg(arg, unsigned long)));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
    int		ret;
	va_list	ap;

	ret = 0;
	if (!format)
		return (0);
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			ret += write(1, &(*format), 1);
			format++;
		}
		if (*format && *format == '%')
		{
			ret += ft_pars(++format, ap);
			format++;
		}
	}
	va_end(ap);
    return (ret);
}
