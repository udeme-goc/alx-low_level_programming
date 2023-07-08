#!/bin/bash

# Compile all .c files and create corresponding .o files
gcc -c *.c

# Create the static library liball.a from the .o files
ar -rc liball.a *.o

# Index the library for faster symbol lookup
ranlib liball.a

# Clean up the .o files
rm *.o
