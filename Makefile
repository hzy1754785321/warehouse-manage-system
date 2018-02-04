hzy: people.o product.o menu.o
	g++  people.o product.o menu.o -o hzy
people.o:people.cpp
	g++ -c people.cpp -o people.o
product.o:product.cpp
	g++ -c product.cpp -o product.o
menu.o:menu.cpp
	g++ -c menu.cpp  -o menu.o 
clear:
	rm *.o  -rf
