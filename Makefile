CC = gcc
CFLAGS = -Wall
SRCDIR = src
BINDIR = bin
OBJS = $(SRCDIR)/main.o $(SRCDIR)/file_operations.o $(SRCDIR)/directory_ops.o $(SRCDIR)/permissions.o $(SRCDIR)/logger.o
TARGET = $(BINDIR)/file_manager

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRCDIR)/*.o $(TARGET)

