NAME = mx_cat
NAME1 = src_file dst_file

SRCS = src/mx_cat.c src/mx_strlen.c src/mx_printerr.c
SRCSOB = mx_cat.c mx_strlen.c mx_printerr.c

INC = inc/minilibmx.h
INCOB = minilibmx.h

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean
install:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -o $(NAME) $(SRCSOB) -I $(INCOB)
uninstall: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME1)
clean:
	@rm -rf $(INCOB)
	@rm -rf $(SRCSOB)
reinstall: uninstall all
