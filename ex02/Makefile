MAKEFLAGS	= --silent
GREEN		=	\033[3;32m
DEFAULT		=	\033[0m

NAME		= bureaucrat
SOURCESPATH	= ./
SOURCESLIST	= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp
SOURCES = $(addprefix $(SOURCESPATH), $(SOURCESLIST))

COMPILE	= c++
FLAGS	= -Wall -Wextra -Werror -O3 -std=c++98
# Replaced -g with -O3 to optimise the code (removing debug symbols).
# -O3 is faster than -g and -O2, but it takes longer to compile.
VALGRIND	= valgrind -s --leak-check=full --show-leak-kinds=all
# -s to suppress the summary, -v to show the full report.
# --track-origins=yes to show where the memory was allocated.
REMOVE	= rm -f

.c.o:
	$(COMPILE) $(FLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):
	$(COMPILE) $(FLAGS) $(SOURCES) -o $(NAME)

fclean:
	@$(REMOVE) $(NAME)
	echo "$(GREEN)Limpíssimo!$(DEFAULT)"

clean: fclean

re:		fclean all

run:	$(NAME)
	./$(NAME)

vrun:	$(NAME)
	$(VALGRIND) ./$(NAME)

rerun:	re run

# Ignores files that could eventually be named after any of these rules.
.PHONY:		all clean fclean re
