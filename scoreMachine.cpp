#include "scoreMachine.h"
#include <iostream>
#include <fstream>

const static int product = 101;
const static std::string SCOREHISTORY = "Text.txt";

// the method to add a record to the machine
int ScoreMachine::add_record(long score) {
	score_history.push_back(score);
	long height = score * product;
	height_history.push_back(height);
	score_length++;
	height_length++;
	return (score_length + height_length) / 2;
}

// a function to clear the last record
int ScoreMachine::clear_last_record() {
	score_history.pop_back();
	score_length--; 
	height_history.pop_back();
	height_length--;
	return score_length;

}

void ScoreMachine::write_score_into_file(){
}

//the function to clear the record completely
int ScoreMachine::clear_record() {
	while (played_times > 0) {
		score_history.pop_back();
		height_history.pop_back();
		played_times--;
	}
	score_length = 0;
	height_length = 0;
	played_times = 0;
	return played_times;
}
