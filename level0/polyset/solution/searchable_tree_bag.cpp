#include "searchable_tree_bag.hpp"
#include "tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag():tree_bag::tree_bag(){}
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag&a):tree_bag::tree_bag(a){}
searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag&a)
{
	tree_bag::operator=(a);
	return *this;
}
bool searchable_tree_bag::has(int val)const
{
	node *temp = this->tree;
	if(temp->value == val)
		return true;
	else if (temp->value > val)
		temp = temp->r;
	else
		temp = temp->l;
	return false;
}