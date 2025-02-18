SRC = $(wildcard ./src/*.c)
OBJ = $(addprefix ./obj/, $(addsuffix .o, $(basename $(notdir $(SRC)))))
FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
CC = clang
PARSE_AGENTS = parse_agents

all: $(PARSE_AGENTS)

$(PARSE_AGENTS): $(OBJ)
	@ar rcs $(PARSE_AGENTS).a $(OBJ);
	@$(CC) $(FLAGS) -o $(PARSE_AGENTS) -I inc src/$(PARSE_AGENTS).c $(PARSE_AGENTS).a

clean:
	@rm -rf ./obj/ ;

uninstall: clean
	@rm -f $(PARSE_AGENTS).a ;
	@rm -f $(PARSE_AGENTS) ;

reinstall: uninstall all

./obj/%.o: ./src/%.c
	@mkdir -p ./obj/ ;
	@$(CC) $(FLAGS) -c $< -o $@ ;
