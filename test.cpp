#define CATCH_CONFIG_MAIN
#include <SFML/Graphics.hpp>
#include "catch.hpp"
#include "../gameMachine.h"
#include "../scoreMachine.h"
#include <iostream>
#include <vector>

//---score machine test
TEST_CASE("add record test"){
	ScoreMachine score_machine;
	long new_score = 1222L;
	REQUIRE (1 == score_machine.add_record(new_score));
}

TEST_CASE("clear record test"){
	ScoreMachine score_machine;
	long new_score = 1222L;
	score_machine.add_record(new_score);
	score_machine.add_record(new_score);	
	score_machine.clear_record();
	REQUIRE (0  == score_machine.score_length);
	REQUIRE (0  == score_machine.height_length);
}

TEST_CASE("clear last record test"){
	ScoreMachine score_machine;
	long new_score = 1222L;
	score_machine.add_record(new_score);
	score_machine.add_record(new_score);	
	score_machine.clear_last_record();
	REQUIRE (1  == score_machine.score_length);
	REQUIRE (1  == score_machine.height_length);
}

//--game machine tests
TEST_CASE("check bouce test"){
	GameMachine game_machine;
	game_machine.setDead(true);
	sf::Texture doodler;
	REQUIRE (false == game_machine.check_bound(2,2,0.2,doodler));
	game_machine.setDead(false);
	REQUIRE (true == game_machine.check_bound(2,2,0.2,doodler));
}

TEST_CASE("set Death test"){
		GameMachine game_machine;
		game_machine.set_score(122);
		REQUIRE(122 == game_machine.get_character().score);
		REQUIRE(122 == game_machine.set_Death());
}

TEST_CASE("level up test"){
	GameMachine game_machine;
	game_machine.set_level(3);
	REQUIRE(3 == game_machine.get_character().level);
	game_machine.level_up();
	REQUIRE(4 == game_machine.get_character().level);
}