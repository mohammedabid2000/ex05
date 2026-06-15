#include "searchable_array_bag.hpp"
#include "array_bag.hpp"

searchable_array_bag::searchable_array_bag():array_bag(){}
searchable_array_bag::searchable_array_bag(const searchable_array_bag&a):array_bag(a){}
searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag&a)
{
	array_bag::operator=(a);
	return *this;
}
bool searchable_array_bag::has(int a) const
{
	for(int i =0; i < size;i++)
	{
		if(data[i] == a)
			return true;
	}
	return false;
}