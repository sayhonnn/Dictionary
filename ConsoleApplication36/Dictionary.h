#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>

#include "Word.h";

using namespace std;

#define TOTALALPHABETS 26
int scrabbleScore[TOTALALPHABETS] = { 1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10 };
class Dictionary_Part01
{
private:
	vector<Word> theDictionary;

public:
	// this will load the given dictionary file (text format), which needs to have the
	// format:
	// word [type]
	// definition - list of definitions separated by ';'
	// blank line
	//
	// input: fineName - name of the file to load
	void load(string fileName)
	{
		// open the file
		ifstream myfile(fileName);
		if (myfile.is_open())
		{
			string word, type, definition;
			// loop for each word in the file
			while (!myfile.eof())
			{
				// first line holds the ID
				getline(myfile, word, ' '); // read up to the space
				getline(myfile, type); // read the rest of the line after the space
				getline(myfile, definition); // read the definition line

				// the quickest, but roughest method of separating definitions
				// with blank lines - this also does the semicolons that are meant
				// to be part of the definition, rather than separators.
				replace(definition.begin(), definition.end(), ';', '\n');

				Word temp(word, type, definition);

				theDictionary.push_back(temp);
				getline(myfile, word); // read the blank line in to skip over it
			}
			// close the file
			myfile.close();

		}
		else
		{
			cout << "File not found!!!\n";
		}
	}
	/*. If that exact word is in the dictionary, print the word’s definition, 
	pre-pended with the word type using the following scheme: Noun (n.), Verb (v.), Adverb (adv.), 
	Adjective(adj.), Preposition(prep) MiscWords(misc.),ProperNouns (pn.), NounAndVerb (n. v.). 
	If the word is not in the dictionary print ‘word not found.’*/
	void printWordInfo(string word)
	{
		for (Word a : theDictionary)
		{
			if (a.getWord() == word)
			{
				cout << a.getType() << " " << a.getDefinition() << endl;
				int score = 0;
				//Check if word type is misc or proper noun
				//if so then don't calculate scrabble score
				if (a.getType() != "[misc]" && a.getType() != "[pn]")
				{
					score = calculateScrabbleScore(a.getWord());
				}
				cout << "Scrabble score is : " << score << endl;
				return;
			}
			
		}
		cout << "Word not found.\n";
	}
	//Check if word qualifies for scrabble word 
	//if it does return the calculate scrabble score
	//else returns 0
	int calculateScrabbleScore(string scrabbleWord)
	{
		int score = 0;
		//Checks if words contains hyphen
		//if so then simply return 0
		if (scrabbleWord.find("-") != string::npos )
		{
			return score;
		}
		//Calculate the scrabble for individual letter and add it to score
		for (int i = 0; i < scrabbleWord.length(); i++)
		{
			if (isalpha(scrabbleWord[i]))
			{
				int index = toupper(scrabbleWord[i]) - 65;
				score += scrabbleScore[index];
			}
		}

		return score;
	}
	//Print anagrams of the word passed as parameter from the dictionary
	void printAnagrams(string word)
	{
		string toSort = word;
		sort(toSort.begin(), toSort.end());
		cout << "Word is : " << word << endl;
		cout << "Anagrams are :";
		for (Word a : theDictionary)
		{
			//If same length and after sorting they both make same word
			if (a.getWord().length() == word.length() && a.getWord() != word)
			{
				string sortCurrent = a.getWord();
				sort(sortCurrent.begin(), sortCurrent.end());
				if (sortCurrent == toSort)
				{
					cout << a.getWord() << "\t";
				}
			}
		}
		cout << endl;
	}
	/*Find the longest word in the dictionary and print it to screen */
	void printLongestWord()
	{
		string word = "";
		for (Word a : theDictionary)
		{
			if (a.getWord().length() > word.length())
			{
				word = a.getWord();
			}
		}
		cout << "Longest Word is : " << word << endl;
	}
	//Reports all the words ending on 'logy' and their lenght is at most 7
	void logyWords()
	{
		for (Word a : theDictionary)
		{
			string word = a.getWord();
			if (word.length() <= 7 && word.length() > 3 && word.substr(word.length() - 4) == "logy" )
			{
				cout << word << endl;
			}
		}
	}
	/*report all words that rhyme (by checking if the last 3 letters are the same) */
	void rhymingWords(string word)
	{
		string subWord = "";
		if (word.length() > 3)
		{
			subWord = word.substr(word.length() - 3);
		}
		else
		{
			subWord = word;
		}
		cout << "Word is : " << word << endl;
		cout << "Rhyming words are : ";
		for (Word a : theDictionary)
		{
			string rhymer = a.getWord();
			if (rhymer.length() > 3 && rhymer.substr(rhymer.length() - subWord.length()) == subWord )
			{
				cout << rhymer << "\t";
			}
		}
		cout << endl;
	}
	// test function that just prints each word character
	// by character - separated with '*' - just to show
	// how to loop thorugh each word in the dictionary.
	// * first 100 words only
	void testWords()
	{
		int j = 0;
		int wordsToPrint = 100;
		for (Word a : theDictionary)
		{
			string wordName = a.getWord();
			for (int i = 0; i < wordName.length(); i++)
			{
				cout << wordName[i] << "*";
			}
			cout << "\n";
			j++;
			if (j>wordsToPrint)
			{
				break;
			}
		}
	}
	//Calculates the word with highest scrabble score among string of letters
	void highestScrabbleScore(string letters)
	{
		string currentBestWord = "";
		int bestScrabble = -1;
		for (Word a : theDictionary)
		{
			if (letters.find(a.getWord()) != string::npos)
			{
				int currentScrabbleScore = calculateScrabbleScore(a.getWord());
				if (currentScrabbleScore > bestScrabble)
				{
					bestScrabble = currentScrabbleScore;
					currentBestWord = a.getWord();
				}
			}
		}
		if (bestScrabble != -1)
		{
			cout << "Word with highest srabble score is : " << currentBestWord << endl;
			cout << "Scrabble score is : " << bestScrabble << endl;
		}
		else
		{
			cout << "No suitable word for scrabble score exists in this string of letters" << endl;
		}
	}
	//Return the vectors of dictionary
	vector<Word>& getDictionary()
	{
		return theDictionary;
	}
};
