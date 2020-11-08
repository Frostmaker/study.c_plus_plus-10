#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double arithmetic_mean(int* arr, int beg, int end)
{
	// Функция находит среднее арифмитичесое элементов массива в промежутке [<beg>, <end>)

	double k{ 0.0 }, sum{ 0.0 };
	for (int i{ beg }; i < end; i++) {
		sum += arr[i];
		k++;
	}
	if (k == 0.0)
		throw - 3;
	return sum / k;
}


double ratio(int* arr, int size, int zero_pos)
{
	// Функция находит отношение среднего арифметического элементов массива до
	// первого нуля и среднего арифметического эл. после него

	double a, b;
	a = arithmetic_mean(arr, 0, zero_pos);
	b = arithmetic_mean(arr, zero_pos + 1, size);
	if (b == 0.0)
		throw - 2;
	return a / b;
}


double my_ln(double x)
{
	// Функция натурального логарифма

	if (x < 1)
		throw 1;
	return log(x);
}


void print_func(double (*f)(double), double a, double b)
{
	// Печать таблицы функции

	for (double i{ a }; i <= b; i++) {
		try
		{
			cout << "x = " << i << " | ln(x) = " << f(i) << endl;
		}
		catch (int)
		{
			cout << "x = " << i << " | ln(x) = " << "логарифм не определён" << endl;
		}
	}
}


double my_solve(int a, int b, char s)
{
	switch (s) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0)
			throw - 2;
		return (double)a / b;
	default:
		throw - 4;
	}
}


void read(int*& a, int& n)
{
	// Функция заполнения динамического массива
	if (a != nullptr)
		throw - 1;
	else {
		cout << "Введите кол-во элементов массива: ";
		cin >> n;

		a = new int[n];
		for (int i{ 1 }; i <= n; i++) {
			cout << "Введите " << i << " элемент: ";
			cin >> a[i - 1];
		}
	}
		return;
}