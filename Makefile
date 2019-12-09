NAME = NcurserWars

SRCS :=	main.cpp \
	 	AsteroidHorde.cpp \
		Bullet.cpp \
		Meteor.cpp \
		SpaceObject.cpp \
		StarShip.cpp

DIR_SRC := $(CURDIR)/src
DIR_OBJ := $(CURDIR)/obj


OBJS := $(SRCS:.cpp=.o)

OBJS := $(addprefix $(DIR_OBJ)/, $(OBJS))
SRCS := $(addprefix $(DIR_SRC)/, $(SRCS))

FLAGS = -Wall -Wextra -Werror

NCURSES = -lncurses

CC = clang++

all: $(NAME)

$(LIBFT_A):
	@make -C libft/

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(NCURSES) -o $(NAME)


$(DIR_OBJ)/%.o: $(DIR_SRC)/%.cpp | $(DIR_OBJ)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	/bin/rm -rf $(OBJS)
	/bin/rm -rf $(DIR_OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
