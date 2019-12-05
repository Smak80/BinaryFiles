#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;
struct Data
{
	char lname[30];
	char fname[30];
	char address[150];
	int age;
};
void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Data person1 = {
		"Иванов",
		"Иван",
		"г. Казань, ул. Университетская, д. 2, кв. 11",
		54
	};
	Data person2;
	person2.age = 61;
	strcpy_s(person2.fname, "Петр");
	strcpy_s(person2.lname, "Петров");
	strcpy_s(person2.address, "г. Москва, ул. Тверская-Ямская, д. 133, к. 6, кв. 98");
	Data* person3;
	person3 = new Data;
	person3->age = 78;
	strcpy_s(person3->fname, "Сидор");
	strcpy_s(person3->lname, "Сидоров");
	strcpy_s(person3->address, "д. Гадюкино, ул. Главная, д. 1");
	ofstream fo("persons.dat", ios_base::binary);
	if (fo.is_open())
	{
		fo.write(reinterpret_cast<const char*>(&person1), sizeof(person1));
		fo.write(reinterpret_cast<const char*>(&person2), sizeof(Data));
		fo.write(reinterpret_cast<const char*>(person3), sizeof(Data));
		fo.close();
	} else
	{
		cout << "Печальбеда: файл не записывается! ;(";
	}
	ifstream fi("persons.dat", ios_base::binary);
	if (fi.is_open())
	{
		Data some_person;
		int i = 1;
		while (!fi.eof())
		{
			fi.read(reinterpret_cast<char*>(&some_person), sizeof(Data));
			if (!fi.fail()){
				cout << i++ << ":\n";
				cout << some_person.lname << " " << some_person.fname << endl;
				cout << "Возраст: " << some_person.age << endl;
				cout << "Адрес: " << some_person.address << endl;
			}
		}
		fi.close();
	} else
	{
		cout << "Печальбеда: файл не считывается! ;;;;((((";
	}
	system("pause");
}