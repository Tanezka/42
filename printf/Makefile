NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
OPTION = -c
SRC = *.c
RUN = make all
TF = "libft/libft.a"

all: $(NAME)

$(NAME):
	cd libft && make all
	gcc $(FLAG) $(OPTION) $(SRC) 
	ar rc $(NAME) *.o libft/*.o

clean:
	rm -f *.o
	cd libft && make clean
fclean: clean
	rm -f $(NAME)
	cd libft && make fclean
re: fclean all

.PHONY: all clean fclean re
