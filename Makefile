CC := g++  # compiler
CFLAGS := -Wall -g  # compiler flags  # -Wall: warning, -g: debug
TARGET := NotAGame  # target name

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.cpp ./src/*.cpp)  # source files (all .cpp files) in the current directory and dir "./src/" 
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS := $(patsubst %.cpp,%.o,$(SRCS))   # object files (all .o files) in the current directory and dir "./src/" 
  
all: $(TARGET)  # target name
$(TARGET): $(OBJS)   # object files (all .o files) in the current directory and dir "./src/"
	$(CC) -o $@ $^  # compile and link all object files to the target name (TARGET) 
./src/%.o: %.cpp  # compile all .cpp files to .o files
	$(CC) $(CFLAGS) -c $<  # compile and link all object files to the target name (TARGET)
clean:
	rm -rf $(TARGET) *.o
	
.PHONY: all clean
