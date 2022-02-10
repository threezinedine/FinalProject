TARGET = dataprocess.exe

BIN = bin
SRC = src
LIB = lib


SOURCE = $(wildcard $(SRC)/*.cpp)
OBJECT = $(subst $(SRC)/,$(BIN)/,$(SOURCE:.cpp=.o))

CC = g++
CFLAGS = -Wall -I$(LIB)

all: test $(TARGET)

test: 
	@IF exist $(BIN) (echo "$(BIN) is already exist.") ELSE (mkdir $(BIN))

$(TARGET): $(OBJECT)
	$(CC) $(OBJECT) -o $(TARGET)

$(BIN)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	del $(subst /,\, $(OBJECT)) $(TARGET)
