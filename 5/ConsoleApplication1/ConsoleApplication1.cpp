#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    ifstream in; // поток для чтения файлов
    string read_line = "";
    // Открываем файл на чтение
    in.open("1.txt");


    if (in.is_open()) // проверили открыт ли файл
    {
        cout << "Файл открыт для чтения" << endl;
        while (getline(in, read_line)) // открыли файл для чтения
        {
            cout << read_line << endl;
        }
    }
    else
    {
        cerr << "Ошибка, файл не открыт" << endl;
    }
    in.close();
    system("pause>>void");
    return 0;
}
