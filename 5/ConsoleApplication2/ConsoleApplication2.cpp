#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

void charcounter(int *empt, int *unempt, char *ch)
{
	switch (*ch) {
	case ' ':
		*empt = *empt + 1;
		break;
	case '\n':
		*empt = *empt + 1;
		break;
	case '\t':
		*empt = *empt + 1;
		break;
	case '\b':
		*empt = *empt + 1;
		break;
	case '\f':
		*empt = *empt + 1;
		break;
	default:
		*unempt = *unempt + 1;
		break;
	}

}


int main()
{
	setlocale(LC_ALL, "ru");
	
	char ch, name[] = "1.txt";//вводим переменные
	int empt = 0, unempt = 0;
	fstream in;
	in.open(name);	
    char sym;


	while (!in.eof())
  {
    in.get(sym); // считать из rf => sym
    cout << sym;
	charcounter(&empt,&unempt,&sym);
  }

  int a, b, c;
  a = empt;
  b = unempt;
  c = b-a;
	cout << endl;
	cout << "Количество пустых символов - " << a << endl;
	cout << "Количество непустых символов - " << c<< endl;

	system("pause>>void");

	return 0;


}
