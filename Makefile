#/
## EPITECH PROJECT, 2025
## my_octal_nbr
## File description:
## my_octal_nbr
#/

src	=	./file/main.c	\
		./file/loadavg.c	\
		./file/win_ncurse.c	\
		./file/time.c	\
		./file/resume_sys.c

obj   =		$(src:.c=.o)

name  =		my_top

cc    =		clang

CFLAGS =	-g -w -Wall -Wextra -Werror  -lm -lc -lncurses

all: $(name)

$(name):    $(obj)
	$(cc) -o $(name) $(obj) $(CFLAGS)

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(name)

re:
	rm -f $(obj)
	rm -f $(name)
