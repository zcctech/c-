#pragma once
#include<iostream>
#include<cstring>
#include<cassert>
using namespace std;
namespace mystring
{
	typedef char* interator;
	typedef const char* const_interator;
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
		string(const string& s)
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;


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
		interator begin()
		{
			return _str;
		}
		interator end()
		{
			return _str+_size;
		}
		const_interator begin()const
		{
			return _str;
		}

		const_interator end()const
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