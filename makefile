default: sigtest.o
	gcc -o test sigtest.o
sigtest.o: sigtest.c
	gcc -c sigtest.c
run:
	./test
clean:
	rm -f *out *~ *o logs
    