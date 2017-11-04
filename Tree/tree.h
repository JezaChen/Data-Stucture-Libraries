//
// Created by jeza on 17-10-31.
//

#ifndef DSL_TREE_H
#define DSL_TREE_H

#include <iostream>

#define GTNodePosi(T) GeneralTreeNode<T>*
namespace DSLibrary
{



    template<typename T>
    class GeneralTreeNode
    {
    public:
        virtual T data() = 0;

        virtual void setData(const T &elem) = 0;

        virtual bool isLeaf() = 0;

        virtual GTNodePosi(T)parent() = 0;

        virtual GTNodePosi(T)leftMostChild() = 0;

        virtual GTNodePosi(T)rightSibling() = 0;

        virtual void insertAsFirstChild(const T &elem) = 0;

        virtual void insertAsRightSibling(const T &elem) = 0;

        virtual T removeFirstChild() = 0;

        virtual T removeRightSibling() = 0;
    };

    template<typename T>
    class GeneralTree
    {
    public:
        virtual void clear() = 0;

        virtual GTNodePosi(T)root() = 0;

        virtual void insertAsRoot(const T &, GTNodePosi(T), GTNodePosi(T)) = 0;

        virtual void insertAsFirstChild(GTNodePosi(T), const T&) = 0;

        virtual void insertAsRightSibling(GTNodePosi(T), const T&) = 0;

        virtual void printTree()
        {
            p(root());
        }

        virtual int size() = 0;
    };


    template<typename T>
    static void p(GTNodePosi(T) root)
    {
        if (root->isLeaf())
            cout << "Leaf: ";
        else cout << "Internal: ";

        cout<<root->data()<<endl;

        for (GTNodePosi(T)r = root->leftMostChild();
             r != NULL; r = r->rightSibling())
        {
            p(r);
        }
    }
}
#endif //DSL_TREE_H
