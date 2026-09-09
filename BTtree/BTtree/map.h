#pragma once
#include<iostream>
#include"BTtree.h"
template<class k,class v>
struct mymap
{
	struct map_KeyofT
	{
		const k& operator()(const std::pair<const k, v>& data)
		{
			return data.first;
		}
};
	typedef BTtree<k, std::pair<const k, v>, map_KeyofT> tree;
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
	iterator find(const k& data)
	{
		return iterator(_t.find(data));
	}
	bool insert(const std::pair<const k, v>& data)
	{
		return _t.insert(data);
		
	}
	v& operator[](const k& key)
	{
		_t.insert({ key,v() });
		
		return find(key)->second;
	}
	
private:
	BTtree<k, std::pair<const k, v>, map_KeyofT> _t;
};
