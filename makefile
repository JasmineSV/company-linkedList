CFLAGS = -std=c++14 -Wall

company:    menu.o company.o employee.o
	g++ menu.o company.o employee.o -o company $(CFLAGS)

test:	main.o company.o employee.o
	g++ main.o company.o employee.o -o test $(CFLAGS)

main.o:	main.cpp employee.h company.h
	g++ -c main.cpp $(CFLAGS)

employee.o:	employee.cpp employee.h
	g++ -c employee.cpp $(CFLAGS)

company.o:	company.cpp company.h employee.h
	g++ -c company.cpp $(CFLAGS)

menu.o:	menu.cpp employee.h company.h
	g++ -c menu.cpp $(CFLAGS)

clean:
	rm test company *.o
