#include "set.hpp"

set::set(searchable_bag& b):a(b){}
void set::insert(int val)
{
	a.insert(val);
}
void set::insert(int *arr, int size){a.insert(arr,size);}
void set::print()const{a.print();}
void set::clear(){a.clear();}
searchable_bag& set::getBag(){return a;}
bool set::has(int val){return a.has(val);}