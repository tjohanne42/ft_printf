#include "inc/ft_printf.h"

int		main(void)
{
	if (!setlocale(LC_ALL, ""))
		return (0);
	ft_printf("ïàé\n");
	return (0);
}
