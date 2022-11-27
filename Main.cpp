#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
	Polynomial p("-3 -4 -1 3 1");
	Polynomial p2("-3 2 10 3");

	cout << p.ToString() << endl << p2.ToString() << endl << endl;

	cout << Polynomial::NOD(p, p2).ToString();

	cin.get();

	return 0;
}
