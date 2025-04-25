# Makefile for compiling parallel and serial Quicksort

CC = mpic++
CFLAGS = -O2

# Executable names
PARALLEL_EXEC = quicksort_parallel
SERIAL_EXEC = quicksort_serial

# Default target
all: $(PARALLEL_EXEC) $(SERIAL_EXEC)

# Compile parallel version
$(PARALLEL_EXEC): quicksort_parallel.cpp utils.cpp
	$(CC) $(CFLAGS) quicksort_parallel.cpp utils.cpp -o $(PARALLEL_EXEC)

# Compile serial version
$(SERIAL_EXEC): quicksort_serial.cpp utils.cpp
	g++ $(CFLAGS) quicksort_serial.cpp utils.cpp -o $(SERIAL_EXEC)

# Clean compiled files
clean:
	rm -f $(PARALLEL_EXEC) $(SERIAL_EXEC)

# Run the parallel version (example)
run_parallel:
	mpirun -np 4 ./$(PARALLEL_EXEC)

# Run the serial version (example)
run_serial:
	./$(SERIAL_EXEC)
