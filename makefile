TARGET = CoffeeMachine
CC = @g++
MAIN = src/main.cpp
INCLUDES = -I inc/
CFLAG = -Wall
SRC_DIR := src/
SRC := $(wildcard $(SRC_DIR)*.cpp)
OBJ_DIR := obj/
OBJ := $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

########################################################
.PHONY: clean create
all: clean create $(TARGET)

$(TARGET): $(OBJ)
	@echo "Building the project..." 
	$(CC) $^ $(CFLAG) -o $@
	@echo "Executing ...................................."
	@./$(TARGET)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@echo "Create a object files..."
	$(CC) -c $(CFLAG) $< $(INCLUDES) -o $@

create:
	@mkdir -p $(OBJ_DIR)

clean: 
	@echo "Cleaning the project..."
	@rm -rf $(TARGET) $(OBJ_DIR)
