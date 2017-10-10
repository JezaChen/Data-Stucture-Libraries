//
// Created by Jeza on 2017/9/26.
//

#ifndef DSL_BST_H
#define DSL_BST_H
#include <iostream>
#include <Common/Exception_Handler.h>
#include "Dictionary.h"
#include "BSTNode.h"
using namespace std;

namespace DSLibrary
{
    template<typename Key, typename E>
    class BST : public Dictionary<Key,E>
    {
    private:
        BSTNodePosi(Key,E) _root; //根节点
        int _size; //规模

        //Private helper functions
        void clearHelp(BSTNodePosi(Key,E));
        BSTNodePosi(Key,E) insertHelp(BSTNodePosi(Key,E), const Key&, const E&, BSTNodePosi(Key,E) hot);
        BSTNodePosi(Key,E) deleteMin(BSTNodePosi(Key,E) rt, BSTNodePosi(Key,E) hot);
        BSTNodePosi(Key,E) getMin(BSTNodePosi(Key,E) rt);
        BSTNodePosi(Key,E) removeHelp(BSTNodePosi(Key,E), const Key& k);
        E findHelp(BSTNodePosi(Key,E), const Key&)const;
        void printHelp(BSTNodePosi(Key,E), int)const;
    public:
        BST():_root(NULL),_size(0) {}
        ~BST() {}

        void clear()
        {
            clearHelp(_root); _root = NULL; _size = 0;
        }

        void insert (const Key& k, const E& elem)
        {
            _root = insertHelp(_root, k, elem,NULL);
            _size++; //记得增加长度
        }

        E remove (const Key& k)
        {
            E temp = find(k);
            //要找不到节点的情况
            if(temp)
            {
                _root = removeHelp(_root, k);
                _size--;
            }
            return temp;
        }
        E removeAny() //莫名奇怪的成员函数
        {
            if(_root)
            {
                E temp=_root->element();
                _root = removeHelp(_root,_root->_key);
                _size--;
                return temp;
            }
            else return NULL;
        }

        E find(const Key& k) const
        {
            return findHelp(_root,k);
        }
        int size() {return _size;}
        void print() const
        {
            if(!_root)
            {
                cerr<<"The BST is empty now."<<endl;
                throw binTreeEmpty_Exception(); //抛出空树异常
            }
            else
            {
                printHelp(_root,0);
            }
        }

    };

}
#endif //DSL_BST_H
