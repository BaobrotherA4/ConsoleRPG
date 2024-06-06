#include "C110152325_Puzzle.h"

C110152325_Puzzle::C110152325_Puzzle(string filename) {

	this->correctAnswer = 0;
	ifstream infile(filename);

	int nr0fAns = 0;
	string answer = "";
	int correntAns = 0;

	if (infile.is_open()) {
		getline(infile, this->question);
		infile >> nr0fAns;
		infile.ignore();

		for (size_t i = 0; i < nr0fAns; i++)
		{
			getline(infile, answer);
			this->answers.push_back(answer);
		}

		infile >> correntAns;
		this->correctAnswer = correntAns;
		infile.ignore();
	}
	else
		throw("Could not open puzzle!");
	  
	infile.close();
}
string C110152325_Puzzle::getAsString() {
	string answers = "";

	for (size_t i = 0; i < this->answers.size(); i++)
	{
		answers += to_string(i) + "¡G" + this->answers[i] + "\n";
	}
	/*return this->qusetion + "\n" + "\n"
		+ answers + "\n"
		+ to_string(this->correctAnswer) + "\n";*/

	return this->question + "\n" + "\n"
		+ answers + "\n";
		
}



C110152325_Puzzle::~C110152325_Puzzle() {

}
