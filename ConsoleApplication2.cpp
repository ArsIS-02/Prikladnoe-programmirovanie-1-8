#include <iostream>
#include <cstring>
#include<cstring>
#include<ctype.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

int main()
{
    char fname[15], ch;
    cout << "Print name file: "; cin >> fname;
    // Открыли входной файл для чтения
    ifstream  ifs(fname, ios_base::in);
    if (!ifs)	//Проверяем поток,
    {
        cout << "Not open input file " << fname;
    }
    cout << "Print name output file: ";
    cin >> fname;
    //Открытие выходного файла. Если он есть, то очистить содержимое файла
    ofstream ofs(fname, ios_base::trunc);
    if (!ofs)	//Проверяем поток
    {
        cout << "Not open output file: " << fname;
    }
    char key[40];
    cout << "Input name of key: "; cin >> key;
    int n = strlen(key);
    int i = 0;
    //Пока не произойдет ошибки, делаем:
    while (ifs && ofs)
    {
        ifs.get(ch);
        ch = ch ^ (int)key[i];
        //putchar(ch);
        i++;
        if (i == n) i = 0;
        ofs.put(ch);	//Запись символа в файл
    }

}
