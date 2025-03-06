
NAME = program

SRCS = \
   main.cpp \
   ShrubberyCreationForm.cpp \
   PresidentialPardonForm.cpp \
   Bureaucrat.cpp \
   RobotomyRequestForm.cpp \
   Intern.cpp \
   AForm.cpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -Weffc++

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "________Compiled!________"
	@echo ""

.PHONY: clean
clean:
	@rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)

.PHONY: re
re: fclean all

