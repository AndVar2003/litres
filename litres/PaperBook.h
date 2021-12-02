#pragma once
#include "Book.h"
#include <string>

class PaperBook :
    public Book
{
public:
    PaperBook(); // �������� ������ � �������
    PaperBook(string aAuthor, string aName, int aCreation, int aRelease, int aPrice, string aPublishing, int aPages);
    void setPublishing(string aPublishing);
    void setPages(int aPages);
    string getPublishing() const;
    int getPages() const;
    void readFromConsole() override; // ��������������� ������
    void writeToStream(ostream&) override; //����������
private:
    string publishing;
    int pages;
    void dummy() {};  // ������� �������������
    void readPaperFromConsole();

    friend ostream& operator << (ostream& os, const PaperBook& pb);
};

