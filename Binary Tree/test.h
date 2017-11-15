//
// Created by jeza on 17-11-15.
//

#ifndef DSL_BINTREE_TEST_H
#define DSL_BINTREE_TEST_H

#include <iostream>

#include "BinNode.h"
#include "BinTree.h"
#include "BinTree_build.h"
//#include "Common/Share.h"
#include "BinNode_Implement.h"

using DSLibrary::BinNode;
using DSLibrary::BinTree;
using DSLibrary::binTreeBuild_General_Help;
using DSLibrary::binTreeBuild_General;
using DSLibrary::binTreeBuild_Char;
using DSLibrary::PRINTER;
using DSLibrary::leavesCount;
using DSLibrary::HeightCount;


void binTree_test()
{
    cout<<"Select one of the following types of BinTree"<<endl;
    cout<<"1.Char 2.Int"<<endl;
    int choice;
    cin>>choice;

    if(choice == 1)
    {
        cout<<"Input a string: ";
        string str;
        cin>>str;
        BinTree<char>* newTree = binTreeBuild_Char(str);

        //print the bintree
        PRINTER<BinNodePosi(char)> printer;
        cout<<"TravPre: ";
        newTree->travPre(printer);
        cout<<endl;

        cout<<"TravIn: ";
        newTree->travIn(printer);
        cout<<endl;

        cout<<"TravPost: ";
        newTree->travPost(printer);
        cout<<endl;

        cout<<"TreeLevel: ";
        newTree->travLevel(printer);
        cout<<endl;

        cout<<"The number of all nodes is: "<<leavesCount(newTree)<<endl;

        cout<<"THe height of this tree is: "<<HeightCount(newTree)<<endl;

        delete newTree;
    }
    else if(choice == 2)
    {

        //print the bintree
        BinTree<int>* newTree = binTreeBuild_General<int>(); //要这样子使用
        PRINTER<BinNodePosi(int)> printer;
        cout<<"TravPre: ";
        newTree->travPre(printer);
        cout<<endl;

        cout<<"TravIn: ";
        newTree->travIn(printer);
        cout<<endl;

        cout<<"TravPost: ";
        newTree->travPost(printer);
        cout<<endl;

        cout<<"TreeLevel: ";
        newTree->travLevel(printer);
        cout<<endl;

        cout<<"The number of all nodes is: "<<leavesCount(newTree)<<endl;

        cout<<"The height of this tree is: "<<HeightCount(newTree)<<endl;

        delete newTree;
    }
}
#endif //DSL_BINTREE_TEST_H
