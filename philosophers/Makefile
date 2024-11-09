CC = gcc

CFLAGS = -Wextra -Werror -Wall

TARGET = philo
SRCS = main.c destroy.c pmt_mutexinit.c routine.c philosophers.c monitor.c free.c threads_join.c forks.c pmt.c print.c input.c actions.c  actions_utils.c action_takefork.c utils.c 

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
