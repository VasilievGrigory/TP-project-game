game: main.cpp lib.h
	g++  --std=c++17 main.cpp -lncurses -o game
test_1: test_composite.cpp lib.h
	g++  --std=c++17 test_composite.cpp -lncurses -o test_1
test_2: test_unite.cpp lib.h
	g++  --std=c++17 test_unite.cpp -lncurses -o test_2

