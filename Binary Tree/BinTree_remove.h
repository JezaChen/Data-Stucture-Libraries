//
// Created by Jeza on 2017/9/21.
//

#ifndef DSL_BINTREE_REMOVE_H
#define DSL_BINTREE_REMOVE_H
#include "BinTree.h"
namespace DSLibrary
{

    template<typename T>
    static int removeAt (BinNodePosi(T) x) //删除节点x及其所有的后代，并返回删除节点的总数
    {
        if(!x) return 0; //递归基
        int delete_counts=1+removeAt(x->lc)+removeAt(x->rc); //进行递归删除
        //开始删除自身
        release(x->data); release(x);
        return delete_counts;
    }

    template <typename T>
    int BinTree<T>::remove(BinNode<T> *x)
    {
        FromParentTo(*x)=NULL;
        updateHeightAbove(x->parent); //更新祖祖辈辈的高度，做最后的告别
        int delete_counts=removeAt(x); _size-=delete_counts;
        release(x);
        return delete_counts; //返回删除节点的总数
    }

}
#endif //DSL_BINTREE_REMOVE_H
