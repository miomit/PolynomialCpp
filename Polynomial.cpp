#include "Polynomial.h"
#include <string>

std::list<Fraction> Polynomial::GetCoefficients()
{
	return this->Coefficients;
}

Polynomial::Polynomial(std::string line) : Polynomial(this->LineToList(line))
{
}

Polynomial::Polynomial(std::list<Fraction> coefficients)
{
	Coefficients = coefficients;
	int c = 0;
	Coefficients.reverse();
	for (auto i : Coefficients)
		if (i != 0) break;
		else c++;
	Coefficients.reverse();
	Coefficients.resize(Coefficients.size() - c);
}

Polynomial Polynomial::ShiftRight(int shift)
{
	auto coefficients =  std::list<Fraction>(Coefficients);

	for (int i = 0; i < shift; i++) coefficients.insert(coefficients.begin(), Fraction());

	return Polynomial(coefficients);
}

std::string Polynomial::ToString()
{
	std::string res = "";

	int i = Coefficients.size() - 1;
	bool flag = false;
	Coefficients.reverse();

	for (auto coefficient : Coefficients)
	{
		if (coefficient != 0)
		{
			if (coefficient < 0)
			{
				res += " - ";
				if (!(i != 0 && -1 * coefficient == 1)) res += (- 1 * coefficient).ToString();
			}
			else if (flag) 
			{
				res += " + ";
				if (!(i != 0 && coefficient == 1)) res += coefficient.ToString();
			}
			else if (!(i != 0 && coefficient == 1)) res += coefficient.ToString();
			
			if (i != 0)
			{
				res += "x";
				if (i != 1) res += "^" + std::to_string(i);
			}

			flag = true;
		}
		i--;
	}

	Coefficients.reverse();
	return res;
}

ResultDivision Polynomial::DivisionWithRemainder(Polynomial polynomial1, Polynomial polynomial2)
{
	std::list<Fraction> coefficients;
	Polynomial remain = polynomial1;

	while (remain.GetCoefficients().size() >= polynomial2.GetCoefficients().size())
	{
		auto coefficient = remain.GetCoefficients().back() / polynomial2.GetCoefficients().back();

		coefficients.push_back(coefficient);

		remain = remain - (polynomial2.ShiftRight(remain.GetCoefficients().size() - polynomial2.GetCoefficients().size()) * coefficient);
	}

	coefficients.reverse();

	return {Polynomial(coefficients), remain};
}

Polynomial Polynomial::NOD(Polynomial polynomial1, Polynomial polynomial2)
{
	if (polynomial2.GetCoefficients().empty()) return polynomial1;
	return NOD(polynomial2, polynomial1 % polynomial2);
}

Polynomial Polynomial::operator+(Polynomial other)
{
	std::list<Fraction> res;

	Fraction sum;

	for (int i = 0; i < std::max(this->Coefficients.size(), other.Coefficients.size()); i++)
	{
		sum = Fraction();

		if (i < this->Coefficients.size()) sum = sum + this->GetCoefficientById(i);
		if (i < other.Coefficients.size()) sum = sum + other.GetCoefficientById(i);

		res.push_back(sum);
	}

	return Polynomial(res);
}

Polynomial Polynomial::operator-(Polynomial other)
{
	return *this + other * -1;
}

Polynomial Polynomial::operator/(Polynomial other)
{
	return DivisionWithRemainder(*this, other).Result;
}

Polynomial Polynomial::operator%(Polynomial other)
{
	return DivisionWithRemainder(*this, other).Remains;
}

Polynomial Polynomial::operator*(Fraction frac)
{
	std::list<Fraction> res;

	for (auto i : this->Coefficients)
		res.push_back(i * frac);

	return Polynomial(res);
}

Polynomial Polynomial::operator*(int num)
{
	return *this * Fraction(num);
}

Fraction Polynomial::GetCoefficientById(int id)
{
	auto it = this->Coefficients.begin();
	for (int i = 0; i < id; i++) {
		++it;
	}
	return *it;
}

std::list<Fraction> Polynomial::LineToList(std::string line)
{
	std::string buffer = "";
	std::list<Fraction> coefficients;
	
	for (auto i : line)
	{
		if (i == ' ')
		{
			if (buffer == "") continue;

			coefficients.push_back(Fraction(std::stoi(buffer)));
			buffer = "";
		}
		else
		{
			buffer += i;
		}
	}

	if (buffer != "") coefficients.push_back(Fraction(std::stoi(buffer)));

	return coefficients;
}
