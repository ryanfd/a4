#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <iostream>

#include "HashTable.h"

using std::string;
using std::vector;
using std::ifstream;
using std::runtime_error;
using std::istream_iterator;
using std::swap;

// Opens a file and reads the contents into a vector
// PARAM: infile = name of the file to be opened
// PRE: the file contains words separated by white space
// POST: returns a vector containing the contents of infile
vector<string> readFile(string infile)
{
	ifstream ist(infile.c_str());
	if (ist.fail())
		throw runtime_error(infile + " not found");
	istream_iterator<string> start(ist), end;
	vector<string> result(start, end);
	
	ist.close();
	return result;
}

vector<string> incorrectLetter(HashTable & ht, string word)
{
	vector<string> result;
	vector<string> checkList;

	if (!ht.find(word)) {
		string temp = word;
		for (int pos=0; pos<word.length(); pos++) {
			for (int i=0; i<word.length(); i++) {
				if (i == pos) {
					char altLetter = 'a';
					for (int j=0; j<26; j++) {
						if (temp[pos] != altLetter) {
							temp[pos] = altLetter;
							checkList.push_back(temp);
						}
						altLetter++;
					}
				}
			}
		}
		for (int i=0; i<checkList.size(); i++) {
			if (ht.find(checkList[i])) result.push_back(checkList[i]);
		}
	} else {
		result.push_back(word);
	}

	return result;
}

// words made by space in word
vector<string> missingSpace(HashTable & ht, string word)
{
	vector<string> result;

	if (!ht.find(word)) {
		for (int pos = 1; pos<word.length(); pos++) { // don't put space before or after word
			string temp;
			for (int j=0; j<word.length(); j++) {
				if (j < pos) temp += word[j];
				else if (j == pos) {
					// first space then letter
					temp += " ";
					temp += word[j];
				} else {
					temp += word[j];
				}
			}
			if (ht.find(temp)) result.push_back(temp);
		}
	} else {
		result.push_back(word);
	}

	return result;
}


// one letter difference
vector<string> extraLetter(HashTable & ht, string word)
{
	vector<string> result;

	if (!ht.find(word)) {
		for (int i=0; i<word.length(); i++) {
			string temp = word;
			temp.erase(temp.begin() + i);
			// cout << temp << endl;
			if (ht.find(temp)) result.push_back(temp);
		}
	} else {
		result.push_back(word);
	}

	return result;
}

// swap 2 neighbouring letters
vector<string> transition(HashTable & ht, string word)
{
	vector<string> result;

	if (!ht.find(word)) {
		for (int i=0; i<word.length()-1; i++) { // last letter will be checked
			string temp = word;
			swap(temp[i], temp[i+1]);
			if (ht.find(temp)) result.push_back(temp);
		}
	} else {
		result.push_back(word);
	}

	return result;
}
