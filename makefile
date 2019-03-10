abc:udpser.o mysqlInput.o timeStamp.o md5.o
	gcc udpser.o mysqlInput.o md5.o timeStamp.o -o abc -L /usr/local/mysql/lib/ -lmysqlclient
md5.o:md5.c
	gcc -c md5.c -o md5.o
timeStamp.o:timeStamp.c
	gcc -c timeStamp.c -o timeStamp.o 
mysqlInput.o:mysqlInput.c 
	gcc -c mysqlInput.c -o mysqlInput.o -I /usr/local/mysql/include/ 
udpser.o:udpser.c 
	gcc -c udpser.c	-o udpser.o -I /usr/local/mysql/include/
clean:
	rm *.o abc
