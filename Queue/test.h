//
// Created by Jeza on 2017/9/22.
//

#ifndef DSL_QUEUE_TEST_H
#define DSL_QUEUE_TEST_H
#include <iostream>
#include<string>
#include "../uniPRINTER/print.h"
#include "Queue.h"
#include "Linked_Queue.h"
#include "Array_Based_Queue.h"


using namespace std;
using namespace DSLibrary;

void queue_test()
{
    int choice;
    cout<<"Select one of the following data structure for test"<<endl;
    cout<<"1.Linked Queue   2.Array Based Queue"<<endl;
    cin>>choice;
    cout<<"You can do something in the following examples: enqueue, dequeue, front, size, clear and print"<<endl;
    Queue<int>* Q;
    if(choice==1)  Q=new Single_Linked::LQueue<int> ();
    else Q=new AQueue<int> ();

   string order;
    while(cin>>order)
    {
        if(order=="enqueue")
        {
            try
            {
                int target;
                cin >> target;
                Q->enqueue(target);
                cout<<"Succeed. "<<endl;
                continue;
            }
            catch(arrayFull_Exception& e)
            {
                e.print();
                //TODO:应该还有增加扩容措施
            }
        }
        if(order=="dequeue")
        {
            try
            {
                print(Q->dequeue());
                cout<<endl;
                continue;
            }
            catch(queueEmpty_Exception& e)
            {
                e.print();
            }
        }
        if(order=="front")
        {
            try
            {
                print(Q->front());
                cout<<endl;
                continue;
            }
            catch(queueEmpty_Exception& e)
            {
                e.print();
            }
        }
        if(order=="size")
        {
            cout<<Q->size()<<endl;
            continue;
        }
        if(order=="clear")
        {
            Q->clear();
            cout<<"Succeed. "<<endl;
            continue;
        }
        if(order=="print")
        {
            if(choice==1) print((Alist<int>*)Q);
            if(choice==2) print((Single_Linked::LQueue<int>*)Q);
            continue;
        }
        if(order=="end")
        {
            break;
        }
        else
        {
            cerr<<"Wrong Instruction! Please try again. "<<endl;
        }
    }
}
#endif //DSL_QUEUE_TEST_H
