#include <iostream>
#include <cstdlib>
using namespace std;
void main()
{
	int dlina1(char*);
	int dlina2(char*);
	int dlina3(char*);
	void kopir(char*, char*);
	int compr(char*, char*);
	void concat(char*, char*);
	char* str, * str1;
	//используем calloc() вместо malloc()
	str = (char*)calloc(100, sizeof(char));
	str1 = (char*)calloc(100, sizeof(char));
	strncpy_s(str, 7, "qwerty", 7);
	strncpy_s(str1, 11, "1234567890", 11);
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
	free(str);
	free(str1);
}
int dlina1(char* arr)
{
	int count = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}
int dlina2(char* arr)
{
	char* chr = (char*)calloc(100, sizeof(char));
	chr = arr;
	int count = 0;
	while (*chr != '\0') {
		count++;
		chr++;
	}
	return count;
	free(chr);
}
int dlina3(char* arr)
{
	string str(arr);
	return str.length();
}
void kopir(char* arr1, char* arr)
{
	for (int i = 0; arr[i] != '\0'; i++)
	{
		arr1[i] = arr[i];
	}
}
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
