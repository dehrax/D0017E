
# Makefile for Hello application. Include main.c and
# this makefile in a new "C Project --> Empty Project"
# in Eclipse and it should compile successfully if you
# choose "Build Project" on the "Project" menu.

# In order to run the Hello application you must tell
# Eclipse which program to run. Choose "Run Configurations"
# on the "Run" menu. Click "C/C++ Application" and write
# the application name, which in this case is "Hello".


# List of all targets that should be built by default
all: Hello

# Rule describing how to build the Hello target
Hello: main.c
	gcc -o Hello -Wall -std=c11 main.c

# Cleans up everything created during make
clean:
	\rm -f Hello
