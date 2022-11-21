TARGET	= ../my_fancy_game

CC	= gcc

RM	= rm -f

SRCS	= ./create_function.c \
		./enemies_action.c \
		./fight.c \
		./game.c \
		./init_boss.c \
		./init_enemies.c \
		./init_player.c \
		./main.c \
		./players_action.c \
		./boss_action.c \
		./display_utils.c \
		./random.c \
		./xp_utils.c \
		./arrlen.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I
CFLAGS += -Wall -Wextra -Werror -std=c11

all: $(TARGET)

$(TARGET): $(OBJS)
	 $(CC) $(OBJS) -o $(TARGET) $(CFLAGS) -L../lib -lmy

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
