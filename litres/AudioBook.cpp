#include "AudioBook.h"

ostream& operator<<(ostream& os, const AudioBook& ab)
{
	os << (const Book&)ab << "Reader name: " << ab.reader << " Reading time: " << ab.time << "\n";
	return os;
}

AudioBook::AudioBook() : Book()
{
	readAudioFromConsole();
}

AudioBook::AudioBook(string aAuthor, string aName, int aCreation, int aRelease, int aPrice, string aReader, int aTime) :
	Book(aAuthor, aName, aCreation, aRelease, aPrice)
{
	setReader(aReader);
	setTime(aTime);
}

void AudioBook::setReader(string aReader)
{
	reader = aReader;
}

void AudioBook::setTime(int aTime)
{
	if (aTime <= 0)
		throw exception("setTime: invalid reading time!");
	time = aTime;
}

string AudioBook::getReader() const
{
	return reader;
}

int AudioBook::getTime() const
{
	return time;
}

void AudioBook::readFromConsole()
{
	Book::readFromConsole();
	readAudioFromConsole();
}

void AudioBook::writeToStream(ostream& os)
{
	/*os << (const Book&)*this << "Reader name: " << reader << " Reading time: " << time << "\n";*/
	os<<*this;
}

void AudioBook::readAudioFromConsole()
{
	cin.ignore();
	string s;
	int t;
	cout << "Введите имя чтеца: ";
	getline(cin, s);
	setReader(s);
	cout << "Введите длительность чтения (в минутах): ";
	while (true) {
		cin >> t;
		try {
			setTime(t);
			break;
		}
		catch (...) {
			cout << "Вы ошиблись, повторите ввод!\n";
		}
	}

}
