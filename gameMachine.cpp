#define SFML_NO_DEPRECATED_WARNINGS
#include "gameMachine.h"
//#include "scoreMachine.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

const std::string IMAGE_NINJA = "images/ninja.png";
const std::string IMAGE_BLUE = "images/doodler-blue.png";
const std::string IMAGE_HEART = "images/heart.png";
const std::string IMAGE_DEAD = "images/doodler-dead.png";
const std::string IMAGE_LEVEL_UP = "images/ninja-level-up.png";
const std::string IMAGE_FLY = "images/fly-mode.png";
const std::string IMAGE_BACKGROUND = "images/background.png";
const std::string IMAGE_PLATFORM = "images/platform.png";
const std::string IMAGE_MONSTER = "images/monster.png";
const std::string IMAGE_MONSTER2 = "images/monster2.png";
const std::string IMAGE_PLATFORM_SPRING = "images/platform-spring.png";
const std::string IMAGE_PLATFORM_BAD = "images/platform-bad.png";
const std::string IMAGE_PLATFORM_FLY = "images/platform-fly.png";
const std::string FILENAME_WRITE_IN = "Text.txt";

//function to generate platforms randomly
void GameMachine::generate_platforms() {
	for (int i = 0; i < PLAT_SIZE; i++) {
		plat[i].x_position = std::rand() % MACHINE_LENGTH;
		plat[i].y_position = std::rand() % MACHINE_HEIGHT;
	}
	for (int j = 0; j < SPECIAL_PLATFORM_SIZE; j++) {
		plat_spring[j].x_position = std::rand() % MACHINE_LENGTH;
		plat_spring[j].y_position = std::rand() % MACHINE_HEIGHT;
	}
	for (int j = 0; j < SPECIAL_PLATFORM_SIZE; j++) {
		plat_bad[j].x_position = std::rand() % MACHINE_LENGTH;
		plat_bad[j].y_position = std::rand() % MACHINE_HEIGHT;
	}
	for (int j = 0; j < SPECIAL_PLATFORM_SIZE; j++) {
		plat_fly[j].x_position = std::rand() % MACHINE_LENGTH;
		plat_fly[j].y_position = std::rand() % MACHINE_HEIGHT;
	}
}

// the method to generate a monster in this game
void GameMachine::generate_monster() {
	monster.x_position = std::rand() % MACHINE_LENGTH;
	monster.y_position = std::rand() % MACHINE_HEIGHT;
	monster2.x_position = std::rand() % MACHINE_LENGTH;
	monster2.y_position = std::rand() % MACHINE_HEIGHT;
}

//update the position of the monster
void GameMachine::renew_monster() {
	//scroll the monsters when they are out of the screen
	monster.x_position = std::rand() % MACHINE_LENGTH;
	monster.y_position = std::rand() % MACHINE_HEIGHT;
	monster2.x_position = std::rand() % MACHINE_LENGTH;
	monster2.y_position = std::rand() % MACHINE_HEIGHT;
}

// Bounce is initiated when acceleration is downward and doodle is
// touching a platform 
bool GameMachine::check_bounce(int &x, int &y, float &dy, sf::Texture &doodler) {
	//if dead, just fall down
	if (character.isDead && character.y_value > MACHINE_HEIGHT - ERROR_OF_DEATH) {
		return false;
	}
	//the check for normal platforms
	for (int i = 0; i < PLAT_SIZE; i++) {
		if ((x + 50 > plat[i].x_position) && (x + 20 < plat[i].x_position + 68)
			&& (y + 60 > plat[i].y_position) && (y + 60 < plat[i].y_position + 14) && (dy > 0)) {
			dy = -10;
			sf::Texture image;
			image.loadFromFile(IMAGE_NINJA);
			doodler.update(image);
		}
	}
	for (int j = 0; j < SPECIAL_PLATFORM_SIZE; j++) {
		//the check for platforms with spring 
		if ((x + 50 > plat_spring[j].x_position) && (x + 20 < plat_spring[j].x_position + 68)
			&& (y + 60 > plat_spring[j].y_position) && (y + 60 < plat_spring[j].y_position + 14) && (dy > 0)) {
			dy = -20;
		
		}
		//the check for cracked platforms
		if ((x + 50 > plat_bad[j].x_position) && (x + 20 < plat_bad[j].x_position + 68)
			&& (y + 60 > plat_bad[j].y_position) && (y + 60 < plat_bad[j].y_position + 14) && (dy > 0)) {
			dy = abs(dy*2.5);
		}
		//the check for flyed platforms
		if ((x + 50 > plat_fly[j].x_position) && (x + 20 < plat_fly[j].x_position + 68)
			&& (y + 60 > plat_fly[j].y_position) && (y + 60 < plat_fly[j].y_position + 14) && (dy > 0)) {
			dy = -30;
			sf::Texture image;
			image.loadFromFile(IMAGE_BLUE);
			doodler.update(image);
		}
	}
	return true;
}

//the function to pause the player
void GameMachine::pause_player() {
	if (character.isPaused) {
		character.dy = 0;
	} else {
		character.dy = -10;
	}
}

//a new feature to create images of lives of the player
void GameMachine::draw_lives(int & lifetime, sf::RenderWindow &win){
	sf::Texture heart;
	heart.loadFromFile(IMAGE_HEART);
	sf::Sprite sHeart(heart);
	for (int i = 0; i < lifetime; i++) {
		sHeart.setPosition(300 + i*25 , 10);
		win.draw(sHeart);
	}
}

//scroll the platforms
// all platform y values rerender with dy
// When a platform goes below the view of the screen, it is redrawn at the
// top of the screen with a random x coordinate.
void GameMachine::scroll_platforms(int &y, int &h, float &dy) {
	//normal platforms
	for (int i = 0; i < PLAT_SIZE; i++) {
		y = h; // doodle's y position set to 200
		plat[i].y_position = plat[i].y_position - dy;

		if (plat[i].y_position> MACHINE_HEIGHT) {
			plat[i].y_position = 0;
			plat[i].x_position = std::rand() % MACHINE_LENGTH;
			character.score += 1;
			if (character.score % 7 == 0) {
				renew_monster();
			}
		}
	}
	
	for (int j = 0; j < SPECIAL_PLATFORM_SIZE; j++) {
		y = h; // doodle's y position set to 200
		//platforms with spring
		plat_spring[j].y_position = plat_spring[j].y_position - dy;
		if (plat_spring[j].y_position> MACHINE_HEIGHT) {
			plat_spring[j].y_position = 0;
			plat_spring[j].x_position = std::rand() % MACHINE_LENGTH;
			character.score += 3;
			if (character.score % 7 == 0) {
				renew_monster();
			}
		}
		//platforms that would crack
		plat_bad[j].y_position = plat_bad[j].y_position - dy;
		if (plat_bad[j].y_position> MACHINE_HEIGHT) {
			plat_bad[j].y_position = 0;
			plat_bad[j].x_position = std::rand() % MACHINE_LENGTH;
			character.score -= 1;
		}
		//platforms that would accelerate
		plat_fly[j].y_position = plat_fly[j].y_position - dy;
		if (plat_fly[j].y_position> MACHINE_HEIGHT) {
			plat_fly[j].y_position = 0;
			plat_fly[j].x_position = std::rand() % MACHINE_LENGTH;
			character.score += 1;
		}
	}
}

// set the character to be dead
int GameMachine::setDeath(sf::Texture &texture) {
	character.isDead = true;
	sf::Texture dead;
	dead.loadFromFile(IMAGE_DEAD);
	texture.update(dead);
	score_history.push_back(character.score);
	return character.score;
}

//a helper funtion to update the level of the character
int GameMachine::level_up(sf::Texture &texture) {
	if (character.score % 1000 == 0) {
		character.level += 1;
	}
	if (character.score > 500) {
		sf::Texture super;
		super.loadFromFile(IMAGE_LEVEL_UP);
		texture.update(super);
	}
	return character.level;
}

// a function of keyboard controller
void GameMachine::control_by_key(sf::Texture &doodler) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		character.x_value += 3;
		if (character.x_value > MACHINE_LENGTH) {
			character.x_value = 0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		character.x_value -= 3;
		if (character.x_value < 0) {
			character.x_value = MACHINE_LENGTH;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		character.y_value += 5;
		sf::Texture image;
		image.loadFromFile(IMAGE_FLY);
		doodler.update(image);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		character.dy += 0.03;
		sf::Texture image;
		image.loadFromFile(IMAGE_NINJA);
		doodler.update(image);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		//character.isPaused = !character.isPaused;
		//pause_player();
	}
}

//function to change the doodler into super-jumpy mode
sf::Sprite GameMachine::super_costumn() {
	sf::Texture image;
	image.loadFromFile(IMAGE_LEVEL_UP);
	sf::Sprite super_(image);
	return super_;
}

// a helper function to get the image of a dead doodler
sf::Texture GameMachine::death_image() {
	sf::Texture dead;
	dead.loadFromFile(IMAGE_DEAD);
	return dead;
}

// a method to restart the game
void GameMachine::restart_game(std::ofstream &score_file) {
	character.isDead = false;
	character.score = 0;
	character.level = 1;
	character.lifetime = 3;
	//write in file
	//score_file << "score of this game: " << character.score << std::endl;
	//score_file.close();
	start_game();
}

//the method to start the game
void GameMachine::start_game() {
	//srand(time(0));
	sf::RenderWindow window(sf::VideoMode(400, 533), "Doodle Jump!");
	window.setFramerateLimit(60);
	sf::Texture background, platform, doodler, monsterImage, monsterImage2, spring_platform, bad_platform, fly_platform;
	//load all images from image file
	background.loadFromFile(IMAGE_BACKGROUND);
	platform.loadFromFile(IMAGE_PLATFORM);
	doodler.loadFromFile(IMAGE_NINJA);
	monsterImage.loadFromFile(IMAGE_MONSTER);
	monsterImage2.loadFromFile(IMAGE_MONSTER2);
	spring_platform.loadFromFile(IMAGE_PLATFORM_SPRING);
	bad_platform.loadFromFile(IMAGE_PLATFORM_BAD);
	fly_platform.loadFromFile(IMAGE_PLATFORM_FLY);

	sf::Sprite sBackground(background), sPlat(platform), sPers(doodler), sMonster(monsterImage), sMonster2(monsterImage2);
	sf::Sprite sSpring(spring_platform);
	sf::Sprite sBadPlat(bad_platform);
	sf::Sprite sFlyPlat(fly_platform);

	generate_platforms();
	generate_monster();

	int height = 200;

	while (window.isOpen()) {
		sf::Event e;
		std::ofstream score_file;
		score_file.open("Text.txt");
		while (window.pollEvent(e)) {
			if (character.isDead) {
				window.close();
				score_file.open(FILENAME_WRITE_IN);
				score_file << "The score of this turn is: " << character.score << std::endl;
				score_file.close();
				restart_game(score_file);
			}
			if (e.type == sf::Event::Closed) {
				window.close();
			}

		} // END EVENT LOOP

		control_by_key(doodler);

		//------ jumpy --------
		character.dy += 0.2; // dy is vertical acceleration
		character.y_value += character.dy;

		if (character.y_value > 500) {
			character.dy = -10;
			if (character.y_value > 450 - 5) {
				character.lifetime--;
				if (character.lifetime == 0) {
					setDeath(doodler);
				}
			}
		}

		//if the monster attacked the character, it would die
		if (abs(character.y_value - monster.y_position) < 10
			&& abs(character.x_value - monster.x_position) < 10 || abs(character.y_value - monster2.y_position) < 10
			&& abs(character.x_value - monster2.x_position) < 10) {
			character.lifetime--;
			if (character.lifetime == 0) {
				setDeath(doodler);
			}
		}

		check_bounce(character.x_value, character.y_value, character.dy, doodler);

		if (character.y_value < height) {
			scroll_platforms(character.y_value, height, character.dy);
			level_up(doodler);
		}

		sPers.setPosition(character.x_value, character.y_value);
		window.draw(sBackground);
		window.draw(sPers);

		// Draws the platforms on the screen
		for (int i = 0; i < PLAT_SIZE; i++) {
			sPlat.setPosition(plat[i].x_position, plat[i].y_position);
			window.draw(sPlat);
		}
		for (int j = 0; j < SPECIAL_PLATFORM_SIZE; j++) {
			sSpring.setPosition(plat_spring[j].x_position, plat_spring[j].y_position);
			window.draw(sSpring);
			sBadPlat.setPosition(plat_bad[j].x_position, plat_bad[j].y_position);
			window.draw(sBadPlat);
			sFlyPlat.setPosition(plat_fly[j].x_position, plat_fly[j].y_position);
			window.draw(sFlyPlat);
		}

		sMonster.setPosition(monster.x_position, monster.y_position);
		window.draw(sMonster);
		sMonster2.setPosition(monster2.x_position, monster2.y_position);
		window.draw(sMonster2);

		//draw the hearts which reperents the current lives of the character
		draw_lives(character.lifetime, window);

		//-------------write text --------------
		std::stringstream ss;
		ss.str("");
		ss << "Score: " << character.score;

		//set the text display of the score of this game
		sf::Font font;
		font.loadFromFile("images/al-seana.ttf");

		sf::Text score_text;
		score_text.setCharacterSize(30);
		score_text.setPosition(10, 10);
		sf::Color black(sf::Color(0, 0, 255));
		score_text.setColor(black);
		score_text.setFont(font);
		score_text.setString(ss.str());
		window.draw(score_text);

		ss.str("");
		ss << "Height: " << MACHINE_LENGTH - character.y_value + character.score * 101;
		sf::Text y_text;
		y_text.setCharacterSize(30);
		y_text.setPosition(10, 60);
		y_text.setColor(black);
		y_text.setFont(font);
		y_text.setString(ss.str());
		window.draw(y_text);

		//if the character is dead, it would just keep falling
		if (character.isDead) {
			ss.str("");
			ss << "NO!"<< std::endl;
			ss << "Score: " << std::endl;
			ss << character.score;
			sf::Text dead_text;
			dead_text.setCharacterSize(150);
			dead_text.setPosition(90, 40);
			dead_text.setColor(sf::Color(23, 34, 56));
			dead_text.setFont(font);
			dead_text.setString(ss.str());
			window.draw(dead_text);
		}
		window.display();
	}
}