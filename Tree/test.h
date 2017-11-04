//
// Created by jeza on 17-11-4.
//

#ifndef DSL_TEST_H
#define DSL_TEST_H

#include <iostream>
#include "tree.h"
#include "tree_lcrs_dynamic_tr.h"
#include "tree_lcrs_array.h"
#include "tree_lcrs_dynamic.h"
#include "tree_loc.h"
#include "tree_sequential.h"

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
        GeneralTree<char>* tree = SequentialTreeImplementation_Rebuild::BracketImplementation_Rebuild(str);
        string res;
        res = SequentialTreeImplementation::BracketImplementation(tree);
        cout<<res<<endl;
    }
}

#endif //DSL_TEST_H
