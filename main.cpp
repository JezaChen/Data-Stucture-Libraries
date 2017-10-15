#include <iostream>

#include "Queue/test.h"
#include "Stack/test.h"
#include "List/test.h"


using namespace std;
using namespace DSLibrary;


int main() {
    cout<<"Select one of the following data structures: "<<endl;
    cout<<"1.List 2.Stack 3.Queue"<<endl;
    int choice;
    cin>>choice;
    if(choice==1)
    {
        cout << "And.." << endl;
        cout << "1.Array Based List 2. Linked List 3. Doubly Linked List" << endl;
        cin>>choice;
        list_test(choice);
    }
    else if(choice==2)
    {
        stack_test();
    }
    else if(choice==3)
    {
        queue_test();
    }
    return 0;
}