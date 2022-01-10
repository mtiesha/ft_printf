#include "ft_printf.h"

static int	ft_convert_hex(unsigned int dig, const char *base)
{
	char			*heap;
	int				len;
	unsigned long	c_dig;

	len = 0;
	c_dig = dig;
	while (c_dig)
	{
		c_dig /= 16;
		len++;
	}
	heap = (char *)malloc((len + 1) * sizeof(char));
	if (!heap)
		return (0);
	heap[len] = 0;
	while (len--)
	{
		heap[len] = base[dig % 16];
		dig /= 16;
	}
	len = ft_print_str(heap);
	free(heap);
	return (len);
}

static int	ft_convert_p(unsigned long dig, const char *base)
{
	char			*heap;
	int				len;
	unsigned long	c_dig;

	len = 0;
	c_dig = dig;
	while (c_dig)
	{
		c_dig /= 16;
		len++;
	}
	heap = (char *)malloc((len + 1) * sizeof(char));
	if (!heap)
		return (0);
	heap[len] = 0;
	while (len--)
	{
		heap[len] = base[dig % 16];
		dig /= 16;
	}
	len = ft_print_str(heap);
	free(heap);
	return (len);
}

int	ft_print_xX(char c, unsigned int dig)
{
	if (dig == 0)
		return (ft_print_char(48));
    if	(c == 'X')
		return (ft_convert_hex(dig, "0123456789ABCDEF"));
	return (ft_convert_hex(dig, "0123456789abcdef"));
}

int	ft_print_ptr(unsigned long p)
{
	write(1, "0x", 2);
	if (p == 0)
		return (2 + ft_print_char(48));
	return (2 + ft_convert_p(p, "0123456789abcdef"));
}
