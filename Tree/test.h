//
// Created by jeza on 17-11-4.
//

#ifndef DSL_TREE_TEST_H
#define DSL_TREE_TEST_H

#include <iostream>
#include <ctime>
#include "sys/time.h"

#include "tree.h"
#include "tree_lcrs_dynamic_tr.h"
#include "tree_lcrs_array.h"
#include "tree_lcrs_dynamic.h"
#include "tree_loc.h"
#include "tree_sequential.h"

#define _DEBUG

#ifdef _DEBUG
//timeval结构定义
struct timeVal{
    long tv_sec; //秒
    long tv_usec; //微秒
};
//timezone 结构定义
struct timeZone{
    int tz_minuteswest; /*和Greenwich 时间差了多少分钟*/
    int tz_dsttime; /*日光节约时间的状态*/
};
#endif //_DEBUG

using namespace DSLibrary;

void tree_test()
{
    cout << "Select one of the following implements" << endl;
    cout << "1.Slash 2.Slash and Point 3.Bracket" << endl;
    int c;
    cin >> c;

    if (c == 1)
    {
        string str; cin>>str;
        BinTree<char>* tree = SequentialTreeImplementation_Rebuild::SlashImplementation_Rebuild(str);
        string res;
        res = SequentialTreeImplementation::SlashImplementation(tree);
        cout<<res<<endl;
    }
    else if(c==2)
    {
        string str; cin>>str;
        BinTree<char>* tree = SequentialTreeImplementation_Rebuild::SlashAndPointImplementation_Rebuild(str);
        string res;
        res = SequentialTreeImplementation::SlashAndPointerImplementation(tree);
        cout<<res<<endl;
    }
    else
    {

        string str; cin>>str;

#ifdef _DEBUG
        struct timeval t1,t2;
        double timeuse;
        gettimeofday(&t1,NULL);
#endif

        GeneralTree<char>* tree = SequentialTreeImplementation_Rebuild::BracketImplementation_Rebuild(str);
        string res;

        res = SequentialTreeImplementation::BracketImplementation(tree);

#ifdef _DEBUG
        gettimeofday(&t2,NULL);
        timeuse = t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;
        printf("Use Time:%f\n",timeuse);
#endif

        cout<<res<<endl;
        tree->printTree();
    }
}

#endif //DSL_TREE_TEST_H
