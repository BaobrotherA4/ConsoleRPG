#pragma once

#include<string>
#include<fstream>
#include<vector>


using namespace std;
class C110152325_Puzzle 
{
private:

	string question;
	vector<string> answers;
	int correctAnswer;

public:
	C110152325_Puzzle(string filename);
	string getAsString();
	virtual ~C110152325_Puzzle();
};


