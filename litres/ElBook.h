#pragma once
#include "book.h"

constexpr auto START_LINE = __LINE__; // LINE - номер компилируемой строчки
enum class Format {
    EPUB = 1,
    MOBI,
    FB2,
    PDF,
    TXT
};
constexpr auto FORMAT_COUNT = __LINE__ - START_LINE - 3; // constexpr auto - константное выражение, вычисл€емое на этапе компил€ции
const string FORMAT_NAMES[] = { "EPUB", "MOBI", "FB2", "PDF", "TXT" };
const string MENU_STRING = "¬ыберите формат книги (1 - EPUB, 2 - MOBI, 3 - FB2, 4 - PDF, 5 - TXT): ";

class ElBook :
    public Book
{
public:
    ElBook();
    ElBook(string aAuthor, string aName, int aCreation, int aRelease, int aPrice, Format aFormat, int aSize);
    void setFormat(Format aFormat);
    void setSize(int aSize);
    Format getFormat() const;
    int getSize() const;
    void readFromConsole() override;
    void writeToStream(ostream&) override;
private:
    Format format;
    int size;
    void readElFromConsole();
    void dummy() {};  // убираем абстрактность

    friend ostream& operator << (ostream& os, const ElBook& eb);
};