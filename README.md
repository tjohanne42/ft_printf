ft_printf subject FR : (https://github.com/koloux/ft_printf/blob/master/subject/ft_printf.pdf)

input example :

rm -f ft_printf_test && make re && make clean && echo "#include \"inc/ft_printf.h\"

int main(void)
{
 // man setlocale
 if (setlocale(LC_ALL, \"\") == 0)
 return (0);
 ft_printf(\"\nResult of ft_printf : %ls\n\", L\"†ïàé\");
 return (0);
}" > main.c && gcc -Wall -Wextra -Werror -o ft_printf_test main.c libftprintf.a && ./ft_printf_test