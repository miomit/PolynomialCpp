#include "Fraction.h"
#include <string>
#include "Algorithm.h"

double Fraction::Result()
{
	return (double)this->Numerator / (double)this->Denominator;
}

int Fraction::GetNumerator()
{
	return this->Numerator;
}

int Fraction::GetDenominator()
{
	return this->Denominator;
}

Fraction::Fraction() : Fraction(0)
{
}

Fraction::Fraction(int numerator) : Fraction(numerator, 1)
{
}

Fraction::Fraction(int numerator, int denominator)
{
	if (denominator == 0) throw std::invalid_argument("denominator == 0");

	this->Numerator = numerator;
	this->Denominator = denominator;

	this->Cut();
}

std::string Fraction::ToString()
{
	std::string res = std::to_string(this->Numerator);

	if (this->Denominator != 1) res +=  "/" + std::to_string(this->Denominator);

	return res;
}

Fraction Fraction::operator+(Fraction other)
{
	return Fraction(
		this->Numerator * other.GetDenominator() + other.GetNumerator() * this->Denominator,
		this->Denominator * other.GetDenominator()
	);
}

Fraction Fraction::operator+(int other)
{
	auto frac = Fraction(other);
	return *this + frac;
}

Fraction Fraction::operator-(Fraction other)
{
	return Fraction(
		this->Numerator * other.GetDenominator() - other.GetNumerator() * this->Denominator,
		this->Denominator * other.GetDenominator()
	);
}

Fraction Fraction::operator-(int other)
{
	auto frac = Fraction(other);
	return *this - frac;
}

Fraction Fraction::operator*(Fraction other)
{
	return Fraction(
		this->Numerator * other.GetNumerator(),
		this->Denominator * other.GetDenominator()
	);
}

Fraction Fraction::operator*(int other)
{
	return Fraction(
		this->Numerator * other,
		this->Denominator
	);
}

Fraction Fraction::operator/(Fraction other)
{
	return Fraction(
		this->Numerator * other.GetDenominator(),
		this->Denominator * other.GetNumerator()
	);
}

Fraction Fraction::operator/(int other)
{
	return Fraction(
		this->Numerator,
		this->Denominator * other
	);
}

bool Fraction::operator==(Fraction other)
{
	return this->Result() == other.Result();
}

bool Fraction::operator==(double other)
{
	return this->Result() == other;
}

bool Fraction::operator!=(Fraction other)
{
	return !(*this == other);
}

bool Fraction::operator!=(double other)
{
	return !(*this == other);
}

bool Fraction::operator<=(Fraction other)
{
	return this->Result() <= other.Result();
}

bool Fraction::operator<=(double other)
{
	return this->Result() <= other;
}

bool Fraction::operator>=(Fraction other)
{
	return this->Result() >= other.Result();
}

bool Fraction::operator>=(double other)
{
	return this->Result() >= other;
}

bool Fraction::operator<(Fraction other)
{
	return this->Result() < other.Result();
}

bool Fraction::operator<(double other)
{
	return this->Result() < other;
}

bool Fraction::operator>(Fraction other)
{
	return this->Result() > other.Result();
}

bool Fraction::operator>(double other)
{
	return this->Result() > other;
}

Fraction Fraction::operator%(Fraction other)
{
	return *this - ((int)(*this / other).Result()) * other;
}

Fraction Fraction::operator%(int other)
{	
	return *this % Fraction(other);
}

void Fraction::Cut()
{
	if (Denominator < 0)
	{
		Numerator *= -1;
		Denominator *= -1;
	}

	int nod = NOD(Numerator, Denominator);

	if (nod == 1) return;

	Numerator /= nod;
	Denominator /= nod;
}

Fraction operator+(int num, Fraction frac)
{
	return frac + num;
}

Fraction operator-(int num, Fraction frac)
{
	return Fraction(num) - frac;
}

Fraction operator*(int num, Fraction frac)
{
	return frac * num;
}

Fraction operator/(int num, Fraction frac)
{
	return Fraction(num) / frac;
}

bool operator==(double num, Fraction frac)
{
	return frac == num;
}

bool operator!=(double num, Fraction frac)
{
	return frac != num;
}

bool operator<=(double num, Fraction frac)
{
	return num <= frac.Result();
}

bool operator>=(double num, Fraction frac)
{
	return num >= frac.Result();
}

bool operator<(double num, Fraction frac)
{
	return num < frac.Result();
}

bool operator>(double num, Fraction frac)
{
	return num > frac.Result();
}

Fraction operator%(int num, Fraction frac)
{
	return Fraction(num) % frac;
}
