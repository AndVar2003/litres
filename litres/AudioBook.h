#pragma once
#include "Book.h"
class AudioBook :
    public Book
{
public:
    AudioBook();
    AudioBook(string aAuthor, string aName, int aCreation, int aRelease, int aPrice, string aReader, int aTime);
    void setReader(string aReader);
    void setTime(int aTime);
    string getReader() const;
    int getTime() const;
    void readFromConsole() override;
    void writeToStream(ostream&) override;
private:
    string reader;
    int time;
    void dummy() {};  // убираем абстрактность
    void readAudioFromConsole();
    friend ostream& operator << (ostream& os, const AudioBook& ab);
};

