#pragma once
#include<deque>
#include<iostream>
#include<cassert>
using namespace std;
namespace bit

{

    template<class T, class Con = deque<T>>

    class stack

    {

    public:

        stack()
        {

        }

        void push(const T& x)
        {
            _c.push_back(x);
        }

        void pop()
        {
            assert(!_c.empty());
            _c.pop_back();
        }

        T& top()
        {
            assert(!_c.empty());
            return _c.back();
        }

        const T& top()const
        {
            assert(!_c.empty());
            return _c.back();
        }

        size_t size()const
        {
            return _c.size();
        }

        bool empty()const
        {
            return _c.empty();
        }

    private:

        Con _c;

    };



    template<class T, class Con = deque<T>>

    class queue

    {

    public:

        queue()
        {

        }

        void push(const T& x)
        {
            _c.push_back(x);
        }

        void pop()
        {
            assert(!_c.empty());
            _c.pop_front();
        }

        T& back()
        {
            assert(!_c.empty());
            return _c.back();
        }

        const T& back()const
        {
            assert(!_c.empty());
            return _c.back();
        }

        T& front()
        {
            assert(!_c.empty());
            return _c.front();
        }

        const T& front()const
        {
            assert(!_c.empty());
            return _c.front();
        }

        size_t size()const
        {
            return _c.size();
        }

        bool empty()const
        {
            return _c.empty();
        }

    private:

        Con _c;

    };

}
