#include <iostream>
#include <conio.h>
using namespace std;
void main()
{
	setlocale(LC_ALL, "ru"); // русская кодировка в командной строке
	//ввод массива создание переменных типов данных и присваивания им значений.
	int mas[] = { 2,5,-83 - 41,6,3, 10, 23, 324,34, 34,34, 87,3,-90,4,9 };
	int imin, imax;
	int n = sizeof(mas) / sizeof(int);
	int i, temp;
	//вывод полученного результата
	cout << "Массив до сортировки:";
	for (i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
	cout << "Массив после сортировки методом пузырька:";
	for (i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++)
		{
			if (mas[j] < mas[i]) {
				temp = mas[i];
				mas[i] = mas[j];
				mas[j] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
	system("pause>>void");
}
