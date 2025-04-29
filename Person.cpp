#include "Person.h"

Person::Person()
{
	age = 0;
	mf = new char[8]{ "Unknown" };////// динамічно виділили пам_ять
	name= new char[8]{ "Unknown" };
	fname = new char[8]{ "Unknown" };////// динамічно виділили пам_ять
	phone = new char[8]{ "Unknown" };
}

Person::Person(int ag, const char* m_f, const char* nm, const char* fn, const char* phn)
{
	age = ag;

	int size = strlen(m_f) + 1;////робота зі строками  тут вызначаемо розмір строки m_f що зайде  mail -4
	mf = new char[size];////виділяемо в кучі пям_ть під потрібний розмір
	strcpy_s(mf, size, m_f);/////робимо копію з m_f що зайде в наше поле mf

	size = strlen(nm) + 1;
	name = new char[size];
	strcpy_s(name, size, nm);

	
	size = strlen(fn) + 1;
	fname = new char[size];
	strcpy_s(fname, size, fn);

	size = strlen(phn) + 1;
	phone = new char[size];
	strcpy_s(phone, size, phn);

}

void Person::Output() const
{
	cout << "Name: " << name << endl;
	cout << "Fisrt name: " << fname << endl;
	cout << "Age: " << age << endl;
	cout << "M/F: " << mf << endl;
	cout << "Phone: " << phone << endl;
}
