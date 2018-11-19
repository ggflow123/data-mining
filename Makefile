all: knn.o kdtree.o
	gccx -o knn knn.o kdtree.o

knn: knn.o kdtree.o
	gccx -o knn knn.o kdtree.o

knn.o: knn.c
	gccx -c knn.c    

kdtree.o: kdtree.c
	gccx -c kdtree.c

clean: kdtree.o knn.o knn
	rm kdtree.o knn.o knn
