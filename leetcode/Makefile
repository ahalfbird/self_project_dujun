objo = $1
$(objo):($(objo).o)
	gcc -o run $(objo).o
	del -f $(objo).o

$(objo).o:$(objo).c
	gcc -c $(objo).c

.PHONY:clean
clean:
	del -f *.o *.exe