//Ariosto Kuit CS 351
// Project1CS351.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//will read file and search and print the word
void SimpleGrep(string filename,string findWord) {
	
	ifstream textfile;
	textfile.open(filename); //open the file 

	if (textfile.fail()) {
		cerr << "Cannot open file\n"; //Error states that file cannot be open 
		exit(1);
	}

	string line;
	
	//will loop the text file and input stream the texts
	while (getline(textfile,line)) {
		
		size_t foundWord = line.find(findWord); //set the positition of the found desire word

		if (foundWord != string::npos) { cout << line << " "; }
	}
}

int main()
{
	string filename, searchWord;

	//enter the text file and word user desire to search
	cout << "simple-grep ";
	cin >> filename;
	cin >> searchWord;

	SimpleGrep(filename,searchWord);

	return 0;
}
