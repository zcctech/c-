#pragma once
#include<vector>
#include<cassert>
#include <functional>
#include <algorithm>
using namespace std;
namespace bit

{


    template <class T, class Container = vector<T>, class Compare = less<T> >

    class priority_queue

    {

    public:

        priority_queue()
        {

        }

        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push(*first);
                first++;
            }
        }

        bool empty() const
        {
            return  c.empty();
        }

        size_t size() const
        {
            return c.size();
        }

        const T& top() const
        {
            assert(!c.empty());
            return c[0];
        }

        void push(const T& x)
        {
            int i = c.size();
            c.push_back(x);
            while (i > 0 && comp(c[(i - 1) / 2], c[i]))
            {
                swap(c[(i - 1) / 2], c[i]);
                i = (i - 1) / 2;
            }
        }

        void pop()
        {
            assert(!c.empty());
            swap(c[0], c[c.size() - 1]);
            c.pop_back();
            assert(!c.empty());
            AdjustDown(0);
        }

    private:
        void AdjustDown(int parent)
        {

            int child = parent * 2 + 1;
            if (child + 1 < c.size() && comp(c[child], c[child + 1]))
            {
                child++;
            }
            while (child < c.size() && comp(c[parent], c[child]))
            {
                swap(c[parent], c[child]);
                parent = child;
                child = parent * 2 + 1;
                if (child + 1 < c.size() && comp(c[child], c[child + 1]))
                {
                    child++;
                }
            }
        }
        Container c;

        Compare comp;

    };
}