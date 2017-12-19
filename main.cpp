#include <iostream>


#include "Queue/test.h"
#include "Stack/test.h"
#include "List/test.h"
#include "Tree/test.h"
#include "Binary Tree/test.h"
#include "Algorithm/sort_test.h"
#include "Hash Dict/test.h"

using namespace std;
using namespace DSLibrary;


int main()
{
    cout << "Select one of the following data structures: " << endl;
    cout << "1.List 2.Stack 3.Queue 4.Tree 5.Binary Tree 6.Sort 7.Hash Dict" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {

        list_test();
    }
    else if (choice == 2)
    {
        stack_test();
    }
    else if (choice == 3)
    {
        queue_test();
    }
    else if (choice == 4)
    {
        tree_test();
    }
    else if (choice == 5)
    {
        binTree_test();
    }
    else if(choice == 6)
    {
        sort_test_I();
    }
    else if(choice == 7)
    {
        hashDict_testII();
    }
        return 0;
}