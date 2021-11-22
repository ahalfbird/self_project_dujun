include mconfig

objects=searchmax.o

run:searchmax.o
	gcc searchmax.o -o run

fifo:fifo.o
	gcc fifo.o -o fifo
	
bmpio:bmpio.o
	gcc bmpio.o -o bmpio
	
timeto:timeto.o
	gcc timeto.o -o timeto

calc:calc.o
	gcc calc.o -o calc

goout:goout.o
	gcc goout.o -o goout

hexio:hexio.o
	gcc hexio.o -o hexio

dghelper:dghelper.o
	gcc dghelper.o -o dghelper

dosomething:dosomething.o
	gcc dosomething.o -o dosomething
	
868:868.o
	gcc 868.o -o 868

856:856.o
	gcc 856.o -o 856

287:287.o
	gcc 287.o -o 287

735:735.o
	gcc 735.o -o 735

1681:1681.o
	gcc 1681.o -o 1681

getcom:getcom.o
	gcc getcom.o -o getcom

bmpedit:bmpedit.o
	gcc bmpedit.o -o bmpedit

#cc===============================================co
searchmax.o:searchmax.c
	gcc -c $(CFLAG) searchmax.c

fifo.o:fifo.c
	gcc -c $(CFLAG) fifo.c
	
bmpio.o:bmpio.c
	gcc -c $(CFLAG) bmpio.c
	
timeto.o:timeto.c
	gcc -c $(CFLAG) timeto.c

calc.o:calc.c
	gcc -c $(CFLAG) calc.c

goout.o:goout.c
	gcc -c $(CFLAG) goout.c

hexio.o:hexio.c
	gcc -c $(CFLAG) hexio.c

dghelper.o:dghelper.c
	gcc -c $(CFLAG) dghelper.c

dosomething.o:dosomething.c
	gcc -c $(CFLAG) dosomething.c

868.o:868.c
	gcc -c $(CFLAG) 868.c

287.o:287.c
	gcc -c $(CFLAG) 287.c

856.o:856.c
	gcc -c $(CFLAG) 856.c

735.o:735.c
	gcc -c $(CFLAG) 735.c

1681.o:1681.c
	gcc -c $(CFLAG) 1681.c

getcom.o:getcom.c
	gcc -c $(CFLAG) getcom.c

bmpedit.o:bmpedit.c
	gcc -c $(CFLAG) bmpedit.c
	
	
#run:$(objects)
#	gcc -o wrun $(objects) > error.txt
#	gcc -Wl,--verbose -o wrun $(objects) 

#*.o:*.c
#	g++ -c $(CFLAG) *.cpp
	
	
.PHONY:clean
clean:
	del -f *.o *.exe