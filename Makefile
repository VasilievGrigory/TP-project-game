game: main.cpp Game.h
	sudo apt-get install libncursesw5-dev
	g++ --std=c++17 main.cpp -lncurses -o game
