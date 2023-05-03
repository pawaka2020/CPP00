CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
EXTRAFLAGS = -std=c++98
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = phonebook

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(EXTRAFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

t: re
	./$(TARGET)