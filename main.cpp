#include "HashTable.cpp"
#include "spellcheck.h"

#include <iostream>
#include <random>
#include <vector>

using std::cout;	
using std::endl; 
using std::vector;

void initTest();
void testInsert();
void testOneOff();
void testTransition();
void testMissing();
vector<string> readFile(string infile);

int main()
{
	// initTest();
	// testInsert();
	// testOneOff();
	// testTransition();
	testMissing();
}

int horner(const string & s) 
{ 
    int result = charConvert(s[0]);  // count from first char
  
    // horner's method
    for (int i=1; i<s.length(); i++) 
        result = result*32 + charConvert(s[i]); 
  
    return result; 
} 

void testMissing()
{
	HashTable h(10);
	h.insert("rate at");
	h.insert("rat eat");
	h.insert("scone");
	h.print();

	vector<string> list = missingSpace(h, "rateat");
	for (int i=0; i<list.size(); i++) {
		cout << i+1 << ") " << list[i] << endl;
	}
}

void testTransition()
{
	HashTable h(10);
	h.insert("art");
	h.insert("tar");
	h.insert("rat");
	h.insert("ball");
	h.print();

	vector<string> list = transition(h, "atr");
	for (int i=0; i<list.size(); i++) {
		cout << i+1 << ") " << list[i] << endl;
	}
}

void testOneOff()
{
	HashTable h(10);
	h.insert("chat");
	h.insert("hate");
	h.insert("hate");
	h.insert("hat");
	h.insert("cat");
	h.print();

	vector<string> list = extraLetter(h, "chate");
	for (int i=0; i<list.size(); i++) {
		cout << i+1 << ") " << list[i] << endl;
	}
}

void initTest()
{
	HashTable h;
	cout << h.maxSize() << endl;
	HashTable h2(h);
	cout << h2.maxSize() << endl;
	HashTable h3 = h2;
	cout << h3.maxSize() << endl;

	HashTable h4(7);
	cout << h4.maxSize() << endl;
}

void testInsert()
{
	HashTable h(3);

	vector<string> list = readFile("wordList1000.txt");
	for (int i=0; i<5; i++) {
		int index = rand() % list.size();
		cout << list[index] << endl;
		h.insert(list[index]);
	}
	// h.insert("level");

	h.print();
}