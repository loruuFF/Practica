#include <iostream>
#include <ctime>
#include "TemplateArray.h"
using namespace std;

void main() {
	srand(time(0));

	Array<int> arr;

	cout << "Initial array:\n";
	arr.Output();

	arr[0] = 42;
	cout << "After arr[0] = 42:\n";
	arr.Output();

	arr.AddLast(999);
	cout << "After AddLast(999):\n";
	arr.Output();

	arr.DellLast();
	cout << "After DellLast():\n";
	arr.Output();

	arr.Add(1, 555);
	cout << "After Add(1, 555):\n";
	arr.Output();

	arr.Dell(1);
	cout << "After Dell(1):\n";
	arr.Output();

	cout << "Enter 10 integers:\n";
	cin >> arr;

	cout << "You entered:\n" << arr << endl;

	system("pause");
}
