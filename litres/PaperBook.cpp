#include "PaperBook.h"


PaperBook::PaperBook() : Book()
{
	readPaperFromConsole();
}

PaperBook::PaperBook(string aAuthor, string aName, int aCreation, int aRelease, int aPrice, string aPublishing, int aPages) :
	Book(aAuthor, aName, aCreation, aRelease, aPrice) 
{
	setPublishing(aPublishing);
	setPages(aPages);
}

void PaperBook::setPublishing(string aPublishing)
{

	publishing = aPublishing;
}

void PaperBook::setPages(int aPages)
{
	if (aPages <= 0)
		throw exception("setPages: invalid pages count!");
	pages = aPages;
}

string PaperBook::getPublishing() const
{

	return publishing;
}

int PaperBook::getPages() const
{
	return pages;
}

ostream& operator<<(ostream& os, const PaperBook& pb)
{
	os << (const Book&)pb << "Publishing house: " << pb.publishing << " Pages: " << pb.pages << "\n";
	return os;
}
void PaperBook::readFromConsole()
{
	Book::readFromConsole();
	readPaperFromConsole();
}

void PaperBook::writeToStream(ostream& os)
{
	os << (const Book&)*this << "Publishing house: " << publishing << " Pages: " << pages << "\n";
}

void PaperBook::readPaperFromConsole()
{
	cin.ignore();
	string s;
	int t;
	cout << "Введите название издательства: ";
	getline(cin, s);
	setPublishing(s);
	cout << "Введите количество страниц: ";
	while (true) {
		cin >> t;
		try {
			setPages(t);
			break;
		}
		catch (...) {
			cout << "Вы ошиблись, повторите ввод!\n";
		}
	}
}