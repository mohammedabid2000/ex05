#include "bigint.hpp"
#include <algorithm>
#include <cstdlib>

bigint bigint::operator+(const bigint &a) const
{
	bigint temp;
	temp.big = "";
	int i = this->big.size() -1;
	int j = a.big.size() -1;
	int carry = 0;
	while (i >=0 || j >=0 || carry > 0)
	{
		int x = i >= 0 ? big[i--] - '0' : 0;
		int y = j >= 0 ? a.big[j--] - '0' : 0;
		int sum = carry + x + y;
		carry = sum / 10;
		temp.big.push_back(sum % 10 + '0');
	}
	if (temp.big.empty())
		temp.big = "0";
	std::reverse(temp.big.begin(), temp.big.end());
	return temp;
}
bigint & bigint::operator+=(const bigint& a)
{
	*this = *this + a;
	return *this;
}
bigint &bigint::operator++()
{
	*this += bigint("1");
	return *this;
}
bigint bigint::operator++(int)
{
	bigint temp = *this;
	*this += bigint("1");
	return temp;
}
bigint bigint::operator<<(int a)const 
{
	if (this->big == "0")
		return *this;
	bigint temp = *this;
	temp.big.append(a, '0');
	return temp;
}
bigint &bigint::operator<<=(int a)
{
	*this = *this << a;
	return *this;
}
bigint &bigint::operator>>=(const bigint &a)
{
	long n = std::atol(a.big.c_str());
	if (n >= static_cast<long>(big.size()))
		this->big = "0";
	else
	{
		this->big.erase(big.size() - n);
		if (this->big.empty())
			this->big = "0";
	}
	return *this;
}

bool bigint::operator<(const bigint&a) const
{
	if (this->big.size() != a.big.size())
		return this->big.size() < a.big.size();
	return this->big < a.big;
}
bool bigint::operator<=(const bigint&a) const
{
	return !(*this > a);
}
bool bigint::operator>(const bigint&a) const
{
	if (this->big.size() != a.big.size())
		return this->big.size() > a.big.size();
	return this->big > a.big;
}
bool bigint::operator>=(const bigint&a) const
{
	return !(*this < a);
}
bool bigint::operator==(const bigint&a) const
{
	return this->big == a.big; 
}
bool bigint::operator!=(const bigint&a) const
{
	return !(*this == a);
}
std::ostream& operator<<(std::ostream& out, const bigint &a)
{
	out << a.getbig();
	return out;
}