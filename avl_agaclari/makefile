hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/stack.o -c ./src/stack.cpp
	g++ -I ./include/ -o ./lib/trees.o -c ./src/trees.cpp
	g++ -I ./include/ -o ./lib/dugum.o -c ./src/dugum.cpp
	g++ -I ./include/ -o ./lib/avl.o -c ./src/avl.cpp
	g++ -I ./include/ -o ./lib/node.o -c ./src/node.cpp
	g++ -I ./include/ -o ./bin/test ./lib/node.o ./lib/avl.o ./lib/stack.o ./lib/trees.o ./lib/dugum.o ./src/test.cpp
	
calistir:
	./bin/test	