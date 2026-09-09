#pragma once
#include<iostream>
#include"BTtree.h"
template<class v>
struct myset
{
	
	struct set_KeyofT
	{
		const v& operator()(const v& key)const
		{
			return key;
		}
	};
	bool insert(const v& data)
	{
		return _t.insert(data);
	}
	typedef BTtree<v,const v, set_KeyofT> tree;
	typedef typename tree::iterator iterator;
	typedef typename tree::const_iterator const_iterator;
	iterator begin()
	{
		return _t.begin();
	}
	iterator end()
	{
		return _t.end();
	}
	iterator find(const v& data)
	{
		return iterator(_t.find());
	}
	
   private:
	   BTtree<v,const v, set_KeyofT> _t;
};