#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;
const int n = 10;
int first, last;
int i;
//функция сортировки
void quicksort(int* mas, int first, int last)
{
    int mid, count;
    int f = first, l = last;
    mid = mas[(f + l) / 2]; //вычисление опорного элемента
    do
    {
        while (mas[f] < mid) f++;
        while (mas[l] > mid) l--;
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
int main() {
    srand(time(NULL));
    int k = 0, m = 0;
    int** B = new int* [k]; int** C = new int* [m];
        setlocale(LC_ALL, "Rus");
    int* A = new int[n];
    cout << "Исходный массив: ";

    for (int i = 0; i < n; i++)//наполнение массива случайными числами
    {
        A[i] = rand() % 100;
        cout << A[i] << " ";
    }

    first = 0; last = n - 1;
    quicksort(A, first, last);
        cout << endl << "Сортированный исходный массив: ";//сортировка исходного массива
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
    cout << ("Чётные элементы, отсортированные по возрастанию: ") << " ";//сортировка чётных элементов по возрастанию
    for (int i = 0; i < n; i++) {
        if (A[i] % 2 == 0)
        {
            cout << A[i] << " ";
        }
    }
    cout << endl;
    cout << ("Нечётные элементы, отсортированные по убыванию: ") << " ";//сортировка нечётных элементов по убыванию
    for (int i = 1; i < n; ++i)
    {
        for (int r = 0; r < n - i; r++)
        {
            if (A[r] < A[r + 1])
            {
                // Обмен местами
                int temp = A[r];
                A[r] = A[r + 1];
                A[r + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] % 2 != 0)
        {
            cout << A[i] << " ";
        }
    } system("pause>>void");
    return 0;
    cout << endl;
   
}