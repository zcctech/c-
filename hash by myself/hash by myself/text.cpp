//#include "hash.h"
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    hashtable<int, int> ht;
//
//    int arr[] = { 1, 12, 23, 34, 45, 56, 67, 78 };
//
//    for (auto e : arr)
//    {
//        cout << "插入：" << e << endl;
//
//        ht.insert({ e, e * 10 });
//
//        cout << "当前表长：" << ht._data.size() << endl;
//        cout << "当前有效数据个数：" << ht._n << endl;
//
//        cout << "当前哈希表：" << endl;
//
//        for (size_t i = 0; i < ht._data.size(); ++i)
//        {
//            if (ht._data[i]._state == EXIST)
//            {
//                cout << "[" << i << "] "
//                    << ht._data[i]._kv.first
//                    << ":"
//                    << ht._data[i]._kv.second
//                    << endl;
//            }
//            else if (ht._data[i]._state == EMPTY)
//            {
//                cout << "[" << i << "] EMPTY" << endl;
//            }
//            else
//            {
//                cout << "[" << i << "] DELETE" << endl;
//            }
//        }
//
//        cout << "-------------------------" << endl;
//    }
//
//    return 0;
//}#include<iostream>
#include"hash.h"
using namespace std;

int main()
{
    //hashtable<int, int> ht;

    //// 1. 制造大量哈希冲突
    //// 初始容量11，这些key的 %11 都等于1
    //int arr[] = { 1, 12, 23, 34, 45, 56, 67, 78 };

    //for (auto key : arr)
    //{
    //    bool ret = ht.insert({ key, key * 10 });

    //    cout << "insert "
    //        << key
    //        << " : "
    //        << ret
    //        << endl;
    //}

    //cout << "--------------------" << endl;

    //// 2. 测试所有已插入元素
    //for (auto key : arr)
    //{
    //    hashdata<int, int>* ret = ht.find(key);

    //    if (ret != nullptr)
    //    {
    //        cout << "find " << key
    //            << " success, value = "
    //            << ret->_kv.second
    //            << endl;
    //    }
    //    else
    //    {
    //        cout << "find " << key
    //            << " failed"
    //            << endl;
    //    }
    //}

    //cout << "--------------------" << endl;

    //// 3. 测试不存在的key
    //int notExist[] = { 2, 100, 999 };

    //for (auto key : notExist)
    //{
    //    auto ret = ht.find(key);

    //    if (ret == nullptr)
    //    {
    //        cout << "find " << key
    //            << " : not exist"
    //            << endl;
    //    }
    //    else
    //    {
    //        cout << "ERROR: " << key
    //            << " should not exist"
    //            << endl;
    //    }
    //}

    //cout << "--------------------" << endl;

    //// 4. 测试重复插入
    //bool ret1 = ht.insert({ 23, 9999 });

    //cout << "repeat insert 23 : "
    //    << ret1
    //    << endl;

    //auto ret2 = ht.find(23);

    //if (ret2)
    //{
    //    cout << "23 value = "
    //        << ret2->_kv.second
    //        << endl;
    //}

    //cout << "--------------------" << endl;

    //cout << "size = "
    //    << ht._n
    //    << endl;

    //cout << "capacity = "
    //    << ht._data.size()
    //    << endl;
    hashtable<int, int> ht;

    ht.insert({ 1, 10 });
    ht.insert({ 12, 120 });
    ht.insert({ 23, 230 });

    cout << ht._n << endl;      // 3

    cout << ht.erase(12) << endl;   // 1

    cout << ht._n << endl;      // 2

    cout << (ht.find(12) == nullptr) << endl;  // 1

    auto ret = ht.find(23);

    if (ret)
    {
        cout << ret->_kv.first << ":"
            << ret->_kv.second << endl;
    }
    return 0;
}