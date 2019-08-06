ft_printf subject FR : (https://github.com/koloux/ft_printf/blob/master/subject/ft_printf.pdf)

usage exemple :

#include "inc/ft_printf.h"

int		main(void)
{
	// man setlocale
	if (!setlocale(LC_ALL, ""))
		return (0);
	ft_printf("†ïàé\n");
	return (0);
}
