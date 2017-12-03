//
// Created by jeza on 17-12-3.
//

#ifndef DSL_HASHDICT_TEST_H
#define DSL_HASHDICT_TEST_H

#include <iostream>
#include <iomanip>
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
    if (choice == 1)
    {
        HashDict<int, string> *hashDict = new HashDict<int, string>(100, -1, -100);

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
                    catch(hashDictKeyCollision_Exception e)
                    {
                        e.print();
                        break;
                    }
                    catch(hashDictFull_Exception e)
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
        HashDict<string, string> *hashDict = new HashDict<string, string>(100, "EMPTY", "TOMB");
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
                    catch(hashDictKeyCollision_Exception e)
                    {
                        e.print();
                        break;
                    }
                    catch(hashDictFull_Exception e)
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

#endif //DSL_HASHDICT_TEST_H
