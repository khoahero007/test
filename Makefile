TARGET	= mapping
CC	= g++
CFLAGS	= -c -Wall
LINKER   = g++ -o
LFLAGS   = -Wall -I. -lm

SRCDIR	= src
OBJDIR	= obj
BINDIR	= bin

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES:= $(wildcard $(SRCDIR)/*.hpp)
OBJECTS	:= $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm	= rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
