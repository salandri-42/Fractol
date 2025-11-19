NAME = libftprintf.a

SRCS = ft_basicflags.c ft_for_pointer.c ft_printf.c ft_putchar.c \
	ft_puthexa.c ft_putnbr.c ft_putstr.c ft_putunsi.c ft_strlen.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = cc

all : $(NAME)

.c.o:
	cc $(FLAGS) -c $< -o $(<:.c=.o)
	
$(NAME) : $(OBJS)
				ar -rcs $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)
