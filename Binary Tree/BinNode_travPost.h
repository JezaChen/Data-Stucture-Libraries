//树
// Created by Jeza on 2017/9/21.
//

#ifndef DSL_BINNODE_TRAVPOST_H
#define DSL_BINNODE_TRAVPOST_H

#include "BinNode.h"
#include "../Stack/Linked_Stack.h"

namespace DSLibrary
{
    template<typename T, typename VST>
    void travPost_R(BinNodePosi(T)x, VST &visit) //递归版后序遍历
    {
        if (!x) return; //递归基
        travPost_R(x->lc, visit);
        travPost_R(x->rc, visit);
        visit(x);
    };

    //迭代版的后续遍历有点抽象
    template<typename T>
    void gotoHLVFL(Stack<BinNodePosi(T)> &S) //找到最高左侧可见叶节点
    {
        while (BinNodePosi(T)x = S.top()) //自顶而下的寻找
        {
            if (HasLChild(*x))
            {
                if (HasRChild(*x)) S.push(x->rc); //若有右孩子，右孩子有限入栈
                S.push(x->lc); //左孩子入栈
            }
            else
                S.push(x->rc); //迫不得已，右孩子入栈
        }
        S.pop(); //记得弹出栈顶的空节点
    }

    template<typename T, typename VST>
    void travPost_I(BinNodePosi(T)x, VST &visit) //迭代版后序遍历
    {
        Single_Linked::LStack<BinNodePosi(T)> S; //辅助栈
        if (x) S.push(x); //根节点入栈
        while (S.empty())
        {
            if (S.top() != x->_parent) //若栈顶非当前节点的父节点，则必为右兄弟或者是当前节点是根节点
            {
                gotoHLVFL(S); //找到栈顶节点的最高左侧可见叶节点
            }
            x = S.pop();
            visit(x); //访问当前节点
        }
    }
}
#endif //DSL_BINNODE_TRAVPOST_H
