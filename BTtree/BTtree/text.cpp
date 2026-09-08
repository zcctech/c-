#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
#include "BTtree.h"

using namespace std;

void TestLL()
{
    BTtree<int> t;

    assert(t.insert(30));
    assert(t.insert(20));
    assert(t.insert(10));

    cout << "LL test passed" << endl;
}

void TestRR()
{
    BTtree<int> t;

    assert(t.insert(10));
    assert(t.insert(20));
    assert(t.insert(30));

    cout << "RR test passed" << endl;
}

void TestLR()
{
    BTtree<int> t;

    assert(t.insert(30));
    assert(t.insert(10));
    assert(t.insert(20));

    cout << "LR test passed" << endl;
}

void TestRL()
{
    BTtree<int> t;

    assert(t.insert(10));
    assert(t.insert(30));
    assert(t.insert(20));

    cout << "RL test passed" << endl;
}

void TestRecolor()
{
    BTtree<int> t;

    // 会出现父亲红、叔叔红的情况
    assert(t.insert(10));
    assert(t.insert(5));
    assert(t.insert(15));
    assert(t.insert(1));

    cout << "Recolor test passed" << endl;
}

void TestDuplicate()
{
    BTtree<int> t;

    assert(t.insert(10));
    assert(t.insert(5));
    assert(t.insert(15));

    // 重复插入应该失败
    assert(t.insert(10) == false);
    assert(t.insert(5) == false);
    assert(t.insert(15) == false);

    cout << "Duplicate test passed" << endl;
}

void TestComplex()
{
    BTtree<int> t;

    int arr[] =
    {
        10, 20, 30,
        15, 25,
        5, 1, 6,
        14, 13,
        27, 26,
        40, 50, 60
    };

    for (auto e : arr)
    {
        assert(t.insert(e));
    }

    cout << "Complex test passed" << endl;
}

void TestContinuousInsert()
{
    BTtree<int> t;

    // 专门压力测试连续递增
    for (int i = 1; i <= 100; ++i)
    {
        assert(t.insert(i));
    }

    cout << "Continuous insert test passed" << endl;
}

int main()
{
    TestLL();
    TestRR();
    TestLR();
    TestRL();

    TestRecolor();
    TestDuplicate();

    TestComplex();
    TestContinuousInsert();

    cout << endl;
    cout << "All basic tests passed!" << endl;

    return 0;
}