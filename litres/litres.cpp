// litres.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "windows.h"
#include "book.h"
#include "paperbook.h"
#include "audiobook.h"
#include "elbook.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	AudioBook* book1;
	ElBook* book2;
	PaperBook* book3; // указатели нужны для выявления исключений
	try {
		book1 = new AudioBook("William Shаkespeare", "The Tragedy of King Lear", 1608, 2021, 150, "Ivanov", 180);
		cout << *book1 << endl;
		delete book1;
	}
	catch (exception) {
		cout << "Ошибки при создании аудиокниги\n";
	}
	try {
		book2 = new ElBook("William Shаkespeare", "The Tragedy of King Lear", 1608, 2020, 30, Format::FB2, 645090);
		cout << *book2 << endl;
		delete book2;
	}
	catch (exception) {
		cout << "Ошибки при создании электронной книги\n";
	}
	try {
		book3 = new PaperBook("William Shаkespeare", "The Tragedy of King Lear", 1608, 2017, 100, "Delta Publishers", 250);
		cout << *book3 << endl;
		delete book3;
	}
	catch (exception) {
		cout << "Ошибки при создании бумажной книги\n";
	}

	cout << "\nДемонстрация работы виртуальных методов (аудиокнига)\n";
	Book* book6 = new AudioBook();
	cin.ignore();
	cout << "Повторное чтение с консоли: \n";
	book6->readFromConsole();
	book6->writeToStream(cout);
	cout << *book6 << endl;

	cin.ignore();
	cout << "\nДемонстрация работы виртуальных методов (электронная книга)\n";
	Book* book4 = new ElBook();
	cin.ignore();
	cout << "Повторное чтение с консоли: \n";
	book4->readFromConsole();
	book4->writeToStream(cout);
	cout << *book4 << endl;

	cin.ignore();
	cout << "\nДемонстрация работы виртуальных методов (бумажная книга)\n";
	Book* book5 = new PaperBook();
	cin.ignore();
	cout << "Повторное чтение с консоли: \n";
	book5->readFromConsole();
	book5->writeToStream(cout);
	cout << *book5 << endl;

	delete book6;
	delete book5;
	delete book4;

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
