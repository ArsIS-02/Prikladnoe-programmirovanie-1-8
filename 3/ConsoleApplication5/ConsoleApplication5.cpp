#include <iostream>
using namespace std;
//рекурсивный метод быстрой сортировки
void quicksort(int* mas, int first, int last)
{
    int mid, count;
    int f = first, l = last;
    mid = mas[(f + l) / 2]; //вычисление опорного элемента
    do
    {
        while (mas[f] > mid) f++;
        while (mas[l] < mid) l--;
        if (f <= l) //перестановка элементов
        {
            count = mas[f];
            mas[f] = mas[l];
            mas[l] = count;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) quicksort(mas, first, l);
    if (f < last) quicksort(mas, f, last);
}
int main()
{
    setlocale(LC_ALL, "Rus");
    int mas[] = { 2,5,-8,1,-4,6,3,-5,-9,13, 0,4,9 };

    //вычисление п - количества элементов
    int n = sizeof(mas) / sizeof(int);
    int i;

    for (i = 0; i < n; i++)
        cout << mas[i] << " ";
    cout << endl;
    int n1, n2;
    cout << "Введите индекс n1:"; cin >> n1;
    cout << "Введите индекс n2:"; cin >> n2;
    if (n2 > n1)
    {
        quicksort(mas, (n1 - 1), (n2 - 1));
        for (i = (n1 - 1); i < (n2 - 1); i++)
            cout << mas[i] << " ";
        cout << mas[i] << " ";
    }
    if (n2 < n1)
    {
        quicksort(mas, (n2 - 1), (n1 - 1));
        for (i = (n2 - 1); i < (n1 - 1); i++)
            cout << mas[i] << " ";
        cout << endl;
    }
}
