#include "../inc/ft_printf.h"

int	is_conv(char c)
{
	int	ret;
	char	*conv;

	conv = "sSpdDioOuUxXcC"
	ret = ft_strstr(&c, conv) != NULL ? 1 : 0;
	return (ret);
}
