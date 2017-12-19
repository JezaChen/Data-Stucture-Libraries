//
// Created by jeza on 17-12-3.
//

#ifndef DSL_HASHDICT_TEST_H
#define DSL_HASHDICT_TEST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "hashdict.h"

using namespace DSLibrary;

void hashDict_all_functions()
{
    cout.setf(ios::left);
    cout << setw(20) << "insert KEY VALUE" << setw(30) << "Insert an element" << endl;
    cout << setw(20) << "search KEY" << setw(30) << "Search by a unique key" << endl;
    cout << setw(20) << "remove KEY" << setw(30) << "Remove an element by a unique key" << endl;
    cout << setw(20) << "size" << setw(20) << "Return the size of The Hash Dict" << endl;
}

void hashDict_test()
{
    cout << "Select One of The Following Data Structures:" << endl;
    cout << "1. KEY = int, VALUE = String, 2. KEY = String, VALUE = String)" << endl;
    int choice;
    cin >> choice;
    hashDict_all_functions();
    if (choice == 1)
    {
        HashDict<int, string> *hashDict = new HashDict<int, string>(100, -99999, -199999);

        string order;
        int key;
        string value;
        string result;
        while (cin >> order)
        {
            switch (order[0])
            {
                case 'i':
                case 'I':
                    cin >> key >> value;
                    try
                    {
                        hashDict->insert(key, value);
                        cout << "Insert Successfully." << endl;
                        break;
                    }
                    catch (hashDictKeyCollision_Exception e)
                    {
                        e.print();
                        break;
                    }
                    catch (hashDictFull_Exception e)
                    {
                        e.print();
                        break;
                    }

                case 'S':
                case 's':
                    cin >> key;
                    if (!hashDict->find(key, result))
                    {
                        cout << "Cannot find the element whose key is matched." << endl;
                    }
                    else
                    {
                        cout << "The value of the element whose key is matched is " << result << endl;
                    }
                    break;
                case 'R':
                case 'r':
                    cin >> key;
                    if (!hashDict->remove(key, result))
                    {
                        cout << "Cannot find the element whose key is matched." << endl;
                    }
                    else
                    {
                        cout << "Remove The element whose value is " << result << " successfully." << endl;
                    }
                    break;
                default:
                    cout << "Wrong Instruction!" << endl;
                    cin.ignore(100, '\n');
            }
        }
        if (hashDict)
            delete hashDict;
    }
    else if (choice == 2)
    {
        HashDict<string, string> *hashDict = new HashDict<string, string>(100, "EMPTY&&_#$DSA_KET", "TOMB&&*(S*D(A)*");
        string order;
        string key;
        string value;
        string result;
        while (cin >> order)
        {
            switch (order[0])
            {
                case 'i':
                case 'I':
                    cin >> key >> value;
                    try
                    {
                        hashDict->insert(key, value);
                        cout << "Insert Successfully." << endl;
                        break;
                    }
                    catch (hashDictKeyCollision_Exception e)
                    {
                        e.print();
                        break;
                    }
                    catch (hashDictFull_Exception e)
                    {
                        e.print();
                        break;
                    }
                case 'S':
                case 's':
                    cin >> key;
                    if (!hashDict->find(key, result))
                    {
                        cout << "Cannot find the element whose key is matched." << endl;
                    }
                    else
                    {
                        cout << "The value of the element whose key is matched is " << result << endl;
                    }
                    break;
                case 'R':
                case 'r':
                    cin >> key;
                    if (!hashDict->remove(key, result))
                    {
                        cout << "Cannot find the element whose key is matched." << endl;
                    }
                    else
                    {
                        cout << "Remove The element whose value is" << result << " successfully." << endl;
                    }
                    break;
                default:
                    cout << "Wrong Instruction!" << endl;
                    cin.ignore(100, '\n');
            }
        }
        if (hashDict)
            delete hashDict;
    }
    else
    {
        cout << "WRONG INSTRUCTION!" << endl;
        return;
    }


}

vector<int> RandomArray(int size, int N)
{
    vector<int> res;
    for (int i = 0; i < size; i++)
    {
        res.push_back(rand() % N);
    }
    return res;
}

void hashDict_testII()
{
    srand(time(nullptr));
    cout << "输入哈希表的大小, 不能小于2000." << endl;
    int N;
    cin >> N;
    HashDict<int, int> hashDict(N, -9999999, -99998899);

    for (int i = 1; i < 10; i++)
    {
        cout << "开始填充率为" << i * 10 << "%的测试" << endl;
        vector<int> tmp = RandomArray(N / 10, 1000 * N);
        for (int j = 0; j < tmp.size(); j++)
        {
            //开始填充数据
            try
            {
                hashDict.insert(tmp[j], 0);
            }catch(hashDictKeyCollision_Exception& e)
            {
                continue; //遇到重复的，跳过
            }
        }

        int one_res, total_res = 0; //一次测试结果，多次测试结果之和
        vector<int> InsertTestArr = RandomArray(200, 1000 * N); //200组测试数据
        vector<int> DeleteTestArr = tmp;
        random_shuffle(DeleteTestArr.begin(), DeleteTestArr.end()); //随机打乱删除用的数组

        for (int j = 0; j < InsertTestArr.size(); j++)
        {
            hashDict.insert_test(InsertTestArr[j], 0, one_res);
            total_res += one_res;
        }
        cout << "插入的平均次数是 " << (double) total_res / 200 << endl;
        total_res = 0;
        int temp; //用于填充参数

        for (int j = 0; j < InsertTestArr.size(); j++)
        {
            hashDict.remove_test(DeleteTestArr[j], temp, one_res);
            total_res += one_res;
        }

        cout << "删除的平均次数是 " << (double) total_res / 200 << endl;
    }
}

#endif //DSL_HASHDICT_TEST_H
