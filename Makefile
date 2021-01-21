smerge: smerge.cpp
	g++ -g smerge.cpp -fopenmp -o smerge

all: smerge

clean:
	rm -rf *.o smerge