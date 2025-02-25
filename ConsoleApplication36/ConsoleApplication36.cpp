// ConsoleApplication36.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "Dictionary.h"
#include "HTMLWriter.h"
using namespace std;

// prints the menu
void printHeader()
{
    cout << "******************\n";
    cout << "* Enter Choice   *\n";
    cout << "******************\n";
    cout << "1. Search word meaning   *\n";
    cout << "2. Longest Word          *\n";
    cout << "3. Words ending on 'logy'*\n";
    cout << "4. Search rhyming words  *\n";
    cout << "5. Search anagrams       *\n";
    cout << "6. Enter string of letters to find highest scrabble score*\n";
    cout << "7. Exit          *\n";
    cout << "******************\n";    
}

int main()
{
    Dictionary_Part01 testDictionary;
    testDictionary.load("dictionary2021.txt");
    cout << "Creating html files" << endl;
    HTMLWriter writer(&testDictionary);
    writer.writeIntroductionPage("introduction.html");
    for (char i = 'A'; i <= 'Z'; i++)
    {
        string pagename(1,i);
        pagename += ".html";
        writer.writeIndexesDictionary(i, pagename);
        cout << "*";
    }
    cout << "\nSuccessfully created html files" << endl;
    bool exit = false;
    string userChoice;
    do
    {
        printHeader();
        cin >> userChoice;

        if (userChoice.length() != 0)
        {

            if (userChoice[0] == '1')
            {
                cin.ignore();
                cout << "Enter the word to search for its meaning : ";
                string word;
                cin >> word;
                testDictionary.printWordInfo(word);
                //testDictionary.testWords();
            }
            else if (userChoice[0] == '2')
            {
                testDictionary.printLongestWord();
            }
            else if (userChoice[0] == '3')
            {
                testDictionary.logyWords();
            }
            else if (userChoice[0] == '4')
            {
                cin.ignore();
                cout << "Enter the word to search for rhyming words : ";
                string word;
                cin >> word;
                testDictionary.rhymingWords(word);
                //testDictionary.printWordInfo(word);
                //testDictionary.testWords();
            }
            else if (userChoice[0] == '5')
            {
                cin.ignore();
                cout << "Enter the word to search for rhyming words : ";
                string word;
                cin >> word;
                testDictionary.printAnagrams(word);
            }
            else if (userChoice[0] == '6')
            {
                cin.ignore();
                cout << "Enter the letters string to find with highest scrabble score : ";
                string word;
                cin >> word;
                testDictionary.highestScrabbleScore(word);
            }
            else if (userChoice[0] == '7')
            {
                exit = true;
            }
        }
       
    } while (!exit);
    
}

