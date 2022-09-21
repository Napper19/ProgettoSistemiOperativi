all: extralcs

extralcs: extractlcs.o lcs.o lcs.h
	gcc -o extralcs extractlcs.o lcs.o lcs.h

lcs.o: lcs.c lcs.h
	gcc -c lcs.c
	
extractlcs.o: extractlcs.c lcs.h
	gcc -c extractlcs.c

clean:
	rm extractlcs.o lcs.o extralcs