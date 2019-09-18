#include <SFML/Graphics.hpp>
#ifndef GAMEMACHINE_H
#define GAMEMACHINE_H
#include "constantValue.h"
#include <vector>

class GameMachine {
	struct point
	{
		int x_position;
		int y_position;
	};
	const static int LIFETIME = 3;
	struct player {
		int x_value = 100;
		int y_value = 100;
		float dy = 0.2;
		long score = 0;
		int lifetime = LIFETIME;
		bool isDead = false;
		bool isPaused = false;
		int level = 1;
	};
	const static int PLAT_SIZE = 7;

	//game : platforms, platforms with spring, a monster appearing randomly
	point plat[PLAT_SIZE];
	point plat_spring[3];
	point plat_bad[3];
	point plat_fly[3];

	point monster;
	point monster2;
	player character;
	std::vector<long> score_history;

public:
	//in class getters and setters
	player getCharacter() {
		return character;
	};
	point getMonster() {
		return monster;
	};
	point getMonster2() {
		return monster2;
	};
	void set_score(long score) {
		character.score = score;
	};
	void set_level(int level) {
		character.level = level;
	}
	void set_dy(float dy) {
		character.dy = dy;
	};
	void set_position(int x, int y) {
		character.x_value = x;
		character.y_value = y;
	}
	void set_life(int lives) {
		character.lifetime = lives;
	};
	void set_dead(bool isDead) {
		character.isDead = isDead;
	}
	// features functions
	void generate_platforms();
	void generate_monster();
	void renew_monster();
	bool check_bounce(int &x, int &y, float &dy, sf::Texture &doodler);
	void scroll_platforms(int &y, int &h, float &dy);
	int level_up(sf::Texture &texture);
	int setDeath(sf::Texture &texture);
	void control_by_key(sf::Texture &doodler);
	void start_game();
	void restart_game(std::ofstream &file);
	sf::Sprite super_costumn();
	sf::Texture death_image();
	void pause_player();
	void draw_lives(int &lifetime, sf::RenderWindow &win);
};
#endif // GAMEMACHINE