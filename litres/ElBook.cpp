#pragma once
#include "ElBook.h"

string toString(Format f) {
    return FORMAT_NAMES[(int)f - 1];
}

ostream& operator<<(ostream& os, const ElBook& eb)
{
    os << (const Book&)eb << "Format: " << toString(eb.format) << " File size: " << eb.size << "\n";
    return os;
}

ElBook::ElBook() :Book()
{
    readElFromConsole();
}

ElBook::ElBook(string aAuthor, string aName, int aCreation, int aRelease, int aPrice, Format aFormat, int aSize) :
    Book(aAuthor, aName, aCreation, aRelease, aPrice)
{
    setFormat(aFormat);
    setSize(aSize);
}

void ElBook::setFormat(Format aFormat)
{

    format = aFormat;
}

void ElBook::setSize(int aSize)
{
    if (aSize <= 0)
        throw exception("setSize: invalid file size!");
    size = aSize;
}

Format ElBook::getFormat() const
{
    return format;
}

int ElBook::getSize() const
{
    return size;
}
void ElBook::readFromConsole()
{
    Book::readFromConsole();
    readElFromConsole();
}

void ElBook::writeToStream(ostream& os)
{
    os << (const Book&)*this << "Format: " << toString(format) << " File size: " << size << "\n";
}

void ElBook::readElFromConsole()
{
    cin.ignore();
    Format inputFormat;
    int t;
    cout << "Выберите формат книги (" + MENU_STRING + "): ";
    while (true) {
        cin >> t;
        if (!((t < 1) || (t > FORMAT_COUNT)))
            break;
        cout << "Вы ошиблись, повторите ввод!\n";
    }
    inputFormat = (Format)t;
    setFormat(inputFormat);
    cout << "введите размер книги:";
    while (true) {
        cin >> t;
        try {
            setSize(t);
            break;
        }
        catch (...) {
            cout << "Вы ошиблись, повторите ввод!\n";
        }
    }
}

