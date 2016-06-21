INC=-I./include/

CXXFLAGS=$(INC) --std=c++0x
OBJS=Infantry.o Event.o Model.o GameEngine.o main.o TurnEvents.o
EXECUTABLE=test_main

#rules

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o $(EXECUTABLE)
