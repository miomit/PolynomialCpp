#include"Fraction.h"
#include <iostream>
#include <list>

struct ResultDivision;

class Polynomial {
public:
	std::list<Fraction> GetCoefficients();
	Fraction GetCoefficientById(int id);

	Polynomial(std::string line);
	Polynomial(std::list<Fraction> coefficients);

	Polynomial ShiftRight(int shift);

	std::string ToString();

	static ResultDivision DivisionWithRemainder(Polynomial polynomial1, Polynomial polynomial2);
	static Polynomial NOD(Polynomial polynomial1, Polynomial polynomial2);

	Polynomial operator+(Polynomial other);
	Polynomial operator-(Polynomial other);

	Polynomial operator/(Polynomial other);
	Polynomial operator%(Polynomial other);

	Polynomial operator*(Fraction frac);
	Polynomial operator*(int num);

private:
	std::list<Fraction> Coefficients;

	std::list<Fraction> LineToList(std::string line);
};

struct ResultDivision
{
	Polynomial Result;
	Polynomial Remains;
};