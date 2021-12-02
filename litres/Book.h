#pragma once
#include <string>
#include <iostream>
using namespace std;

class Book
{
public:
	Book(string aAuthor, string aName, int aCreation, int aRelease, int aPrice);
	Book(const Book& other);
	void operator = (const Book& other);
	Book(); // конструктор без параметров
	void setYearRelease(int aRelease);
	void setPrice(int aPrice);
	void setAuthor(string aAuthor);
	void setName(string aName);
	void setYearCreation(int aCreation);
	string getAuthor() const;
	string  getName() const;
	int getYearCreation() const;
	int getYearRelease() const;
	int getPrice() const;
	unsigned getID() const;
	virtual void readFromConsole(); 
	virtual void writeToStream(ostream&); // вывод в произвольный поток
private:
	unsigned ID;
	string author;
	string name;
	int yearCreation;
	int yearRelease;
	int price;
	void clone(const Book& other);
	virtual void dummy() = 0;   // для обеспечения абстрактности класса
	static unsigned nextID;  // для обеспечения уникальности ID

	friend ostream& operator << (ostream& os, const Book& b);
};

