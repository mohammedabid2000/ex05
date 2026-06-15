#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag &a;
	public:
		set(searchable_bag&);
		bool has(int);
		void insert(int);
		void insert(int *, int);
		void print()const;
		void clear();
		searchable_bag& getBag();
};