#include <iostream>

class Fraction
{
public:
	double Result();

	int GetNumerator();
	int GetDenominator();

	Fraction();
	Fraction(int numerator);
	Fraction(int numerator, int denominator);

	std::string ToString();

	Fraction operator+(Fraction other);
	Fraction operator+(int other);
	friend Fraction operator+(int num, Fraction frac);

	Fraction operator-(Fraction other);
	Fraction operator-(int other);
	friend Fraction operator-(int num, Fraction frac);

	Fraction operator*(Fraction other);
	Fraction operator*(int other);
	friend Fraction operator*(int num, Fraction frac);

	Fraction operator/(Fraction other);
	Fraction operator/(int other);
	friend Fraction operator/(int num, Fraction frac);

	bool operator==(Fraction other);
	bool operator==(double other);
	friend bool operator==(double num, Fraction frac);

	bool operator!=(Fraction other);
	bool operator!=(double other);
	friend bool operator!=(double num, Fraction frac);

	bool operator<=(Fraction other);
	bool operator<=(double other);
	friend bool operator<=(double num, Fraction frac);

	bool operator>=(Fraction other);
	bool operator>=(double other);
	friend bool operator>=(double num, Fraction frac);

	bool operator<(Fraction other);
	bool operator<(double other);
	friend bool operator<(double num, Fraction frac);

	bool operator>(Fraction other);
	bool operator>(double other);
	friend bool operator>(double num, Fraction frac);
	
	Fraction operator%(Fraction other);
	Fraction operator%(int other);
	friend Fraction operator%(int num, Fraction frac);

private:
	int Numerator, Denominator;

	void Cut();
};