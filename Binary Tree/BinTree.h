//
// Created by Jeza on 2017/9/20.
//

#ifndef DSL_BINTREE_H
#define DSL_BINTREE_H
#include <algorithm>
#include "BinNode.h"
#include "../Common/Share.h"
using namespace std;

namespace DSLibrary
{
    template<typename T>
    class BinTree {
    protected:
        int _size;
        BinNodePosi(T)_root; //规模，根节点
        virtual int updateHeight(BinNodePosi(T) x) //更新一个节点的高度
        {
            return x->height=1+max(stature(x->lc),stature(x->rc));
        }
        void updateHeightAbove(BinNodePosi(T) x) //沿一个节点向上更新高度
        {
            while(x)
            {
                updateHeight(x);
                x=x->parent;
            }
        }
    public:
        BinTree():_size(0),_root(NULL) {}
        ~BinTree() {}
        int size() const {return _size;} //树的规模
        bool empty()const {return !_root;} //树空判断
        BinNodePosi(T) root() const {return _root;}
        BinNodePosi(T) insertAsRoot(T const& e) { _size=1; return _root=new BinNode<T> (e); }
        BinNodePosi(T) insertAsLc (BinNodePosi(T) x, T const& e) {_size++; return x->insertAsLc(e);}
        BinNodePosi(T) insertAsRc (BinNodePosi(T) x, T const& e) {_size++; return x->insertAsRc(e);}
        BinNodePosi(T) attachAsLc (BinNodePosi(T) x, BinTree<T>*& S)
        {
            if(x->lc=S->_root) x->lc->parent=x; //避免空树的判断
            _size+=S->_size; updateHeightAbove(x); //向上更新高度
            release(S); S=NULL; return x; //释放原树，并返回原插入点
        }
        BinNodePosi(T) attachAsRc (BinNodePosi(T) x, BinTree<T>*& S)
        {
            if(x->rc=S->_root) x->rc->parent-x; //避免空树的判断
            _size+=S->_size; updateHeightAbove(x);
            release(S); S=NULL; return x; //释放原树，并返回原插入点
        }
        int remove (BinNodePosi(T) x);

    };
}
#endif //DSL_BINTREE_H
