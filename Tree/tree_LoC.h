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
                                    locTreeNodePosi(T) rsb = nullptr
                                    locTreeNodePosi(T)lc = nullptr)
                    : _data(data),
                      _parent(par),
                      _rightSibling(rsb),
                      _leftMostChild(lc)
            {}

            ~listOfChildren_TreeNode()
            {
                release(_parent);
                release(_leftMostChild);
            }

            bool isLeaf()
            {
                if(!_leftMostChild) return true;
                else return false;
            }

            locTreeNodePosi(T) parent()
            {
                return _parent;
            }

            locTreeNodePosi(T) leftMostChild()
            {
                return _leftMostChild;
            }

            locTreeNodePosi(T) rightSibling() //not necessary
            {
                return _rightSibling;
            }

            void insertAsFirstChild(const T& elem)
            {
                _leftMostChild = new listOfChildren_TreeNode<T> (elem,this,_leftMostChild);
            }

            void insertAsRightSibling(const T& elem)
            {

            }

        private:
            T _data;
            locTreeNodePosi(T)_parent;
            locTreeNodePosi(T)_leftMostChild;
            locTreeNodePosi(T) _rightSibling; //相当于链表中的next指针
        };
}
#endif //DSL_TREE_LOC_H
