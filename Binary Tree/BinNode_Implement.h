//
// Created by jeza on 17-11-12.
//

#ifndef DSL_BINNODE_IMPLEMENT_H
#define DSL_BINNODE_IMPLEMENT_H

#include "BinNode.h"
#include "BinTree.h"
namespace DSLibrary
{
    template<typename T>
    int leavesCount_Help(BinNodePosi(T) _root)
    {
        if(_root == nullptr) return 0;
        if(IsLeaf(*_root)) return 1;
        else
            return leavesCount_Help(_root->lc) + leavesCount_Help(_root->rc);
    }

    template <typename T>
    int leavesCount(BinTree<T>* tree)
    {
        return leavesCount_Help(tree->root());
    }

    template <typename T>
    int HeightCount_Help(BinNodePosi(T) _root) //模拟统计高度过程，实际上BST的实现已经整合了这个功能，没有什么功能了
    {
        if(_root == nullptr) return -1; //默认空树的高度为-1
        else
        {
            return 1 + max(HeightCount_Help(_root->lc),HeightCount_Help(_root->rc));
        }
    }
}
#endif //DSL_BINNODE_IMPLEMENT_H
