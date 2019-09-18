#include <SFML/Graphics.hpp>
#include "clock.h"
#include "gameMachine.h"
#include "scoreMachine.h"
#include <iostream>
#include <fstream>

//the limit of the window openning time
const long RUNTIME_OUT = 1000000000;
const std::string FILENAME_WRITE_IN = "Text.txt";
std::ofstream score_file;

int main() {
	Timer clock;
	GameMachine game;
	game.start_game();
	if (clock.runTime >= RUNTIME_OUT) {
		return 0;
	}
	//try to write in file
	score_file.open(FILENAME_WRITE_IN);
	score_file << "Game over!" << std::endl;
	score_file.close();
	return 0;
}