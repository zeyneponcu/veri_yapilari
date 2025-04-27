hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/SayilarListesi.o -c  ./src/SayilarListesi.cpp
	g++ -I ./include/ -o ./lib/dugum.o -c  ./src/dugum.cpp
	g++ -I ./include/ -o ./lib/basamak.o -c  ./src/basamak.cpp
	g++ -I ./include/ -o ./lib/sayi.o -c  ./src/sayi.cpp
	g++ -I ./include/ -o ./bin/test ./lib/basamak.o ./lib/sayi.o ./lib/SayilarListesi.o  ./lib/dugum.o ./src/test.cpp
	
calistir:
	./bin/test