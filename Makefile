CC = g++
CFLAGS = -std=c++11 -Wall -O2 -ggdb

BINDIR = bin
SOURCEDIR = src
OBJDIR = $(BINDIR)/obj

SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCEDIR)/%, $(OBJDIR)/%, $(patsubst %.cpp, %.o, $(SOURCES)))

TARGET = $(BINDIR)/linq_test

$(TARGET): init $(OBJECTS)
	@echo -n 'Linking $@ ...'
	$(CC) $(CFLAGS) $(OBJECTS) -o $@
	@echo ' OK'

$(OBJDIR)/%.o: $(SOURCEDIR)/%.cpp
	@echo -n 'Compiling $@ ...'
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo ' OK'

.PHONY: clean init test

init:
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(BINDIR) 	