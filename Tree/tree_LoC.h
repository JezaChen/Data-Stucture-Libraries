//
// Created by jeza on 17-11-1.
//

#ifndef DSL_TREE_LOC_H
#define DSL_TREE_LOC_H

//list of children presentation
#include "../Common/Share.h"
#include "tree.h"

#define locTreeNodePosi(T) listOfChildren_TreeNode<T>*

namespace DSLibrary
{
    template<typename T>
    class listOfChildren_TreeNode : public GeneralTreeNode<T>
    {
    public:
        listOfChildren_TreeNode(T data,
                                locTreeNodePosi(T)par = nullptr,
                                locTreeNodePosi(T)rsb = nullptr,
                                locTreeNodePosi(T)lc = nullptr)
                : _data(data),
                  _parent(par),
                  _rightSibling(rsb),
                  _leftMostChild(lc)
        {}

        ~listOfChildren_TreeNode()
        {
            //release(_parent);
            //release(_leftMostChild);
            _parent = nullptr;
            _leftMostChild = nullptr;
            _rightSibling = nullptr;
        }

        bool isLeaf()
        {
            if (!_leftMostChild) return true;
            else return false;
        }

        locTreeNodePosi(T)parent()
        {
            return _parent;
        }

        locTreeNodePosi(T)leftMostChild()
        {
            return _leftMostChild;
        }

        locTreeNodePosi(T)rightSibling() //not necessary
        {
            return _rightSibling;
        }

        void insertAsFirstChild(const T &elem)
        {
            _leftMostChild = new listOfChildren_TreeNode<T>(elem, this, _leftMostChild);
        }

        void insertAsRightSibling(const T &elem)
        {
            _rightSibling = new listOfChildren_TreeNode<T>(elem, _parent, _rightSibling);
        }

        T removeFirstChild()
        {
            if (_leftMostChild)
            {
                locTreeNodePosi(T)temp = _leftMostChild;
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
                locTreeNodePosi(T)temp = _rightSibling;
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
        locTreeNodePosi(T)_parent;
        locTreeNodePosi(T)_leftMostChild;
        locTreeNodePosi(T)_rightSibling; //相当于链表中的next指针
    };

    template<typename T>
    class listOfChildren_Tree : public GeneralTree<T>
    {
    public:
        listOfChildren_Tree(locTreeNodePosi(T)r)
                : _root(r), _size(1)
        {}

        listOfChildren_Tree(T rootValue)
                : _root(new listOfChildren_TreeNode<T>(rootValue))
        {}

        ~listOfChildren_Tree()
        {

        }

        void clear()
        {
            clearHelp(_root);
            _size = 0;
        }

        locTreeNodePosi(T)root()
        {
            return _root;
        }

        //void insertAsRoot(const T&, )

        int size()
        { return _size; }

    private:
        locTreeNodePosi(T)_root;
        int _size;

        void clearHelp(locTreeNodePosi(T)r)
        {
            //locTreeNodePosi(T)temp = r;
            for (locTreeNodePosi(T)temp = r->leftMostChild();
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
