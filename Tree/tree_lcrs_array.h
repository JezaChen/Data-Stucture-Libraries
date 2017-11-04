//
// Created by jeza on 17-11-2.
//

#ifndef DSL_TREE_LCRS_ARRAY_H
#define DSL_TREE_LCRS_ARRAY_H
//list of children presentation
#include "../Common/Share.h"
#include "tree.h"


namespace DSLibrary
{
    namespace TrLibrary
    {
        typedef int rank;

#define nullPosi -1

        template<typename T>
        class leftChildRightSibling_TreeNode  //不必继承了...
        {
        public:
            leftChildRightSibling_TreeNode(T data,
                                           rank par = nullPosi,
                                           rank rsb = nullPosi,
                                           rank lc = nullPosi)
                    : _data(data),
                      _parent(par),
                      _rightSibling(rsb),
                      _leftMostChild(lc)
            {}

            ~leftChildRightSibling_TreeNode()
            {
                _parent = nullPosi;
                _leftMostChild = nullPosi;
                _rightSibling = nullPosi;
            }

            T data()
            {
                return _data;
            }

            void setData(const T& newData)
            {
                _data = newData;
            }

            bool isLeaf()
            {
                return _leftMostChild == nullPosi;
            }

            rank parent()
            {
                return _parent;
            }

            void setParent(const rank& parentPosi)
            {
                _parent = parentPosi;
            }

            rank leftMostChild()
            {
                return _leftMostChild;
            }

            rank rightSibling() //not necessary
            {
                return _rightSibling;
            }

            void modifyNewFirstChildPosi(const rank &newPosi)
            {
                _leftMostChild = newPosi;
            }

            void modifyNewRightSiblingPosi(const rank &newPosi)
            {
                _rightSibling = newPosi;
            }


        private:
            T _data;
            rank _parent;
            rank _leftMostChild;
            rank _rightSibling; //相当于链表中的next指针
        };

        template<typename T>
        class leftChildRightSibling_Tree
        {
#define defaultSize 200
        public:
            leftChildRightSibling_Tree(int s = defaultSize)
                    : _capacity(s), _elem(new leftChildRightSibling_Tree<T> [s])
            {
                init();
            }

            leftChildRightSibling_Tree(T rootValue, int s = defaultSize)
                    : _capacity(s),_root(0),_elem(new leftChildRightSibling_Tree<T> [s])
            {
                init();
                _elem[0].setData(rootValue);
            }

            ~leftChildRightSibling_Tree()
            {
                release(_elem);
            }

            void clear()
            {
                _size = 0;
                init();
            }

            rank root()
            {
                return _root;
            }

            int size()
            { return _size; }

            void insertAsFirstChild(const rank& parent, const T& val)
            {
                if(_size == _capacity)
                {
                    //TODO:抛出异常
                }
                else
                {
                    //rank temp = _elem[parent].leftMostChild();
                    _elem[_size].setData(val);
                    _elem[_size].setParent(parent);
                    _elem[_size].modifyNewRightSiblingPosi(_elem[parent].leftMostChild());
                    _elem[parent].modifyNewFirstChildPosi(_size);
                    _size++;
                }
            }

            void insertAsRightSibling(const rank& leftSibling, const T& val)
            {
                if(_size == _capacity)
                {
                    //TODO:抛出异常
                }
                else
                {
                    //rank temp = _elem[leftSibling].rightSibling();
                    _elem[_size].setData(val);
                    _elem[_size].setParent(_elem[leftSibling].parent());
                    _elem[_size].modifyNewRightSiblingPosi(_elem[leftSibling].rightSibling());
                    _elem[leftSibling].modifyNewRightSiblingPosi(_size);
                    _size++;
                }
            }

        private:
            rank _root;
            int _size;
            int _capacity;
            leftChildRightSibling_TreeNode<T>* _elem;

            void init()
            {
                for(int i=0;i<_capacity;i++)
                {
                    _elem[i].setParent(-1);
                    _elem[i].modifyNewFirstChildPosi(-1);
                    _elem[i].modifyNewRightSiblingPosi(-1);

                }
            }
        };
    }
}
#endif //DSL_TREE_LCRS_ARRAY_H
