#Bank Management Sys C project
#Copy Right : EZZ Taha

# %.x all files end with .x
# $@ replace by name of target
# $< replace by first prerequisite
# $^ replace by all prerequisites

CC= g++

SRCDIR = src
OBJDIR = obj
INCDIR = inc

SRC=$(wildcard $(SRCDIR)/*.cpp)
OBJ=$(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all : bankSystem 
#make rule to generate the final binary 

bankSystem : $(OBJ) $(OBJDIR)/main.o
	$(CC) $(OBJ) $(OBJDIR)/main.o -o bankSystem 

#$(OBJ): $(ODIR)/%.o: src/%.c $(DEPS)
$(OBJDIR)/main.o : main.cpp 
	$(CC) main.cpp -c -o $(OBJDIR)/main.o
	
$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $<




