#include <string.h>
#include <iostream>
using namespace std;
void main() {
	setlocale(LC_ALL, "ru");
	char expl[20] = "12345656";
	char expl1[20] = "vcbcbcv";
	char copyArr[20];
	cout << "Исходная строка" << endl;
	cout << expl << endl;
	cout << "Длина строки" << endl;
	cout << strlen(expl) << endl;
	cout << "Конкатенация строк" << endl;
	strcat_s(expl, expl1);
	cout << expl << endl;
	cout << "Копирование строк" << endl;
	strcpy_s(copyArr, expl);
	cout << copyArr << endl;
	cout << "Сравнение строк" << endl;
	cout << strcmp(expl1, expl) << endl;
}
