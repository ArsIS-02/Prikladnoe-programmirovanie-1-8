#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#define N 5 //три строчки
using namespace std;
void main()
{
	setlocale(LC_ALL, "ru"); // русская кодировка 
	float m[N][N];
	//вводим прототипы функций
	float matMax(float(&arr)[N][N]);
	float matMin(float(&arr)[N][N]);
	float triUMax(float(&arr)[N][N]);
	float triUMin(float(&arr)[N][N]);
	float triDMax(float(&arr)[N][N]);
	float triDMin(float(&arr)[N][N]);
	float mDiagMax(float(&arr)[N][N]);
	float mDiagMin(float(&arr)[N][N]);
	float scDiagMax(float(&arr)[N][N]);
	float scDiagMin(float(&arr)[N][N]);
	float triDsred(float(&arr)[N][N]);
	float triUsred(float(&arr)[N][N]);
	float matSred(float(&arr)[N][N]);
	float* rowSum(float(&arr)[N][N]);
	float* colSum(float(&arr)[N][N]);
	float* Minrow(float(&arr)[N][N]);
	float* Maxrow(float(&arr)[N][N]);
	float* Maxcol(float(&arr)[N][N]);
	float* Mincol(float(&arr)[N][N]);
	float* sredcol(float(&arr)[N][N]);
	float* sredrow(float(&arr)[N][N]);
	float triUsum(float(&arr)[N][N]);
	float triDsum(float(&arr)[N][N]);
	float matnearSred(float(&arr)[N][N]);
	int i, j;
	// заполняем исходный массив
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			m[i][j] = rand() / 12.f;
		}
	}
	//выводим исходный массив и, последовательно все функции
	cout << "Исходный массив" << endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout << setw(8) << setprecision(5) << m[i][j];

		}
		cout << endl;
	}


	cout << "максимум матрицы = " << matMax(m) << endl;
	cout << "минимум матрицы = " << matMin(m) << endl;
	cout << "максимум верхнетреугольной части матрицы = "
		<< triUMax(m) << endl;
	cout << "минимум верхнетреугольной части матрицы = "
		<< triUMin(m) << endl;
	cout << "минимум нижнетреугольной части матрицы = "
		<< triDMin(m) << endl;
	cout << "максимум нижнетреуголыюй части матрицы = "
		<< triDMax(m) << endl;
	cout << "максимум главной диагонали матрицы = "
		<< mDiagMax(m)
		<< endl;
	cout << "минимум главной диагонали матрицы = "
		<< mDiagMin(m) << endl;
	cout << "максимум второстепенной диагонали матрицы = "
		<< scDiagMax(m) << endl;
	cout << "минимум второстепенной диагонали матрицы = "
		<< scDiagMin(m) << endl;
	cout << "среднее арифметическое значение элементов нижнетреугольной части матрицы = "
		<< triDsred(m) << endl;
	cout << "среднееарифметическое значение элементов верхнетреугольной части матрицы = "
		<< triUsred(m) << endl;
	cout << "среднее арифметическое значение элементов матрицы = "
		<< matSred(m) << endl;
	cout << "сумма строк матрицы" << endl;
	for (int k = 0; k < N; k++)
	{
		cout << *(rowSum(m) + k) << endl;
	}
	cout << " сумма столбцов матрицы " << endl;
	for (int k = 0; k < N; k++)
	{
		cout << *(colSum(m) + k) << "  ";
	}
	cout << endl;
	cout << "минимальные значения строк" << endl;
	for (int k = 0; k < N; k++)
	{
		cout << *(Minrow(m) + k) << endl;
	}
	cout << "максимальные значения строк" << endl;
	for (int k = 0; k < N; k++)
	{
		cout << *(Maxrow(m) + k) << endl;
	}
	cout << "минимальные значения столбцов" << endl;
	for (int k = 0; k < N; k++)
	{
		cout << *(Mincol(m) + k) << "  ";
	}
	cout << endl;
	cout << "максимальные значения столбцов" << endl;
	for (int k = 0; k < N; k++)
	{
		cout << *(Maxcol(m) + k) << "  ";
	}
	cout << endl;
	cout << "среднее арифметическое значение столбцов" << endl;
	for (int k = 0; k < N; k++)
	{
		cout << *(sredcol(m) + k) << "  ";
	}
	cout << endl;
	cout << "среднее арифметическое значение строк" << endl;
	for (int k = 0; k < N; k++)
	{
		cout << *(sredrow(m) + k) << endl;
	}
	cout << "сумма верхнетреугольной части матрицы = "
		<< triUsum(m) << endl;
	cout << "сумма нижнетреугольной части матрицы = "
		<< triDsum(m) << endl;
	cout << "элемент, наиболее близкий по значению к среднему арифметическому = "
		<< matnearSred(m) << endl;

}
//максимум матрицы
float matMax(float(&arr)[N][N]) {
	float maxM = arr[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] > maxM)
			{
				maxM = arr[i][j];
			}

		}
	}
	return maxM;
}
//минимум матрицы
float matMin(float(&arr)[N][N]) {
	float minM = arr[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] < minM)
			{
				minM = arr[i][j];
			}

		}
	}
	return minM;
}
//максимум верхнетреугольной части матрицы
float triUMax(float(&arr)[N][N])
{
	int k = 0, j;
	float maxM;
	maxM = 0;
	for (int i = 0; i < N; i++)
	{
		j = k++;
		for (; j < N; j++)
		{
			if (arr[i][j] > maxM)
			{
				maxM = arr[i][j];
			}
		}
	}
	return maxM;
}
//минимум верхнетреугольной части матрицы
float triUMin(float(&arr)[N][N])
{
	int k = 0, j;
	float minM;
	minM = arr[0][0];
	for (int i = 0; i < N; i++)
	{
		j = k++;
		for (; j < N; j++)
		{
			if (arr[i][j] < minM)
			{
				minM = arr[i][j];
			}
		}
	}
	return minM;
}
//максимум нижнетреуголыюй части матрицы
float triDMin(float(&arr)[N][N])
{
	int k = 1, n;
	float minM;
	minM = arr[0][0];
	for (int i = 0; i < N; i++)
	{
		n = k++;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] < minM)
			{
				minM = arr[i][j];
			}
		}
	}
	return minM;
}
//максимум главной диагонали матрицы
float triDMax(float(&arr)[N][N])
{
	int k = 1, n;
	float maxM;
	maxM = 0;
	for (int i = 0; i < N; i++)
	{
		n = k++;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] > maxM)
			{
				maxM = arr[i][j];
			}
		}
	}
	return maxM;
}
//максимум главной диагонали матрицы
float mDiagMax(float(&arr)[N][N])
{

	float maxM;
	maxM = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i][i] > maxM)
		{
			maxM = arr[i][i];
		}
	}
	return maxM;
}
//минимум главной диагонали матрицы
float mDiagMin(float(&arr)[N][N])
{
	float minM;
	minM = arr[0][0];
	for (int i = 0; i < N; i++)
	{
		if (arr[i][i] < minM)
		{
			minM = arr[i][i];
		}
	}
	return minM;
}
//минимум второстепенной диагонали матрицы
float scDiagMin(float(&arr)[N][N])
{
	float minM;
	minM = arr[N - 1][0];
	for (int i = N - 1; i >= 0; i--)
	{
		if (arr[i][N - i - 1] < minM)
		{
			minM = arr[i][N - i - 1];
		}


	}
	return minM;
}
//максимум второстепенной диагонали матрицы
float scDiagMax(float(&arr)[N][N])
{
	float maxM;
	maxM = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (arr[i][N - i - 1] > maxM)
		{
			maxM = arr[i][N - i - 1];
		}


	}
	return maxM;
}
//среднеарифметическое значение элементов матрицы
float matSred(float(&arr)[N][N]) {
	float sred = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

			sred += arr[i][j];
		}
	}
	sred /= N * N;
	return sred;
}
//среднеарифметическое значение элементов верхнетреугольной части матрицы
float triUsred(float(&arr)[N][N])
{
	int k = 0, j;
	float sred = 0;

	for (int i = 0; i < N; i++)
	{
		j = k++;
		for (; j < N; j++)
		{
			sred += arr[i][j];
		}
	}
	sred /= (N + ((float)pow(N, 2) - N) / 2);
	return sred;
}
//среднеарифметическое значение элементов нижнетреугольной части матрицы
float triDsred(float(&arr)[N][N])
{
	int k = 1, n;
	float sred = 0;
	for (int i = 0; i < N; i++)
	{
		n = k++;
		for (int j = 0; j < n; j++)
		{
			sred += arr[i][j];
		}
	}
	sred /= (N + ((float)pow(N, 2) - N) / 2);
	return sred;
}
//суммы строк матрицы
float* rowSum(float(&arr)[N][N]) {
	float Sum;
	float narr[N];
	for (int i = 0; i < N; i++)
	{
		Sum = 0;
		for (int j = 0; j < N; j++)
		{
			Sum += arr[i][j];
		}
		narr[i] = Sum;
	}
	return narr;
}
//суммы столбцов матрицы
float* colSum(float(&arr)[N][N]) {
	float Sum;
	float narr[N];
	for (int i = 0; i < N; i++)
	{
		Sum = 0;
		for (int j = 0; j < N; j++)
		{
			Sum += arr[j][i];
		}
		narr[i] = Sum;
	}
	return narr;
}
//минимальные значения строк
float* Minrow(float(&arr)[N][N]) {
	float min;
	float narr[N];
	for (int i = 0; i < N; i++)
	{
		min = arr[i][0];
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] < min)
			{
				min = arr[i][j];
			}
		}
		narr[i] = min;
	}
	return narr;
}
//максимальные значения строк
float* Maxrow(float(&arr)[N][N]) {
	float max;
	float narr[N];
	for (int i = 0; i < N; i++)
	{
		max = 0;
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}
		}
		narr[i] = max;
	}
	return narr;
}
//максимальные значения столбцов
float* Maxcol(float(&arr)[N][N]) {
	float max;
	float narr[N];
	for (int i = 0; i < N; i++)
	{
		max = 0;
		for (int j = 0; j < N; j++)
		{
			if (max < arr[j][i])
			{
				max = arr[j][i];
			}
		}
		narr[i] = max;
	}
	return narr;
}
//минимальные значения столбцов
float* Mincol(float(&arr)[N][N]) {
	float min;
	float narr[N];
	for (int i = 0; i < N; i++)
	{
		min = arr[0][i];
		for (int j = 0; j < N; j++)
		{
			if (min > arr[j][i])
			{
				min = arr[j][i];
			}
		}
		narr[i] = min;
	}
	return narr;
}
//среднеарифметические значения строк
float* sredrow(float(&arr)[N][N]) {
	float sred;
	float narr[N];
	for (int i = 0; i < N; i++)
	{
		sred = 0;
		for (int j = 0; j < N; j++)
		{
			sred += arr[i][j];
		}
		sred /= N;
		narr[i] = sred;
	}
	return narr;
}
//среднеарифметические значения столбцов
float* sredcol(float(&arr)[N][N]) {
	float sred;
	float narr[N];
	for (int i = 0; i < N; i++)
	{
		sred = 0;
		for (int j = 0; j < N; j++)
		{
			sred += arr[j][i];
		}
		sred /= N;
		narr[i] = sred;
	}
	return narr;
}
//сумма верхнетреугольной части матрицы
float triUsum(float(&arr)[N][N])
{
	int k = 0, j;
	float sum = 0;
	for (int i = 0; i < N; i++)
	{
		j = k++;
		for (; j < N; j++)
		{

			sum += arr[i][j];

		}
	}
	return sum;
}
//сумма нижнетреугольной части матрицы
float triDsum(float(&arr)[N][N])
{
	int k = 1, n;
	float sum = 0;
	for (int i = 0; i < N; i++)
	{
		n = k++;
		for (int j = 0; j < n; j++)
		{

			sum += arr[i][j];

		}
	}
	return sum;
}
//элемент, наиболее близкий по значению к среднеарифметическому
float matnearSred(float(&arr)[N][N]) {
	float sred = 0, nsred, diff;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

			sred += arr[i][j];
		}
	}
	sred /= N * N;
	diff = abs(arr[0][0] - sred);
	nsred = arr[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (abs(arr[i][j] - sred) < diff)
			{
				diff = abs(arr[i][j] - sred);
				nsred = arr[i][j];
			}
		}
	}
	return nsred;
}
