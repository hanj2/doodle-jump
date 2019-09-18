#pragma once
#include <SFML/Graphics.hpp>
#ifndef SCOREMACHINE_H
#define SCOREMACHINE_H
#include <vector>

const int static TOP_RECORD = 10;
class ScoreMachine {
	std::vector<long> score_history;
	std::vector<long> height_history;
	int played_times = 0;
	int score_length;
	int height_length;

public:
	int add_record(long score);
	int clear_record();
	int clear_last_record();
	void write_score_into_file();
};

#endif // SCOREMACHINE