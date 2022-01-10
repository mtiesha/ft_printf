#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = 0;
	while (*str)
		len += write(1, &*str++, 1);
	return (len);
}

int	ft_print_u(unsigned int dig)
{
	unsigned long	ret;

	ret = 0;
	if (dig >= 10)
	{
		ret += ft_print_u(dig / 10);
		ret += ft_print_u(dig % 10);
	}
	else
		ret += ft_print_char(dig + '0');
	return (ret);
}

int	ft_print_dori(int dig)
{
	long	ret;

	if (dig == -2147483648)
		return (write(1, "-2147483648", 11));
	ret = 0;
	if (dig < 0)
	{
		ret += ft_print_char('-');
		dig = dig * -1;
	}
	if (dig >= 10)
	{
		ret += ft_print_dori(dig / 10);
		ret += ft_print_dori(dig % 10);
	}
	else
		ret += ft_print_char(dig + '0');
	return (ret);
}
