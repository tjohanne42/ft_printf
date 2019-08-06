C_STANDART = \033[0m
C_GRAS = \033[1m
C_SOULIGN = \033[4m
C_CLIGN = \033[5m
C_SURLIGN = \033[7m
C_BLACK = \033[30m
C_RED = \033[31m
C_GREEN = \033[32m
C_YELLOW = \033[33m
C_BLUE = \033[34m
C_PINK = \033[35m
C_CYAN = \033[36m
C_GREY = \033[37m

NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror

LIBFTDIR = libft/

LIBFTSRC =	ft_atoi.c       ft_memcmp.c     ft_putstr.c     ft_striteri.c   ft_strnstr.c \
			ft_bzero.c      ft_memcpy.c     ft_putstr_fd.c  ft_strjoin.c    ft_strrchr.c \
			ft_isalnum.c    ft_memdel.c     ft_strcat.c     ft_strlcat.c    ft_strsplit.c \
			ft_isalpha.c    ft_memmove.c    ft_strchr.c     ft_strlen.c     ft_strstr.c \
			ft_isascii.c    ft_memset.c     ft_strclr.c     ft_strmap.c     ft_strsub.c \
			ft_isdigit.c    ft_putchar.c    ft_strcmp.c     ft_strmapi.c    ft_strtrim.c \
			ft_isprint.c    ft_putchar_fd.c ft_strcpy.c     ft_strncat.c    ft_tolower.c \
			ft_itoa.c       ft_putendl.c    ft_strdel.c     ft_strncmp.c    ft_toupper.c \
			ft_memalloc.c   ft_putendl_fd.c ft_strdup.c     ft_strncpy.c 	ft_lstdelone.c \
			ft_memccpy.c    ft_putnbr.c     ft_strequ.c     ft_strnequ.c	ft_lstdel.c \
			ft_memchr.c     ft_putnbr_fd.c  ft_striter.c    ft_strnew.c 	ft_lstnew.c \
			ft_lstadd.c		ft_lstiter.c	ft_lstmap.c		ft_power.c		ft_sqrt.c \
			ft_strnjoin.c	ft_nbrlen.c		ft_itoa_base.c

SRCDIR = src/

SRCCONVDIR = $(SRCDIR)convert/

SRCFLAGDIR = $(SRCDIR)flag/

SRC = ft_ftoa.c ft_printf.c ft_uitoa_base.c ft_wstrlen.c insert_buffer.c parser.c take_flag.c take_flag_func.c wchar_utf8.c

SRCCONV = convert_char.c convert_decimal.c convert_decimal_two.c convert_float.c convert_hexadecimal.c convert_octal.c \
		  convert_pointer.c convert_pourcent.c convert_string.c convert_unsigned.c convert_unvalid.c convert_wchar.c convert_wstring.c

SRCFLAG = flag_negative.c flag_width.c flag_zero.c

OBJ = $(SRC:.c=.o) $(SRCCONV:.c=.o) $(SRCFLAG:.c=.o) $(LIBFTSRC:.c=.o)

all: $(NAME)

$(NAME):
	@ $(CC) -c $(addprefix $(SRCDIR), $(SRC)) $(addprefix $(SRCCONVDIR), $(SRCCONV)) \
	$(addprefix $(SRCFLAGDIR), $(SRCFLAG)) $(addprefix $(LIBFTDIR), $(LIBFTSRC))
	@ ar -rc $(NAME) $(OBJ)
	@ ranlib $(NAME)
	@ echo -e "\033[0m==\tCompilation libftprintf.a\t\t\t\033[1;32mDONE$(C_STANDART)"

clean:
	@ rm -f $(OBJ)
	@ echo -e "\033[0m==\tClean objects libftprintf.a\t\t\t\033[1;32mDONE$(C_STANDART)"

fclean: clean
	@ rm -f $(NAME)
	@ echo -e "\033[0m==\tClean library libftprintf.a\t\t\t\033[1;32mDONE$(C_STANDART)"

re: fclean all

test : re
	gcc -o ft_printf main.c libftprintf.a
	@ rm -f $(OBJ)
	./ft_printf | cat -e