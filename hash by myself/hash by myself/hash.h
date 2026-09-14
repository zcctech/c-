#pragma once
#include<iostream>
#include<vector>
using namespace std;
//enum state
//{
//	EXIST,
//	EMPTY,
//	DELETE
//};
//template<class k,class v>
//struct hashdata
//{
//	pair<k, v> _kv;
//	state _state = EMPTY;
//	
//
//};
//template<class k,class v>
//struct thehashfanc
//{
//	size_t operator()(const k& key)const
//	{
//		return size_t(key);
//	}
//};
//template<class v>
//struct thehashfanc<string,v>
//{
//	size_t operator()(const string& key)const
//	{
//		size_t hash0 = 0;
//		for (auto& a : key)
//		{
//			hash0 =hash0*131;
//			hash0 += a;
//		}
//		return hash0;
//	}
//	
//};
//template<class k, class v,class hashfanc = thehashfanc<k,v>>
//struct hashtable
//{
//	hashtable(size_t  num=11)
//		:_data(num)
//		, _n (0)
//	{ }
//	bool insert(const pair<k, v>& data)
//	{
//		if (find(data.first)!=nullptr)//查找函数，判断不为nullptr
//		{//说明为重复值
//			return false;
//		}
//		if ((_n +1)* 10 / _data.size() >= 7)
//		{
//			hashtable<k, v,hashfanc> _newdata(_data.size()*2);
//			for (size_t i = 0; i < _data.size(); ++i)
//			{
//				if (_data[i]._state == EXIST)
//				{
//					_newdata.insert(_data[i]._kv);
//				}
//			}
//			_data.swap(_newdata._data);
//		}
//		size_t hash0 = _fanc((data.first)) % _data.size();
//		size_t hash1 = hash0;
//		size_t i = 1;
//		while (_data[hash1]._state == EXIST)
//		{
//			hash1 = (hash0 + i)%_data.size();
//			i++;
//		}
//		_data[hash1]._kv = data;
//		_data[hash1]._state = EXIST;
//		_n++;
//		return true;
//	}
//	hashdata<k, v>* find(const k& key)
//	{
//		size_t hash0 = _fanc(key) % _data.size();
//		size_t hash1 = hash0;
//		for(size_t i=0;i< _data.size();i++)
//		{
//			hash1 = (hash0 + i) % _data.size();
//			if (_data[hash1]._state==EXIST&&_data[hash1]._kv.first == key)
//			{
//				return &_data[hash1];
//		}
//			
//		}
//		return nullptr;
//	}
//	bool erase(const k& key)
//	{
//		hashdata<k, v>* ret = find(key);
//		if (ret == nullptr)
//		{
//			return false;
//		}
//		else
//		{
//			ret->_state = DELETE;
//			_n--;
//			return true;
//		}
//		
//	}
//	vector<hashdata<k,v>> _data;
//	size_t _n;
//	hashfanc _fanc;
//};
template<class k,class v>
struct hashnode
{
	hashnode(const pair<k, v>& kv)
		:_kv(kv)
		,next(nullptr)
	{ }
	pair<k, v> _kv;
	hashnode<k, v>* next;

};
template<class k, class v>
struct hashtable
{
	typedef hashnode<k, v> node;
	hashtable(size_t  num = 11)
			:_data(num,nullptr)
			, _n (0)
	{ }
	bool insert(const pair<k, v>& kv)
	{
		if (find(kv.first))
		{
			return false;
		}
		if (_data.size() == _n)
		{
			hashtable<k, v> newtable(_n * 2);
			int i = 0;
			for (i = 0; i < _data.size(); i++)
			{
				node* cur = _data[i];
				while (cur)
				{
					node* next = cur->next;
					size_t hash0 = cur->_kv.first% newtable._data.size();
					cur->next = newtable._data[hash0];
					newtable._data[hash0] = cur;
					cur = next;
				}
				_data[i] = nullptr;
			}
			swap(this->_data,newtable._data);

		}
		size_t hash0 = kv.first % _data.size();
		node* newnode = new node(kv);
		newnode->next = _data[hash0];
		_data[hash0] = newnode;
		_n++;
		return true;
	}
	node* find(const k& key)
	{
		size_t hash0 = key % _data.size();
		node* cur = _data[hash0];
		while (cur)
		{
			if (cur->_kv.first == key)
			{
				return cur;
		}
			cur= cur->next;


		}
		return nullptr;
	}
private:
	vector<node*> _data;
	size_t _n;
};
