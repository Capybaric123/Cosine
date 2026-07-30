CC = clang
IDIR = -I./include
LDIR = -L./lib
CFLAGS = -std=c99 -O3 -g -Wall -Wextra
LDFLAGS = -lglfw
LDFLAGS += -lGL -lX11 -lpthread -lXrandr -lXi -ldl

SRC = $(wildcard src/*.c)

build:
	$(CC) -o app $(IDIR) $(LDIR) $(SRC) $(CFLAGS) $(LDFLAGS)
