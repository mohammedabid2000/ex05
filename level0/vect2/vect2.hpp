#pragma once
#include <iostream>
class vect2
{
private:
	int x,y;
public:
	vect2():x(0),y(0){}
	vect2(int x1, int y1):x(x1),y(y1){}
	vect2(const vect2& a):x(a.x),y(a.y){}
	vect2 operator=(const vect2& a)
	{
		if(this != &a)
		{
			this->x = a.x;
			this->y = a.y;
		}
		return *this;
	}
	vect2 operator++(int);
	vect2 &operator++();
	vect2 operator--(int);
	vect2 &operator--();
	vect2 operator+(const vect2&)const;
	vect2 &operator+=(const vect2&);
	vect2 operator-(const vect2&)const;
	vect2 operator-()const;
	vect2 &operator*=(int a);
	vect2 operator*(int scalar) const;
	vect2 &operator-=(const vect2&);
	int operator[](int index)const;
	int	&operator[](int index) { return index == 0 ? x : y; }
	bool operator!=(const vect2&)const;
	bool operator==(const vect2&)const;
	int getX(){return this->x;}
	int getY(){return this->y;}
};
std::ostream& operator<<(std::ostream& out, const vect2& a);
vect2 operator*(int a, const vect2&);