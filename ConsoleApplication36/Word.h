#pragma once
#include <iostream>
#include <string>

using namespace std;

class Word
{
private:
	string word;
	string type;
	string definition;

public:
	Word(string word, string type, string definition)
	{
		this->word = word;
		this->type = type;
		this->definition = definition;
	}
	string getWord() { return word; }
	string getType() { return type; }
	string getDefinition() { return definition; }

	void printDefinition()
	{
		cout << definition << "\n";
	}
};
