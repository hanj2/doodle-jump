#include <SFML/Graphics.hpp>

//reference: https://en.sfml-dev.org/forums/index.php?topic=11989.0
struct Timer {
	sf::Clock mC;
	float runTime;
	bool paused;

	Timer() {
		paused = false;
		runTime = 0;
		mC.restart();
	}

	void Reset() {
		mC.restart();
		runTime = 0;
		paused = false;
	}
};