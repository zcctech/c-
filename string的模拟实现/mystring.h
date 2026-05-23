#pragma once
#include<iostream>
#include<cstring>
#include<cassert>
using namespace std;
namespace mystring
{
	typedef char* iterator;
	typedef const char* const_iterator;
	class string
	{
	public:
		string(const char* str="")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_size + 1];
			strcpy(_str, str);
		}
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		string(const string& s)
		{
			string tep(s._str);
			swap(tep);

		}
		~string()
		{
			delete[] _str;
			_size = _capacity = 0;
		}
		const char* c_str()const
		{
			return _str;
		}
		size_t size()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		char& operator[](int a)
		{
			assert(a < _size);
			return _str[a];
		}
		char& operator[](int a)const
		{
			assert(a < _size);
			return _str[a];
		}
		string& operator=(const string& s1)
		{
			if (this == &s1)
			{
				return *this;
		}
			string tep(s1.c_str());
			swap(tep);
			
			return *this;
		}
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str+_size;
		}
		const_iterator begin()const
		{
			return _str;
		}

		const_iterator end()const
		{
			return _str + _size;
		}
		void reserve(const size_t n);
		void push_back(const char ch);
		string& operator+=(char ch);
		void append(const char* ch);
		string& operator+=(const char* ch);
		void insert(size_t pos, char ch);
		void insert(size_t pos,const char* str);
		void erase(size_t pos, size_t len = npos);
		size_t find(char ch, const size_t pos = 0);
		size_t find(const char* str, const size_t pos = 0);
		string substr(size_t pos, size_t len);
		string& clear();
		
			





	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos;
	};
	bool operator>(const string& s1, const string& s2);
	bool operator>=(const string& s1, const string& s2);
	bool operator<(const string& s1, const string& s2);
	bool operator<=(const string& s1, const string& s2);
	bool operator==(const string& s1, const string& s2);
	bool operator!=(const string& s1, const string& s2);
	ostream& operator<<(ostream& out,string& s1);
	istream& operator>>(istream& in, string& s1);
	
}