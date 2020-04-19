##
## Makefile for Makefile in /home/chauch_a/rendu/cpp_plazza
## 
## Made by CHAUCHET Alan
## Login   <chauch_a@epitech.net>
## 
## Started on  Tue Apr 22 17:58:28 2014 CHAUCHET Alan
## Last update Sun Apr 27 20:38:04 2014 CHAUCHET Alan
##

NAME		= plazza

INC		= inc/

PATH1		= src/

PATHINGR	= $(PATH1)Ingr/

PATHPIZZ	= $(PATH1)Pizza/

PATHFORK	= $(PATH1)Fork/

PATHTHREAD	= $(PATH1)Thread/

SRC		= $(PATH1)main.cpp				\
		  $(PATH1)Factory.cpp				\
		  $(PATH1)IngrBox.cpp				\
		  $(PATH1)OptVal.cpp				\
		  $(PATH1)Lexer.cpp				\
		  $(PATH1)Parser.cpp				\
		  $(PATH1)Reception.cpp				\
		  $(PATH1)Kitchen.cpp				\
		  $(PATH1)Cook.cpp				\
		  $(PATH1)MyPerror.cpp				\
		  $(PATHINGR)AIngr.cpp				\
		  $(PATHINGR)ChiefLove.cpp			\
		  $(PATHINGR)Doe.cpp				\
		  $(PATHINGR)EggPlant.cpp			\
		  $(PATHINGR)GoatCheese.cpp			\
		  $(PATHINGR)Gruyere.cpp			\
		  $(PATHINGR)Ham.cpp				\
		  $(PATHINGR)Mushrooms.cpp			\
		  $(PATHINGR)Steak.cpp				\
		  $(PATHINGR)Tomato.cpp				\
		  $(PATHPIZZ)APizza.cpp				\
		  $(PATHPIZZ)Margarita.cpp			\
		  $(PATHPIZZ)Regina.cpp				\
		  $(PATHPIZZ)Americaine.cpp			\
		  $(PATHPIZZ)Fantasia.cpp			\
		  $(PATHFORK)ANamedPipe.cpp			\
		  $(PATHFORK)NamedPipe.cpp			\
		  $(PATHFORK)AProcess.cpp			\
		  $(PATHFORK)Process.cpp			\
		  $(PATHFORK)Select.cpp				\
		  $(PATHTHREAD)AThread.cpp			\
		  $(PATHTHREAD)Thread.cpp			\
		  $(PATHTHREAD)AMutex.cpp			\
		  $(PATHTHREAD)Mutex.cpp			\
		  $(PATHTHREAD)ACond.cpp			\
		  $(PATHTHREAD)Cond.cpp				\

OBJ	= $(SRC:.cpp=.o)

CPPFLAGS	= -W -Wall -Werror -Wextra -I $(INC)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) -lpthread -D_REENTRANT

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
