#pragma once

#include<string>

using std::string;

class HashTable 
{
public:
	// constructors, destructors, operator
	HashTable();
	HashTable(int);
	HashTable(const HashTable &);
	~HashTable();
	HashTable & operator=(const HashTable &);

	// mutators
	void insert(string);

	// accessors
	bool find(string);
	int size() const;
	int maxSize() const;
	float loadFactor() const;

	// DELETE LATER
	void print();

private:
	string* arr;
	int capacity;
	int h2;
	int currentNumItems;

	// helpers
	void copyTable(const HashTable &); // deep copy function
	bool isPrime(int); // check if number is prime
	int findPrime(int); // find closest prime equal to or greater than
	int horner(const string &); // get unique numerical value of string
	int hashFunction(const string &); // hash function
	int hashFunction2(const string &); // double hash function
};