#pragma once
#include<iostream>
#include<cassert>
using namespace std;
namespace mylist
{

	
	
	template<class T>
	struct list_node
	{
	T data;
	list_node<T>* next;
	list_node<T>* prev;
	list_node(const T& x=T())
		:data(x)
		,next(nullptr)
		,prev(nullptr)
	{ }
	};
template<class T>
struct Iterator_list
{
	typedef list_node<T> node;
	typedef Iterator_list<T> self;
	node* _node;
	Iterator_list(node* pos)
		:_node(pos)
	{ }
	T& operator*()
	{
		return _node->data;
	}
	self& operator++()
	{
		_node = _node->next;
		return *this;
	}
	self& operator--()
	{
		_node = _node->prev;
		return *this;
	}
	bool operator!=(const Iterator_list<T>& a)
	{
		return _node!= a._node;
	}
	bool operator==(const Iterator_list<T>& a)
	{
		return _node == a._node;
	}
};

template<class T>
class list
{
public:
	typedef list_node<T> node;
	typedef Iterator_list<T> Iterator;


	list()
		
	{
		_head = new node;
		_head->next = _head;
		_head->prev = _head;
		_size = 0;
	}
		Iterator begin()
	{
			Iterator it(_head->next);
		return it;
	}
	Iterator end()
	{
		return _head;
	}
	void push_back(const T& x)
	{
		insert(end(), x);

	}
	void push_front(const T& x)
	{
		insert(begin(), x);
	}
	
	void insert(Iterator pos, const T& x)
	{
		node* cur = pos._node;
		node* prev =cur->prev;
		node*newnode=new node(x);
		newnode->prev = prev;
		newnode->next = cur;
		prev->next = newnode;
		cur->prev = newnode;
		_size++;
	}
	void erase(Iterator pos)
	{
		assert(pos != end());
		node* cur = pos._node;
		node* prev = cur->prev;
		node* next = cur->next;
		delete cur;
		prev->next = next;
		next->prev = prev;
		_size--;
	}
	void pop_back()
	{
		erase(--end());
	}
	void pop_front()
	{
		erase(begin());
	}
	bool empty()const
	{
		return _size == 0;
	}
	size_t size()const
	{
		return _size;
	}

private:
	node* _head;
	size_t _size;
};
}