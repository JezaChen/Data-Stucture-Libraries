//
// Created by Jeza on 2017/9/22.
//
#pragma once
#ifndef DSL_QUEUE_TEST_H
#define DSL_QUEUE_TEST_H
#include <iostream>
#include<string>
#include <iomanip>
#include "../uniPRINTER/print.h"
#include "Queue.h"
#include "Linked_Queue.h"
#include "Array_Based_Queue.h"


using namespace std;
using namespace DSLibrary;

void queue_all_functions()
{
    cout.setf(ios::left);
    cout<<setw(20)<<"enqueue (num)"<<setw(30)<<"enqueue the element"<<endl;
    cout<<setw(20)<<"dequeue"<<setw(30)<<"dequeue the element"<<endl;
    cout<<setw(20)<<"front"<<setw(30)<<"get the front element of the stack"<<endl;
    cout<<setw(20)<<"size"<<setw(30)<<"get the size of the stack"<<endl;
    cout<<setw(20)<<"clear "<<setw(30)<<"delete all elements in the stack"<<endl;
}

void queue_test()
{
    int choice;
    cout<<"Select one of the following data structure for test"<<endl;
    cout<<"1.Linked Queue   2.Array Based Queue"<<endl;
    cin>>choice;

    Queue<int>* Q;
    if(choice==1)  Q=new Single_Linked::LQueue<int> ();
    else Q=new AQueue<int> ();

    queue_all_functions();

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
                continue;
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
                continue;
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
                continue;
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
        if(order=="end")
        {
            break;
        }
        else
        {
            cerr<<"Wrong Instruction! Please try again. "<<endl;
            cin.ignore(100,'\n');
        }
    }
    release(Q);
}
#endif //DSL_QUEUE_TEST_H
