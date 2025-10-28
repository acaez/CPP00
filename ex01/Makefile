NAME = eyescontact
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I./inc

SRC_DIR = src
SRCS = $(SRC_DIR)/eyescontact.cpp \
       $(SRC_DIR)/main.cpp

OBJ_DIR = obj
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re