#pragma once
#include<functional>
template<class T>
struct share_ptr
{
	share_ptr( T* ptr)
		:_ptr(ptr)
		, _count(new int(1))
	{ }
	template<class D>
	share_ptr(T* ptr,D del)
		:_ptr(ptr)
		, _count(new int(1))
		,_del(del)
	{
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	share_ptr(const share_ptr<T>& P)
	{
		 _count=P._count;
		 _ptr = P._ptr;
		 _del = P._del;
		 (*_count)++;
	}
	share_ptr<T>& operator=(const share_ptr<T>& P)
	{
		if (this!=&P)
		{
			if ((--(*_count)) == 0)
			{
				_del(_ptr);
				delete _count;
			}
			_count = P._count;
			_ptr = P._ptr;
			_del = P._del;
			(*_count)++;
	}
		return *this;
	}

	~share_ptr()
	{
		if ((--(*_count))==0)
		{
			_del(_ptr);
			delete _count;
		}
	}

private:
	T* _ptr;
	int* _count;
	std::function<void(T*)> _del = [](T*ptr) {delete ptr;};
};
