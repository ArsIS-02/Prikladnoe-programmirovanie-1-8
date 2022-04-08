#include <iostream>
#include<conio.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru"); // русская кодировка в командной строке
    int i, k;
    int n;
    cout << "Введите основание: ";
    cin >> n;           //ввод основания 
    int power(int, int);//описание прототипа метода  


    for (i = 0; i < 10; i++)//в цикле меняется показатель степени от 0 до 9 
    {
        k = power(n, i);              //в метод передаем основание и степень 
        cout << n << "^" << i << "=" << k << endl; //выводим результат в терминал
    }
}
int power(int x, int n)//метод с двумя параметрами 
{
    int i, p = 1;
    for (i = 1; i <= n; i++) p *= x;//произведение основания n раз на себя 
    return p;                   //возвращаем результат 
    system("pause>>void");
}