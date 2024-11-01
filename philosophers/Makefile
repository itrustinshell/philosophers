CC = gcc

CFLAGS = -Wextra -Werror -Wall

TARGET = philo
SRCS = main.c validation.c philosophers.c forks.c pmt.c print.c init.c init_utils.c actions.c  actions_utils.c actions_utils_2.c actions_utils_3.c 
SRC_DIR = src

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJ_DIR = obj
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all
