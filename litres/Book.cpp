#include "Book.h"

unsigned Book::nextID = 0;

Book::Book(string aAuthor, string aName, int aCreation, int aRelease, int aPrice) : ID(nextID++)
{
	setName(aName);
	setAuthor(aAuthor);
	setYearCreation(aCreation);
	setYearRelease(aRelease);
	setPrice(aPrice);
}
void Book::setAuthor(string aAuthor)
{
	author = aAuthor;
}

void Book::setName(string aName)
{
	name = aName;
}

void Book::setYearCreation(int aCreation)
{
	if (aCreation > 2021 || aCreation <= 0)
		throw exception("setYearCreation: invalid creation year!");
	yearCreation = aCreation;
}

string Book::getAuthor() const
{
	return author;
}

string Book::getName() const
{
	return name;
}

int Book::getYearCreation() const
{

	return yearCreation;
}

Book::Book(const Book& other) : ID(nextID++)
{
	clone(other); // автоматическое формирование id
}

void Book::operator=(const Book& other)
{
	clone(other);
}

Book::Book()
{
	readFromConsole();
}

void Book::setYearRelease(int aRelease)
{
	if (aRelease < 1900 || aRelease > 2021)
		throw exception("setYearRelease: invalid release year!");
	yearRelease = aRelease;
}

void Book::setPrice(int aPrice)
{
	if (aPrice < 0)
		throw exception("setPrice: invalid book price");
	price = aPrice;
}

int Book::getYearRelease() const
{
	return yearRelease;
}

int Book::getPrice() const
{
	return price;
}

unsigned Book::getID() const
{
	return ID;
}

void Book::readFromConsole()
{
	int t;
	string s;

	cout << "Введите имя автора: ";
	getline(cin, s);
	setAuthor(s);
	cout << "Введите название произведения: ";
	getline(cin, s);
	setName(s);
	cout << "Введите год создания произведения: ";
	while (true) {  // бесконечный цикл
		cin >> t;
		try {
			setYearCreation(t);
			break;
		}
		catch (...) {
			cout << "Вы ошиблись, повторите ввод!\n";
		}
	}
	cout << "Введите год издания книги: ";
	while (true) {
		cin >> t;
		try {
			setYearRelease(t);
			break;
		}
		catch (...) {
			cout << "Вы ошиблись, повторите ввод!\n";
		}
	}
	cout << "Введите цену книги: ";
	while (true) {
		cin >> t;
		try {
			setPrice(t);
			break;
		}
		catch (...) {
			cout << "Вы ошиблись, повторите ввод!\n";
		}
	}
}

void Book::writeToStream(ostream& os)
{
	os << "Book ID: " << ID << " Author: " << author << " Name: " << name <<
		" Creation year: " << yearCreation << " Release year: " << yearRelease << " Price: " << price << "\n";
}

void Book::clone(const Book& other)
{
	name = other.name;
	author = other.author;
	yearCreation = other.yearCreation;
	yearRelease = other.yearRelease;
	price = other.price;
}

ostream& operator<<(ostream& os, const Book& b)
{
	os << "Book ID: " << b.ID << " Author: " << b.author << " Name: " << b.name <<
		" Creation year: " << b.yearCreation << " Release year: " << b.yearRelease << " Price: " << b.price << "\n";
	return os;
}
