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
template<class T,class ref,class ptr>
struct Iterator_list
{
	typedef list_node<T> node;
	typedef Iterator_list<T,ref,ptr> self;
	node* _node;
	Iterator_list(node* pos)
		:_node(pos)
	{ }
	ref operator*()
	{
		return _node->data;
	}
	ptr operator->()
	{
		return &_node->data;
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
	self& operator++(int)
	{
		self ret = *this;
		_node = _node->next;
		return ret;
	}
	self& operator--(int)
	{
		self ret = *this;
		_node = _node->prev;
		return ret;
	}
	bool operator!=(const self& a)const
	{
		return _node!= a._node;
	}
	bool operator==(const self& a)const
	{
		return _node == a._node;
	}
};

template<class T>
class list
{
public:
	typedef list_node<T> node;
	typedef Iterator_list<T, T&, T*> Iterator;
	typedef Iterator_list<T,const T&,const T*> const_Iterator;

	void empty_init()
	{
		_head = new node;
		_head->next = _head;
		_head->prev = _head;
		_size = 0;
	}
	list()
		
	{
		empty_init();
	}
	list(const list<T>& it)
	{
		empty_init();
		for (auto a:it)
		{
			push_back(a);
		}
	}
	void swap(list<T>& it)
	{
		std::swap(_head, it._head);
		std::swap(_size, it._size);
	}
	list<T>operator=(list<T> it)
		{
		swap(it);
		}
	void clear()
	{
		auto it = begin();
		while (it != end())
		{
			it = erase(it);
		}
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
	const_Iterator begin()const
	{
		
		return _head->next;
	}
	const_Iterator end()const
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
	
	Iterator insert(Iterator pos, const T& x)
	{
		node* cur = pos._node;
		node* prev =cur->prev;
		node*newnode=new node(x);
		newnode->prev = prev;
		newnode->next = cur;
		prev->next = newnode;
		cur->prev = newnode;
		_size++;
		return newnode;
	}
	Iterator erase(Iterator pos)
	{
		
		assert(pos != end());
		node* cur = pos._node;
		node* prev = cur->prev;
		node* next = cur->next;
		delete cur;
		prev->next = next;
		next->prev = prev;
		_size--;
		return next;
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
template<class container>
void print_container(const container& v)
{
	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
}
}
