//
// Created by jeza on 17-10-31.
//

#ifndef DSL_TREE_H
#define DSL_TREE_H


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

        //virtual void insertAsFirstChild(GTNodePosi(T), const T&);

        //virtual void insertAsRightSibling(GTNodePosi(T), const T&);

        virtual void print() = 0;

        virtual int size() = 0;
    };
}
#endif //DSL_TREE_H
