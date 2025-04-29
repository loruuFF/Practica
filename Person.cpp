#include "Person.h"

Person::Person()
{
	age = 0;
	mf = new char[8]{ "Unknown" };////// �������� ������� ���_���
	name= new char[8]{ "Unknown" };
	fname = new char[8]{ "Unknown" };////// �������� ������� ���_���
	phone = new char[8]{ "Unknown" };
}

Person::Person(int ag, const char* m_f, const char* nm, const char* fn, const char* phn)
{
	age = ag;

	int size = strlen(m_f) + 1;////������ � ��������  ��� ���������� ����� ������ m_f �� �����  mail -4
	mf = new char[size];////�������� � ���� ���_�� �� �������� �����
	strcpy_s(mf, size, m_f);/////������ ���� � m_f �� ����� � ���� ���� mf

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
