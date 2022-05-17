#
# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make count' will create the executable file.
#

# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = gcc
# define some Makefile variables for the compiler and compiler flags 
# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: sensor

# To create the executable file count we need the object files
# sensorInputSim.o, main.o:
#
sensor:	sensorInputSim.o main.o
	$(CC) $(CFLAGS) -o sensor sensorInputSim.o main.o

# To create the object file countwords.o, we need the source
# files sensorInputSim.c, sensorInputSim.h:
#
sensorInputSim.o:  sensorInputSim.c sensorInputSim.h
	$(CC) $(CFLAGS) -c sensorInputSim.c

# To create the object file counter.o, we need the source files
# main.c and sensorInputSim.h:
#
main.o:  main.c sensorInputSim.h 
	$(CC) $(CFLAGS) -c main.c

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) sensor.o main.o *~
