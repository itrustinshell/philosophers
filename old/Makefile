CC = gcc
CFLAGS = -Wall -Wextra -o -phtread
TARGET = philo
SRCS = main.c join_and_free.c init_pmt_death.c init_pmt_general.c init_pmt_meals.c validation.c monitor_routine.c create_malloc.c init_param.c utils.c philosophers_routine.c take_forks.c
SRC_DIR = src
## OBJS = $(SRCS:.c=.o)
##Objects fiile, that is files *.c transformed in machine-language-file *.o 
##the following is only a textual translation...for the rule see below
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJ_DIR = obj
all: $(TARGET)

#allora il nostro obiettivo è il target.
# per fare il target devi avere objs
#objs è uguale ai SRCS preceduti dal path della OBJ_DIR
# se fai il cc degli objs ottieni il target (eseguibile)
# questa regola equivale olo ad aver scritto sul terminale il comando finale da eseguire.
#ma non verrò mai eseguito se non esistono quelle cose...ma diciamo che dopo aver costruitor
#tutto devi scivere appunto quel comando finale.

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -g -o $(TARGET) -lpthread

#quindi questi file .o devono essere creati nella cartella obj
##this is to create file object.
## | is an order-only prerequisites.
#Prerequisites listed after the | are order-only prerequisites. They indicate that the target needs to be created if it doesn't exist, but they do not affect the rebuilding of the target if they are updated. Order-only prerequisites are only checked to see if they exist or not.
#$(OBJ_DIR) after | is an order-only prerequisite. It ensures that the directory $(OBJ_DIR) exists before any object file is compiled into it. If $(OBJ_DIR) doesn't exist, Make will create it before proceeding with any compilation.


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
#ora effettivamente esistono....e la regola iniziale ha successo

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all


