#include <iostream> 
using namespace std;
void main()
{
	//прототипы функций 
	int dlina1(char*);
	int dlina2(char*);
	int dlina3(char*);
	void kopir(char*, char*);
	int compr(char*, char*);
	void concat(char*, char*);
	char str[] = "qwerty";
	char str1[25] = "1234567890";
	//вывод
	cout << dlina1(str) << endl;
	cout << dlina2(str) << endl;
	cout << dlina3(str) << endl;
	cout << str1 << endl;
	kopir(str1, str);
	cout << str1 << endl;
	cout << compr(str, str1) << endl;
	cout << str1 << endl;
	cout << str << endl;
	concat(str1, str);
	cout << str1 << endl;
}
//функция,определяющая длину строки с помощью цикла for 
int dlina1(char* arr)
{
	int count = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}
//функция,определяющая длину строки с помощью цикла while 
int dlina2(char* arr)
{
	char* chr = arr;
	int count = 0;
	while (*chr != '\0') {
		count++;
		chr++;
	}
	return count;
}
//функция,определяющая длину строки с помощью перевода массива в  
//строку и применения к ней стандартой функции length() 
int dlina3(char* arr)
{
	string str(arr);
	return str.length();
}
//функция копирующая одну строку в другую 
void kopir(char* arr1, char* arr)
{
	for (int i = 0; arr[i] != '\0'; i++)
	{
		arr1[i] = arr[i];
	}
}
//функция,сравнивающая строки 
int compr(char* arr, char* arr1)
{
	int i = 0, result = 0;
	while (((arr[i] != '\0') && (arr1[i] != '\0')))
	{
		if (int(arr[i]) > int(arr1[i]))
		{
			result = 1;
			break;
		}
		if (int(arr[i]) < int(arr1[i]))
		{
			result = -1;
			break;
		}
		i++;
	}
	return result;
}
// функция,"склеивающая" строки (конкатенация) 
void concat(char* a, char* b)
{
	int len = dlina2(a);
	len += 0;
	int i = 0;
	for (; b[i] != '\0'; i++)
	{
		a[len + i] = b[i];
	}
	a[len + i] = '\0';
}