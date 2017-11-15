//
// Created by Jeza on 2017/9/20.
//
#ifndef DSL_BINNODE_H
#define DSL_BINNODE_H

#include <iostream>

/**************************
 * BinNode（非指针）状态与性质的判断
 **************************/
//”是不是“关系的判断
#define IsRoot(x) (!((x)._parent))
#define IsLeaf(x) (!HasChild(x))
#define IsLChild(x) (!IsRoot(x) && (&(x)==(x)._parent->lc)) //要注意需要进行根节点的判断
#define IsRChild(x) (!IsRoot(x) && (&(x)==(x)._parent->rc))
//”有没有“关系的判断
#define Has_parent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
/******************************
 * 与BinNode（指针）有特定关系的节点的指针
 ******************************/
#define sibling(x) \
(IsLChild(*(p))?(p)->_parent->rc:(p)->_parent->lc)  //兄弟
#define uncle(x) \
(IsLChild((*p)->_parent):(p)->parnet->_parent->rc:(p)->parnet->_parent->lc) //叔父
#define FromParentTo(x) \
(IsRoot(x)? _root:(IsLChild(x)?(x)._parent->lc:(x)._parent->rc)) //来自父亲的引用

#define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p)?(p)->height:-1) //节点的高度，约定空树的高度为-1

namespace DSLibrary
{
    typedef enum
    {
        RB_RED, RB_BLACK
    } RBColor; //节点颜色，用于红黑树
    template<typename T>
    struct BinNode
    {
        T data; //数值
        BinNodePosi(T)_parent;
        BinNodePosi(T)lc;
        BinNodePosi(T)rc; //父节点、左孩子、右孩子
        int height; //高度
        int npl; //用于左式堆
        RBColor color; //节点颜色，用于红黑树
        //默认构造函数
        BinNode() : _parent(NULL), lc(NULL), rc(NULL), height(0), npl(0), color(RB_RED)
        {}

        //构造函数
        BinNode(T e, BinNodePosi(T)p = NULL, BinNodePosi(T)lc = NULL, BinNodePosi(T)rc = NULL, int h = 0, int np = 0,
                RBColor c = RB_RED) :
                data(e), _parent(p), lc(lc), rc(rc), height(h), npl(np), color(c)
        {}

        int size()
        {}

        BinNodePosi(T)insertAsLc(const T &e)
        { return lc = new BinNode<T>(e, this); }

        BinNodePosi(T)insertAsRc(const T &e)
        { return rc = new BinNode<T>(e, this); }

        BinNodePosi(T)succ() //中序遍历的直接后继
        {
            if (rc) //如果右孩子存在
            {
                //沿右孩子的左分支不断深入
                BinNodePosi(T)x = rc;
                while (x->lc) x = x->lc;
                return x;
            }
            else //否则，向上追溯
            {
                //找到包含当前节点为左子树范围的最近祖先
                BinNodePosi(T)x = this;
                while (x->_parent && !IsLChild(*x))
                {
                    x = x->_parent;
                }
                return x->_parent;
            }
        }

        //遍历
        template<typename VST>
        void travLevel(VST &); //层次遍历
        template<typename VST>
        void travPre(VST &); //前序遍历
        template<typename VST>
        void travIn(VST &); //中序遍历
        template<typename VST>
        void travPost(VST &); //后序遍历
        //比较器
        bool operator<(BinNode const &x)
        { return data < x.data; }

        bool operator>(BinNode const &x)
        { return data > x.data; }

        bool operator==(BinNode const &x)
        { return data == x.data; }

        bool operator!=(BinNode const &x)
        { return !(this == x); }
    };
}
#endif //DSL_BINNODE_H
