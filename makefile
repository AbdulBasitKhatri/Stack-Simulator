CC=g++

BIN=stack-simulator

INC=. ./include/
SRC=.

CFLAGS=-MP -MD -Wall -Wextra -g $(foreach F,$(INC),-I$(F))

CF=$(foreach F,$(SRC),$(wildcard $(F)/*.cpp))
OBJ=$(patsubst %.cpp,%.o,$(CF))
DEP=$(patsubst %.cpp,%.d,$(CF))

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ) $(DEP) $(BIN)

-include $(DEP)
