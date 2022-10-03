###############################################################################
# Tyler Perkins
# 3-10-22
# Makefile
#

CC = g++

FLAGS  = -pipe

CFLAGS  = -Wall
CFLAGS += -Ofast
CFLAGS += -g
#CFLAGS += -pg

LIBRARIES =

SRC = $(shell find ./src -name '*.cpp')
OBJ = $(subst .cpp,.o,$(SRC))
BIN = ./bin

PREFIX    = /usr/local
MANPREFIX = $(PREFIX)/share/man

TARGET = image_processing_demo

MAKEFLAGS += --jobs=4

all : $(OBJ)
	@echo LD $@
	@$(CC) $(FLAGS) $(CFLAGS) -o $(BIN)/$(TARGET) $(OBJ) $(LIBRARIES)

.cpp.o :
	@echo CC $<
	@$(CC) $(FLAGS) $(CFLAGS) $(LIBRARIES) $(DEFINITIONS) -c $< -o $@

install : all

uninstall :

clean :
	find . -type f -name '*.o' -delete
	rm -rf $(BIN)/*
