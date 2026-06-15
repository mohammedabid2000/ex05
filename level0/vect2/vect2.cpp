#include "vect2.hpp"
vect2 vect2::operator++(int)
{
	vect2 temp = *this;
	*this += vect2(1,1);
	return temp;
}
vect2 &vect2::operator++()
{
	*this += vect2(1,1);
	return *this;
}
vect2 vect2::operator--(int)
{
	vect2 temp = *this;
	*this -= vect2(1,1);
	return temp;
}
vect2 &vect2::operator--()
{
	*this -= vect2(1,1);
	return *this;
}
vect2 vect2::operator+(const vect2 &a)const
{
	vect2 temp;
	temp.x = this->x + a.x; 
	temp.y = this->y + a.y;
	return temp;
}
vect2 &vect2::operator+=(const vect2&a)
{
	*this = *this + a;
	return *this;
}
vect2 vect2::operator-(const vect2&a)const
{
	vect2 temp;
	temp.x = this->x - a.x; 
	temp.y = this->y - a.y;
	return temp;
}
vect2	vect2::operator*(int scalar) const
{
	vect2	copy(*this);
	copy.x *= scalar;
	copy.y *= scalar;
	return (copy);
}
vect2 &vect2::operator*=(int a)
{
	this->x = this->x * a;
	this->y = this->y * a;
	return *this;
}
vect2 &vect2::operator-=(const vect2&a)
{
	*this = *this - a;
	return *this;
}
int vect2::operator[](int index)const
{
	if(index == 0)
		return this->x;
	else
		return this->y;
}

bool vect2::operator!=(const vect2&a)const
{
	return !((this->x == a.x) && (this->y == a.y));
}
bool vect2::operator==(const vect2&a)const
{
	return ((this->x == a.x) && (this->y == a.y));
}
vect2 vect2::operator-()const
{
	return vect2(-this->x, -this->y);
}
std::ostream& operator<<(std::ostream& out, const vect2& a)
{
	out << "{" << a[0] << ", " << a[1] << "}";
	return out;
}
vect2 operator*(int a, const vect2 &v)
{
	vect2	temp(v);
	temp *= a;
	return (temp);
}