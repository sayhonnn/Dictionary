#pragma once

#include "Dictionary.h"


class HTMLWriter
{
	Dictionary_Part01* dict;
	string style;
public:
	HTMLWriter(Dictionary_Part01* load)
	{
		this->dict = load;
		ifstream stylefile;
		stylefile.open("style.txt");
		string line;
		while (!stylefile.eof())
		{
			getline(stylefile, line);
			style += line;
		}
		stylefile.close();
	}
	//Creates an introductory html page from where user can traverse to any page
	void writeIntroductionPage(string pagefilename)
	{
		ofstream datafile;
		datafile.open(pagefilename.c_str());

		datafile << "<!DOCTYPE html> <html> <head> <title>Oxford Dictionary</title> <style>"
		"h1{ text-align:center; font-family: Verdana, Geneva, Tahoma, sans-serif; color:darkcyan; font-size:100px; }"
		"table{ width: 500px; text - align: center; padding - left: 100px; }"
		"tr { background-color: rgb(191, 216, 216); text-align: center; padding-right: 100px; }"
		"td { font-family: Verdana, Geneva, Tahoma, sans-serif; font-size: xx-large; border-radius: 50%; color: darkcyan; padding-right: 100px;"
		"padding-left: 100px; padding-top: 30px; padding-bottom: 30px;"
		"text-align: center; }"
		"a:link{"
		  "color: green;"
		  "background-color: transparent;"
		  "text-decoration: none;"
		"}"

		"a:visited{"
		  "color: darkcyan;"
		  "background-color: transparent;"
		  "text-decoration: none;"
		"}"

		"a:hover{"
		  "color: rgb(4, 77, 77);"
		  "background-color: transparent;"
		  "text-decoration: none;"
		"}"

		"a:active{"
		  "color: rgb(3, 44, 44);"
		  "background-color: transparent;"
		  "text-decoration: none;"
		"}"
			"</style>"
			"</head>"
			"<body>"

			"<h1>Oxford's Dictionary</h1>"
			"<table>"
			"<tr>"
			"<td><a href = \"A.html\">A</a></td>"
			"<td><a href = \"B.html\">B</a></td>"
			"<td><a href = \"C.html\">C</a></td>"
			"<td><a href = \"D.html\">D</a></td>"
			"<td><a href = \"E.html\">E</a></td>"
			"<td><a href = \"F.html\">F</a></td>"
			"</tr>"
			"<tr>"
			"<td><a href = \"G.html\">G</a></td>"
			"<td><a href = \"H.html\">H</a></td>"
			"<td><a href = \"I.html\">I</a></td>"
			"<td><a href = \"G.html\">G</a></td>"
			"<td><a href = \"K.html\">K</a></td>"
			"<td><a href = \"L.html\">L</a></td>"
			"</tr>"
			"<tr>"
			"<td><a href = \"M.html\">M</a></td>"
			"<td><a href = \"N.html\">N</a></td>"
			"<td><a href = \"O.html\">O</a></td>"
			"<td><a href = \"P.html\">P</a></td>"
			"<td><a href = \"Q.html\">Q</a></td>"
			"<td><a href = \"R.html\">R</a></td>"
			"</tr>"
			"<tr>"
			"<td><a href = \"S.html\">S</a></td>"
			"<td><a href = \"T.html\">T</a></td>"
			"<td><a href = \"U.html\">U</a></td>"
			"<td><a href = \"V.html\">V</a></td>"
			"<td><a href = \"W.html\">W</a></td>"
			"<td><a href = \"X.html\">X</a></td>"
			"</tr>"
			"<tr>"
			"<td><a href = \"Y.html\">Y</a></td>"
			"<td><a href = \"Z.html\">Z</a></td>"
			"</tr>"
			"</table>"

			"</body>"
			"</html>" << endl;

		datafile.close();
	}
	//This function takes character ch as input which ranges from 'A' to 'Z'
	//This function also take pagename as input
	//Outputs dictionary in html format in .html file, the dictionary consist of word starting with ch character
	void writeIndexesDictionary(char ch, string pagename)
	{
		ofstream datafile;
		datafile.open(pagename.c_str());
		//Check if file was created

		
		//Write data in the file
		datafile << "<!DOCTYPE html> <html> <head> <title>" << (char)toupper(ch)  << " 's Words</title>";
		datafile << style;
		datafile << "</head><body>" << endl;
		datafile << "<h1> Index " << (char)toupper(ch) << "'s</h1>";
		datafile << "<h2><a href=\"introduction.html\">Back to Introduction page</a></h2>" << endl;
		datafile << "<table>" << endl;
		for (Word a : dict->getDictionary())
		{
			if (toupper(a.getWord()[0]) == ch)
			{
				datafile << "<tr>" << endl;
				datafile << "<td>" << a.getWord() << "</td>" << endl;
				datafile << "<td>" << a.getType() << "</td>" << endl;
				datafile << "<td>" << a.getDefinition() << "</td>" << endl;
				datafile << "</tr>" << endl;
			}
		}
		
		datafile << "</table>" << endl;
		datafile << "</body>" << endl;
		datafile << "</html>" << endl;
		datafile.close();
	}
};