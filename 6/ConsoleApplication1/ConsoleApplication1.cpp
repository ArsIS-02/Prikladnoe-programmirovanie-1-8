#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
class Stroka
{
	//переменная для хранения строк
	char str[80];
public:
	// прототипы разных вариантов конструкторов
	// функций и переопределения операторов
	Stroka(char*);
	Stroka() {};
	Stroka(const Stroka&);
	Stroka& operator=(const Stroka&);
	Stroka& operator+(const Stroka&);
	int operator==(const Stroka&);
	int dlina();
	void vvod();
	void vyvod();
	char* znach();
};
//определение функций конструкторов и переопределения операторов
Stroka::Stroka(char* string)
{
	strcpy(str, string);
}
Stroka::Stroka(const Stroka& s)
{
	strcpy(str, s.str);
}
Stroka& Stroka::operator=(const Stroka& s)
{
	strcpy(str, s.str);
	return *this;
}
Stroka& Stroka::operator+(const Stroka& s)
{
	strcat(str, s.str);
	return *this;
}
int Stroka::operator==(const Stroka& s)
{
	if (strcmp(str, s.str) == 0)
		return 1;
	else
		return 0;
}
int Stroka::dlina()
{
	return strlen(str);
}
char* Stroka::znach()
{
	return str;
}
void Stroka::vvod()
{
	cin >> str;
}
void Stroka::vyvod()
{
	cout << str;
}
void main()
{
	setlocale(LC_ALL, "ru");
	// используем массивы для передачи значений
	char arr[] = "qwert";
	char arr1[] = "asdfg";
	Stroka s1(arr), s3, s4(s1), s5;
	s3.vvod();
	s3 = arr1;
	s3.vyvod();
	cout << endl;
	//обратите внимание,здесь переопределяется равно =>
	// оно выполняет операцию которая определена в классе
	s5 = s1 + s3 + s4;
	cout << "длина s5 = " << s5.dlina();
	cout << endl;
	s5.vyvod();
	cout << endl;
	cout << s1.znach() << endl;
	if (s1 == s5)
	{
		cout << "строки s1 и s5 равны";
		cout << endl;
	}
	else
	{
		if (s1 == s4)
			cout << "строки s1 и s4 равны";
		cout << endl;
	}
	}
