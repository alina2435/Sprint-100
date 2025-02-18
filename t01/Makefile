

SRCS = src/mx_cp.c src/mx_strlen.c src/mx_printerr.c
SRCSOB = mx_cp.c mx_strlen.c mx_printerr.c

INC = inc/minilibmx.h
INCOB = minilibmx.h
NAME = mx_cp
NAME1 = src_file dst_file
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
reinstall: uninstall clean all
