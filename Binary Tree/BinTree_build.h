//
// Created by jeza on 17-11-15.
//

#ifndef DSL_BINTREE_BUILD_H
#define DSL_BINTREE_BUILD_H

#include "BinTree.h"
#include "Tree/tree_sequential.h"

namespace DSLibrary
{
    BinTree<char> *binTreeBuild_Char(const string &str)
    {
        return SequentialTreeImplementation_Rebuild::SlashImplementation_Rebuild(str);
    }


    template<typename T>
    BinTree<T> *binTreeBuild_General()
    {
        cout<<"Input the root node's elem: ";
        T temp;
        if(cin>>temp)
        {
            BinTree<T> *newTree = new BinTree<T>();
            newTree->insertAsRoot(temp);

            cout<<"Input the root's left child elem: ";
            T temp2;
            if(cin>>temp2)
            {
                binTreeBuild_General_Help(newTree, newTree->root(), temp2, true);
            }
            else
            {
                cout<<"It has no left child"<<endl;
                cin.clear();
                cin.ignore();
            }

            cout<<"Input the root's right child elem: ";
            if(cin>>temp2)
            {
                binTreeBuild_General_Help(newTree, newTree->root(), temp2, false);
            }
            else
            {
                cout<<"It has no right child"<<endl;
                cin.clear();
                cin.ignore();
            }

            return newTree;
        }
        else
            return nullptr;
    }

    template<typename T>
    void binTreeBuild_General_Help(BinTree<T> *&tree,
                                   BinNodePosi(T)currTreeNode,
                                   const T &elem,
                                   bool isLeftChild)
    {
        BinNodePosi(T) newTreeNodePosi;
        if(isLeftChild)
            newTreeNodePosi = tree->insertAsLc(currTreeNode, elem);
        else
            newTreeNodePosi = tree->insertAsRc(currTreeNode, elem);


        cout<<"Input the node "<<elem<<"'s left child elem: ";
        T temp;
        if(cin>>temp)
        {
            binTreeBuild_General_Help(tree, newTreeNodePosi, temp, true);
        }
        else
        {
            cout<<"It has no left child"<<endl;
            cin.clear();
            cin.ignore();
        }

        cout<<"Input the node "<<elem<<"'s right child elem: ";
        if(cin>>temp)
        {
            binTreeBuild_General_Help(tree, newTreeNodePosi, temp, false);
        }
        else
        {
            cout<<"It has no right child"<<endl;
            cin.clear();
            cin.ignore();
        }

    }
}
#endif //DSL_BINTREE_BUILD_H
