#include <iostream> 
#define PR(x)  printf("x=%u, *x=%f, &x=%u \n",x,*x, &x) 
#include <stdio.h> 
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru"); // русская кодировка в командной строке
    float mas[] = { 465.8, 279.2, 804.5 }; //объявлен массив 
    float* ptrl, * ptr2; //объявлены указатели 
    ptrl = mas; //указатель на массив 
    ptr2 = &mas[2]; //указатель адрес массива 
    PR(ptrl); //вывод значения, указателя на значение, адрес 
    ptrl++; //переход к следующему элементу указателя 
    PR(ptrl);
    PR(ptr2);
    ++ptr2;
    PR(ptr2);
    printf("ptr2-ptrl=%d\n", ptr2 - ptrl);
    system("pause>>void");
}