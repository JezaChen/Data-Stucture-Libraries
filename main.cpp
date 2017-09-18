#include <iostream>
#include "AList.h"
#include "Link.h"
#include "Doubly_Linked_List.h"
#include "Exception_Handler.h"
#include "print.h"

using namespace std;
using namespace DSLibrary;

void list_test(int choice)
{
    cout<<"Tips: now you can do something just like insert, remove..."<<endl;
    //1. moveToStart 2. moveToEnd 3. prev 4.next 5.moveToPosi 6.insert 7.delete 8.append 9.get 10.trav
    List<int>* test;
    if(choice==1) test=new Alist<int>();
    else if(choice==2) test=new Single_Linked::Llist<int>();
    else test=new Double_Linked::Llist<int>();
    string order;
    while(cin>>order)
    {
        if(order=="insert")
        {
            int target; cin>>target;
            try
            {
                test->insert(target);
                cout<<"succeed"<<endl;
                continue;
            }
            catch(arrayFull_Exception& e)
            {
                e.print();
                continue;
            }
        }
        if(order=="remove")
        {
            try
            {

                int r=test->remove();
                cout<<"Now you have removed the element "<<r<<endl;
            }
            catch(nullPointer_Exception& e)
            {
                e.print();
                continue;
            }
        }
        if(order=="append")
        {
            int target; cin>>target;
            try
            {
                test->append(target);
            }
            catch(arrayFull_Exception& e)
            {
                e.print();
                continue;
            }
        }
        if(order=="get")
        {
            try
            {
                cout<<test->getValue()<<endl;
            }
            catch(nullPointer_Exception& e)
            {
                e.print();
                continue;
            }
        }
        if(order=="moveToStart")
        {
            test->moveToStart();
            continue;
        }
        if(order=="moveToEnd")
        {
            test->moveToEnd();
            continue;
        }
        if(order=="prev")
        {
            try
            {
                test->moveToStart();
                continue;
            }
            catch(outOfBounds_Exception& e)
            {
                e.print();
                continue;
            }
        }
        if(order=="next")
        {
            try
            {
                test->next(); continue;
            }
            catch(outOfBounds_Exception& e)
            {
                e.print();
                continue;
            }
        }
        if(order=="moveToPosi")
        {
            int target; cin>>target;
            try
            {
                test->moveToPosi(target);
                continue;
            }
            catch(outOfBounds_Exception& e)
            {
                e.print();
                continue;
            }
        }
        if(order=="print")
        {
            if(choice==1) print((Alist<int>*) test);
            else if(choice==2) print((Single_Linked::Llist<int>*) test);
            else print((Double_Linked::Llist<int>*) test);
        }
    }

}
int main() {
    cout<<"Select one of the following data structures: "<<endl;
    cout<<"1.Array Based List 2. Linked List 3. Doubly Linked List"<<endl;
    int choice;
    cin>>choice;
    list_test(choice);
    return 0;
}