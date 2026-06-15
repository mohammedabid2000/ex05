#pragma once

#include <iostream>
#include <string>
#include <sstream>
class bigint
{
	private:
		std::string big;
	public:
		bigint(){big = "0";};
		bigint(const bigint& other):big(other.big){};
		bigint(const std::string &s):big(s){};
		bigint(int a)
		{
			std::stringstream aa;
			aa << a;
			big = aa.str();
		}
		bigint& operator=(const bigint& other)
		{
			if(this != &other)
				this->big = other.big;
			return *this;
		};
		std::string getbig() const{return big;}
		bigint operator+(const bigint &) const;
		bigint& operator+=(const bigint &);

		bigint &operator++();
		bigint operator++(int);
		bigint operator<<(int) const;
		bigint &operator<<=(int);
		bigint &operator>>=(const bigint&);

		bool operator<(const bigint&) const;
		bool operator<=(const bigint&) const;
		bool operator>(const bigint&) const;
		bool operator>=(const bigint&) const;
		bool operator==(const bigint&) const;
		bool operator!=(const bigint&) const;
};
std::ostream& operator<<(std::ostream& out, const bigint &b);