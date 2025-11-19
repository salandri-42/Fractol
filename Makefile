NAME = fractol

BONUS = fractol_bonus

FT_PRINTF = ft_printf/libftprintf.a

MLX = minilibx-linux/libmlx.a

SRCS = fractol.c utils.c mandelbrot.c julia.c ft_strncmp.c event_utils.c ft_atoi.c

SRCS_BONUS = bonus/atof_bonus.c \
						 bonus/event_bonus.c \
						 bonus/fractol_bonus.c \
						 bonus/julia_bonus.c \
						 bonus/mandelbrot_bonus.c \
						 bonus/strncmp_bonus.c \
						 bonus/utils_bonus.c \
						 bonus/burningship_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

bonus : $(BONUS)

.c.o :
	cc $(FLAGS) -Iminilibx-linux -O3 -c $< -o $@

$(NAME) : $(OBJS) $(MLX) $(FT_PRINTF)
	cc $(FLAGS) $(OBJS) -Lminilibx-linux -lmlx_Linux -Iminilibix-linux -lXext -lX11 -lm -lz -o $(NAME) $(FT_PRINTF)

$(BONUS) : $(OBJS_BONUS) $(MLX) $(FT_PRINTF)
	cc $(FLAGS) $(OBJS_BONUS) -Lminilibx-linux -lmlx_Linux -Iminilibix-linux -lXext -lX11 -lm -lz -o $(BONUS) $(FT_PRINTF)

$(FT_PRINTF) :
	make -C ft_printf/

$(MLX) :
	make -C minilibx-linux/

clean :
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	make clean -C minilibx-linux/
	make clean -C ft_printf/

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS)
	make fclean -C ft_printf/

re : fclean $(NAME)

.PHONY : all clean fclean re
