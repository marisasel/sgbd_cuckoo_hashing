CFLAGS = -g -Wall 

object = myht.c hash_table.c auxiliar.c

all:  $(object)
	gcc $(object) -o myht $(CFLAGS) -lm

clean:
	rm -f *.o myht

purge:	clean
	rm -f myht