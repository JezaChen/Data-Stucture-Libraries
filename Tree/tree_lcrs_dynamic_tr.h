//
// Created by jeza on 17-11-3.
//

#ifndef DSL_TREE_LCRS_DYNAMIC_TR_H
#define DSL_TREE_LCRS_DYNAMIC_TR_H

#include "../Common/Share.h"
#include  "tree.h"
#include "../Binary Tree/BinTree.h"
//#include "../Binary Tree/BinNode.h"

#ifndef lcrsTreeNodePosi
#define lcrsTreeNodePosi(T) leftChildRightSibling_TreeNode<T>*
#endif

namespace DSLibrary
{
    namespace TRLibrary
    {
        //template <typename T>  int removeHelp(lcrsTreeNodePosi(T) );
        template<typename T>
        class leftChildRightSibling_TreeNode;

        template<typename T>
        int removeHelp(lcrsTreeNodePosi(T)_root);


        template<typename T>
        class leftChildRightSibling_TreeNode : public GeneralTreeNode<T>,
                                               public BinNode<T>
        {
        public:
            //构造函数干好自己的分内事就行了
            leftChildRightSibling_TreeNode(const T &val,
                                           lcrsTreeNodePosi(T)realNodeParent,
                                           lcrsTreeNodePosi(T)lc,
                                           lcrsTreeNodePosi(T)rsb) :
                    BinNode<T>(val, realNodeParent, lc, rsb)
            {}

            ~leftChildRightSibling_TreeNode()
            {}

            T data()
            { return BinNode<T>::data; }

            void setData(const T &val)
            {
                BinNode<T>::data = val;
            }

            bool isLeaf()
            {
                return BinNode<T>::lc == nullptr;
            }

            lcrsTreeNodePosi(T)parent()
            {
                lcrsTreeNodePosi(T)x = this;
                while (!IsRoot(*x) && (x == x->_parent))
                {
                    x = static_cast<lcrsTreeNodePosi(T)> (x->_parent);
                }
                return static_cast<lcrsTreeNodePosi(T)> (x->_parent);

            }

            lcrsTreeNodePosi(T)leftMostChild()
            {
                return static_cast<lcrsTreeNodePosi(T)> (BinNode<T>::lc);
            }

            lcrsTreeNodePosi(T)rightSibling()
            {
                return static_cast<lcrsTreeNodePosi(T)> (BinNode<T>::rc);
            }

            void insertAsFirstChild(const T &elem)
            {
                BinNodePosi(T)oldLc = BinNode<T>::lc;
                BinNode<T>::lc = new leftChildRightSibling_TreeNode<T>(elem,
                                                                       this,
                                                                       nullptr,
                                                                       static_cast<lcrsTreeNodePosi(T)> (oldLc));
                if (oldLc)
                    oldLc->_parent = BinNode<T>::lc; //old lc need changing its parent to the new lc
            }

            void insertAsRightSibling(const T &elem)
            {
                BinNodePosi(T)oldRc = BinNode<T>::rc;
                BinNode<T>::rc = new leftChildRightSibling_TreeNode<T>(elem,
                                                                       this,
                                                                       nullptr,
                                                                       static_cast<lcrsTreeNodePosi(T)>(oldRc));
                if (oldRc)
                    oldRc->_parent = BinNode<T>::rc;
            }

            T removeFirstChild()
            {
                if (!BinNode<T>::lc)
                {
                    T tempValue = BinNode<T>::lc->data;
                    lcrsTreeNodePosi(T)newLc = static_cast<lcrsTreeNodePosi(T)>(BinNode<T>::lc->rc);
                    removeHelp(static_cast<lcrsTreeNodePosi(T)>(BinNode<T>::lc->BinNode<T>::lc));
                    release(BinNode<T>::lc);
                    BinNode<T>::lc = newLc;
                    return tempValue;
                }
                else
                {
                    //TODO
                }
            }

            T removeRightSibling()
            {
                if (!BinNode<T>::rc)
                {
                    T tempValue = BinNode<T>::rc->data;
                    lcrsTreeNodePosi(T)newRc = static_cast<lcrsTreeNodePosi(T)>(BinNode<T>::rc->BinNode<T>::rc);
                    removeHelp(static_cast<lcrsTreeNodePosi(T)>(BinNode<T>::rc->BinNode<T>::lc));
                    release(BinNode<T>::rc);
                    BinNode<T>::rc = newRc;
                    return tempValue;
                }
                else
                {
                    //TODO
                }
            }

        private:
        };

        template<typename T>
        int removeHelp(lcrsTreeNodePosi(T)_root)
        {
            //delete its left child and everything in its left child
            if (!_root) return 0; //递归基
            int deleteCounts =
                    1 + removeHelp(static_cast<lcrsTreeNodePosi(T)>(_root->lc)) +
                    removeHelp(static_cast<lcrsTreeNodePosi(T)>(_root->rc));
            release(_root);
            return deleteCounts;

        }

        template<typename T>
        class leftChildRightSibling_Tree : public GeneralTree<T>
        {
        public:
            leftChildRightSibling_Tree() : _root(nullptr), _size(0)
            {}

            leftChildRightSibling_Tree(const T &rootValue)
                    : _root(new leftChildRightSibling_TreeNode<T>(rootValue)), _size(1)
            {}

            leftChildRightSibling_Tree(const lcrsTreeNodePosi(T)&root)
                    : _root(const_cast<lcrsTreeNodePosi(T)> (root)), _size(1)
            {}

            ~leftChildRightSibling_Tree()
            {
                clear();
                _size = 0;
            }

            void clear()
            {
                removeHelp(_root);
            }

            lcrsTreeNodePosi(T)root()
            {
                return _root;
            }

            void insertAsRoot(const T &rootValue, GTNodePosi(T)treeRoot1, GTNodePosi(T)treeRoot2)
            {
                _root = new leftChildRightSibling_TreeNode<T>(rootValue, nullptr, nullptr, nullptr);
                _root->lc = static_cast<lcrsTreeNodePosi(T)>(treeRoot1);
                if (_root->lc)
                    _root->lc->rc = static_cast<lcrsTreeNodePosi(T)>(treeRoot2);
                else
                    _root->lc = static_cast<lcrsTreeNodePosi(T)>(treeRoot2);

            }

            void insertAsFirstChild(GTNodePosi(T)target, const T &elem)
            {
                insertAsFirstChild(static_cast<lcrsTreeNodePosi(T)>(target), elem);
            }

            void insertAsRightSibling(GTNodePosi(T)target, const T &elem)
            {
                insertAsRightSibling(static_cast<lcrsTreeNodePosi(T)>(target), elem);
            }

            void print()
            {}

            int size()
            { return _size; }


        private:

            void insertAsFirstChild(const lcrsTreeNodePosi(T)target, const T &val)
            {
                const_cast<lcrsTreeNodePosi(T)>(target)->insertAsFirstChild(val);
                _size++;
            }

            void insertAsRightSibling(const lcrsTreeNodePosi(T)target, const T &val)
            {
                const_cast<lcrsTreeNodePosi(T) >(target)->insertAsRightSibling(val);
                _size++;
            }

            lcrsTreeNodePosi(T)_root;
            int _size;
        };
    }
}
#endif //DSL_TREE_LCRS_DYNAMIC_TR_H
