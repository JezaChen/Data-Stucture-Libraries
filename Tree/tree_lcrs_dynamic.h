//
// Created by jeza on 17-11-1.
//

#ifndef DSL_TREE_LOC_H
#define DSL_TREE_LOC_H

//list of children presentation
#include "../Common/Share.h"
#include "tree.h"

#define lcrsTreeNodePosi(T) leftChildRightSibling_TreeNode<T>*

namespace DSLibrary
{
    template<typename T>
    class leftChildRightSibling_TreeNode : public GeneralTreeNode<T>
    {
    public:
        leftChildRightSibling_TreeNode(T data,
                                lcrsTreeNodePosi(T)par = nullptr,
                                lcrsTreeNodePosi(T)rsb = nullptr,
                                lcrsTreeNodePosi(T)lc = nullptr)
                : _data(data),
                  _parent(par),
                  _rightSibling(rsb),
                  _leftMostChild(lc)
        {}

        ~leftChildRightSibling_TreeNode()
        {
            //release(_parent);
            //release(_leftMostChild);
            _parent = nullptr;
            _leftMostChild = nullptr;
            _rightSibling = nullptr;
        }

        T data()
        {
            return _data;
        }
        bool isLeaf()
        {
            if (!_leftMostChild) return true;
            else return false;
        }

        lcrsTreeNodePosi(T)parent()
        {
            return _parent;
        }

        lcrsTreeNodePosi(T)leftMostChild()
        {
            return _leftMostChild;
        }

        lcrsTreeNodePosi(T)rightSibling() //not necessary
        {
            return _rightSibling;
        }

        void insertAsFirstChild(const T &elem)
        {
            _leftMostChild = new leftChildRightSibling_TreeNode<T>(elem, this, _leftMostChild);
        }

        void insertAsRightSibling(const T &elem)
        {
            _rightSibling = new leftChildRightSibling_TreeNode<T>(elem, _parent, _rightSibling);
        }

        T removeFirstChild()
        {
            if (_leftMostChild)
            {
                lcrsTreeNodePosi(T)temp = _leftMostChild;
                _leftMostChild = _leftMostChild->rightSibling();

                T tempValue = temp->data();
                release(temp);
                return tempValue;
            } else
            {
                //TODO
            }
        }

        T removeRightSibling()
        {
            if (_rightSibling)
            {
                lcrsTreeNodePosi(T)temp = _rightSibling;
                _rightSibling = _rightSibling->rightSibling();

                T tempValue = temp->data();
                release(temp);
                return tempValue;
            } else
            {
                //TODO
            }
        }

    private:
        T _data;
        lcrsTreeNodePosi(T)_parent;
        lcrsTreeNodePosi(T)_leftMostChild;
        lcrsTreeNodePosi(T)_rightSibling; //相当于链表中的next指针
    };

    template<typename T>
    class leftChildRightSibling_Tree : public GeneralTree<T>
    {
    public:
        leftChildRightSibling_Tree(lcrsTreeNodePosi(T)r)
                : _root(r), _size(1)
        {}

        leftChildRightSibling_Tree(T rootValue)
                : _root(new leftChildRightSibling_TreeNode<T>(rootValue))
        {}

        ~leftChildRightSibling_Tree()
        {

        }

        void clear()
        {
            clearHelp(_root);
            _size = 0;
        }

        lcrsTreeNodePosi(T)root()
        {
            return _root;
        }

        //void insertAsRoot(const T&, )

        int size()
        { return _size; }

    private:
        lcrsTreeNodePosi(T)_root;
        int _size;

        void clearHelp(lcrsTreeNodePosi(T)r)
        {
            //lcrsTreeNodePosi(T)temp = r;
            for (lcrsTreeNodePosi(T)temp = r->leftMostChild();
                 temp != nullptr; temp = temp->rightSibling())
            {
                clearHelp(r);
            }
            release(r);
            r = nullptr;
        }
    };
}
#endif //DSL_TREE_LOC_H
