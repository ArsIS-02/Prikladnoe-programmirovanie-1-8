#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "ru");
	string s, num;
	char ch, name[50] = "2.txt";
	//открываем файлы для чтения и записи
	ofstream out{ "result.txt" };
	ifstream file("2.txt");
	getline(file, s);
	// функция которая перемещает номера страницы в ее конец
	while (!file.eof()) {
		num = s;
		getline(file, s);
		do
		{
			out << s << endl;
			getline(file, s);
		} while (s[s.size() - 1] != '\f');
		s.erase(s.size() - 1, 1);
		out << s << endl;
		num.insert((num.size()), "\f");
		out << num << endl;
		getline(file, s);
	}
}
