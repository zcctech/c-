#pragma once
#include<iostream>
#include<cassert>
#include<string.h>
using namespace std;
namespace myvector
{
	template<class Container>
	void print_Container(const Container& v)
	{
		for (auto& ch : v)
		{
			cout << ch << " ";
		}
		cout << endl;
	}
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		vector()
		{ }
		vector(const vector<T>& s1)
		{
			for (auto& ch : s1)
			{
				push_back(ch);
			}
		}
		vector(size_t n,const T& val=T())
		{
			while (n--)
			{
				push_back(val);
				
			}
		}
		vector(int  n, const T& val = T())
		{
			while (n--)
			{
				push_back(val);

			}
		}
		template<class inputiterator>
		vector(inputiterator first, inputiterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		void clear()
		{
			_start = _finish;
		}
		void swap(vector<T> s1)
		{
			std::swap(_start, s1._start);
			std::swap(_finish, s1._finish);
			std::swap(_endofStorage, s1._endofStorage);
		}
		vector<T> operator=(vector<T> s1)
		{
			swap(s1);
			return *this;
		}
		void reserve(size_t n)
		{
			if (n >capacity())
			{
				size_t oldsize = size();
				T* tep = new T[n];
				for (int i = 0; i < oldsize; i++)
				{
					tep[i] = _start[i];
				}
				delete[] _start;
				_start = tep;
				_finish = tep + oldsize;
				_endofStorage = tep + n;
			}
			
		}
		bool empty()
		{
			return _start == _finish;
		}
		void push_back(const T& x)
		{
			if (_finish == _endofStorage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			_finish++;
		}
		void pop_back()
		{
			assert(!empty());
			_finish--;
		}
		void insert(iterator pos, const T& x)
		{
			if (_finish == _endofStorage)
			{
				size_t len = pos - _start;

				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}
			iterator end = _finish-1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			_finish++;
		}
		iterator erase(iterator pos)
		{
			iterator it = pos;
			iterator tep = pos + 1;
			while (tep!=end())
			{
				*(tep - 1) = *tep;
				tep++;
			}
			_finish--;
			return it;
		}
		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish != _start + n)
				{
					*(_finish) = val;
					_finish++;
				}
				
			}
		}
		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _endofStorage-_start;
		}
		T& operator[](size_t i)
		{
			assert(i < size());
			return *(_start + i);
		}
		const T& operator[](size_t i)const
		{
			assert(i < size());
			return *(_start + i);
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofStorage;
		}
	private:
		
		iterator _start=nullptr;
		iterator _finish=nullptr; 
		iterator _endofStorage=nullptr; 
	};
}