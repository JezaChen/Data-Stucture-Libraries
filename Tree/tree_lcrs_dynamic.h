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

        void setData(const T&elem)
        {
            _data = elem;
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

        /**
         * Be careful that new left child must not have right siblings and parent!!!
         * @param newLc
         */
        void insertAsFirstChild(lcrsTreeNodePosi(T)newLc)
        {
            if (newLc == nullptr) return;
            newLc->_parent = this;
            newLc->_rightSibling = _leftMostChild;
            _leftMostChild = newLc;
        }

        void insertAsRightSibling(const T &elem)
        {
            _rightSibling = new leftChildRightSibling_TreeNode<T>(elem, _parent, _rightSibling);
        }

        /**
         * Be careful that new right sibling must not have right siblings and parent!!!
         * @param newRsb
         */
        void insertAsRightSibling(lcrsTreeNodePosi(T)newRsb)
        {
            if (newRsb == nullptr) return;
            newRsb->_parent = _parent;
            newRsb->_rightSibling = _rightSibling;
            _rightSibling = newRsb;
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
            }
            else
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
            }
            else
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
        //constructor
        leftChildRightSibling_Tree(lcrsTreeNodePosi(T)r)
                : _root(r), _size(1)
        {}

        leftChildRightSibling_Tree(const T &rootValue)
                : _root(new leftChildRightSibling_TreeNode<T>(rootValue)),
                  _size(1)
        {}

        leftChildRightSibling_Tree() :
                _root(nullptr), _size(0)
        {}

        //destructor
        ~leftChildRightSibling_Tree()
        {
            release(_root);
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

        void insertAsFirstChild(GTNodePosi(T)target, const T &val)
        {
            insertAsFirstChild(static_cast<lcrsTreeNodePosi(T)>(target), val);
        }

        void insertAsRightSibling(GTNodePosi(T)target, const T &val)
        {
            insertAsRightSibling(static_cast<lcrsTreeNodePosi(T)>(target), val);
        }


        void insertAsRoot(const T &rootValue, GTNodePosi(T)oldRoot1, GTNodePosi(T)oldRoot2)
        {
            _root = new leftChildRightSibling_TreeNode<T>(rootValue);
            _root->insertAsFirstChild(static_cast<lcrsTreeNodePosi(T) >(oldRoot1));
            _root->leftMostChild()->insertAsRightSibling(static_cast<lcrsTreeNodePosi(T) >(oldRoot2));
        }

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

        void insertAsFirstChild(lcrsTreeNodePosi(T)target, const T &val)
        {
            target->insertAsFirstChild(val);
            _size++;
        }

        void insertAsRightSibling(lcrsTreeNodePosi(T)target, const T &val)
        {
            target->insertAsRightSibling(val);
            _size++;
        }
    };
}
#endif //DSL_TREE_LOC_H
