#define  _CRT_SECURE_NO_WARNINGS
#include"mystring.h"
namespace mystring
{
	const size_t string::npos = -1;
	string& string::clear()
	{
		_size = _capacity = 0;
		_str[_size] = '\0';
		return *this;
	}
	void string::reserve(const size_t n)
	{
		if (n > _capacity)
		{
			char* tep = new char[n + 1];
			strcpy(tep, _str);
			delete[] _str;
			_str = tep;
			_capacity = n;
		}
	}
	void string::push_back(const char ch)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size] = ch;
		_size++;
		_str[_size] = '\0';
	}
	string& string::operator+=( char ch)
	{
		push_back(ch);
		return *this;
	}
	typedef char* interator;
	void string::append(const char* ch)
	{
		int len = strlen(ch);
		if (len + _size > _capacity)
		{
			reserve(len + _size > 2 * _capacity ? len + _size : 2 * _capacity);
			
		}
		strcpy(_str + _size, ch);
		_size += len;
	}
	string& string::operator+=(const char* ch)
	{
		append(ch);
		return *this;
	}
	void string::insert(size_t pos, char ch)
	{
		assert(pos < _size);
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		int end = _size;
		while (end > pos)
		{
			_str[end ] = _str[end-1];
			end--;
		}
		_str[pos] = ch;
		_size++;
		_str[_size] = '\0';
	}
	void string::insert(size_t pos,const char* str)
	{
		assert(pos < _size);
		int len = strlen(str);
		if (len + _size > _capacity)
		{
			reserve(len + _size > 2 * _capacity ? len + _size : 2 * _capacity);

		}
		int end = _size+len-1;
		while (end > pos+len-1)
		{
			_str[end] = _str[end -len];
			end--;
			
		}
		for (int i = 0; i < len; i++)
		{
			_str[i + pos] = str[i];
	}
		_size+=len;
		_str[_size] = '\0';
	}

	
	void string::erase(size_t pos, size_t len )
	{
		assert(pos < _size);
		if (len >= _size - pos)
		{
			_size = pos;
			_str[_size] = '\0';
			return;
		}
		int begin = pos + len;
		while (begin < _size)
		{
			_str[begin - len] = _str[begin];
			begin++;
		}
		_size -= len;
		_str[_size] = '\0';
	}
	size_t string::find(char ch, const size_t pos)
	{
		assert(pos < _size);
		for (int i = 0; i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}
	size_t string::find(const char* str, const size_t pos)
	{
		assert(pos < _size);
		const char* tep = strstr(_str + pos, str);
		if (tep == nullptr)
		{
			return npos;
		}
		else
		{
			return tep - _str;
		}

	}
	string string::substr(size_t pos, size_t len)
	{
		string tep;
		assert(pos < _size);
		if (len >= _size - pos)
		{
			len = _size - pos;
		}
		tep.reserve(len);
		for (int i = 0; i < len; i++)
		{
			tep += _str[pos + i];
		}
		
			return tep;
		
	}
	bool operator>(const string& s1, const string& s2)
	{
		return !strcmp(s1.c_str(), s2.c_str());
	}
	bool operator>=(const string& s1, const string& s2)
	{
		return s1 > s2 || (strcmp(s1.c_str(), s2.c_str()) )== 0;
	}
	bool operator<(const string& s1, const string& s2)
	{
		return !(s1 >= s2);
	}
	bool operator<=(const string& s1, const string& s2)
	{
		return !(s1 > s2);
	}
	bool operator==(const string& s1, const string& s2)
	{
		return  (strcmp(s1.c_str(), s2.c_str())) == 0;
	}

	bool operator!=(const string& s1, const string& s2)
	{
		return  !(s1 == s2);
	}
	ostream& operator<<(ostream& out,string& s1)
	{
		out << s1.c_str();
		return out;
	}
	istream& operator>>(istream& in,  string& s1)
	{
		s1.clear();
		const int n = 10;
		char tep[n];
		  char ch;
		 ch=in.get();
		 int i = 0;
		while (ch != ' ' && ch != '\n')
		{
			tep[i++] = ch;
			if (i == n - 1)
			{
				tep[i] = '\0';
				s1 += tep;
				i = 0;
			}
			ch = in.get();
			
		}
		if (i != 0)
		{
			tep[i] = '\0';
			s1 += tep;
		}
		return in;
	}
}