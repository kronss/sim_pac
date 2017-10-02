CC = clang++

CFLAGS = -I./$(INC_DIR)
# -Wall -Wextra -Werror
SHELL = /bin/sh

################################################################################
#	
################################################################################
NAME = a.out

#********* -INC
INC_NAME =	main.hpp \
			Window.class.hpp \
			Unit.class.hpp \
			Pacman.class.hpp \
			Ghost.class.hpp
# add .hpp file ---->
INC_DIR =	inc
INC = $(addprefix $(INC_DIR)/, $(INC_NAME))


#********* -OBJ
OBJ_DIR =	.obj
OBJ = $(subst .cpp,.o,$(subst $(SRC_DIR)/,$(OBJ_DIR)/,$(SRC)))


#********* -SRC
SRC_DIR =	src
SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAME))
SRC_NAME =	main.cpp \
			Window.class.cpp \
			Unit.class.cpp \
			Pacman.class.cpp \
			Ghost.class.cpp
# add .cpp file ---->



################################################################################
#	RULES
################################################################################

.PHONY: all clean fclean re t

all: $(NAME)

$(NAME): $(OBJ) $(INC) 
	$(CC) $(CFLAGS)  $(OBJ) -o $(NAME) -lncurses
	@echo "\033[33m'$(NAME)' compiling done.\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $? -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all


##############
# dell 

lite_clean:
	rm -rf $(OBJ_DIR)

rew: lite_clean $(NAME);
	
r:	$(NAME)
	./$(NAME)

bug:
	$(CC) $(CFLAGS)  -I./inc/ $(SRC) -g -o bug

debug: bug
	lldb -- ./bug
