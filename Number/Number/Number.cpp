// Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;

long calculate(long number)
{
	if (number == 1)
		return -1;
	long f_n_1 = +calculate(number - 1) + (long)pow(-1, number) * number;
	return f_n_1;
}

long calculate1(long number)
{
	if (number % 2 == 0)
	{
		return number / 2;
	}
	else
	{
		return -(number + 1) / 2;
	}
}

long calculate2(long number)
{
	return pow((long) - 1, number) * (number + 1) / 2;
}


int main()
{
	long n = pow(10, 15);
	cout << n << endl;
	cout << "calculate1 [" << n << "]: " << calculate1(n) << endl;

	cout << "calculate [" << n << "]: " << calculate2(n) << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file