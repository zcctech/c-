#pragma once
#include<iostream>
#include<vector>
using namespace std;
enum state
{
	EXIST,
	EMPTY,
	DELETE
};
template<class k,class v>
struct hashdata
{
	pair<k, v> _kv;
	state _state = EMPTY;


};
template<class k, class v>
struct hashtable
{
	hashtable(size_t  num=11)
		:_data(num)
		, _n (0)
	{ }
	bool insert(const pair<k, v>& data)
	{
		if (find(data.first)!=nullptr)//查找函数，判断不为nullptr
		{//说明为重复值
			return false;
		}
		if ((_n +1)* 10 / _data.size() >= 7)
		{
			hashtable<k, v> _newdata(_data.size()*2);
			for (size_t i = 0; i < _data.size(); ++i)
			{
				if (_data[i]._state == EXIST)
				{
					_newdata.insert(_data[i]._kv);
				}
			}
			_data.swap(_newdata._data);
		}
		size_t hash0 = (data.first) % _data.size();
		size_t hash1 = hash0;
		size_t i = 1;
		while (_data[hash1]._state == EXIST)
		{
			hash1 = (hash0 + i)%_data.size();
			i++;
		}
		_data[hash1]._kv = data;
		_data[hash1]._state = EXIST;
		_n++;
		return true;
	}
	hashdata<k, v>* find(const k& key)
	{
		size_t hash0 = key % _data.size();
		size_t hash1 = hash0;
		for(size_t i=0;i< _data.size();i++)
		{
			hash1 = (hash0 + i) % _data.size();
			if (_data[hash1]._state==EXIST&&_data[hash1]._kv.first == key)
			{
				return &_data[hash1];
		}
			
		}
		return nullptr;
	}
	bool erase(const k& key)
	{
		hashdata<k, v>* ret = find(key);
		if (ret == nullptr)
		{
			return false;
		}
		else
		{
			ret->_state = DELETE;
			_n--;
			return true;
		}
		
	}
	vector<hashdata<k,v>> _data;
	size_t _n;
};
