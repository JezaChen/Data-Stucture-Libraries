//
// Created by Jeza on 2017/9/21.
//

#ifndef DSL_BINNODE_TRAVIN_H
#define DSL_BINNODE_TRAVIN_H

#include "BinNode.h"
#include "../Stack/Linked_Stack.h"

namespace DSLibrary
{
    template<typename T, typename VST>
    void travIn_R(BinNodePosi(T)x, VST &visit) //递归版中序遍历
    {
        if (!x) return; //递归基
        travIn_R(x->lc, visit);
        visit(x);
        travIn_R(x->rc, visit);
    };

    //迭代版中序遍历版本1
    template<typename T>
    void goAlongLeftBranch(BinNodePosi(T)u, Stack<BinNodePosi(T)> &S)
    {
        while (u)
        {
            S.push(u);
            u = u->lc;
        }
    }

    template<typename T, typename VST>
    void travIn_I1(BinNodePosi(T)x, VST &visit)
    {
        Stack<BinNodePosi(T)> S; //辅助栈
        while (true)
        {
            goAlongLeftBranch(x, S); //沿左分支依次将各个节点入栈
            if (S.empty()) break;
            else
            {
                x = S.pop();
                visit(x);
                x = x->rc; //转至右孩子（不管是不是空的）瞅一瞅
            }
        }
    };

    //迭代版中序遍历版本2，根据版本1进行相应的更改
    template<typename T, typename VST>
    void travIn_I2(BinNodePosi(T)x, VST &visit)
    {
        Stack<BinNodePosi(T)> S; //辅助栈
        while (true)
        {
            if (x) //如果当前节点非空
            {
                S.push(x); //入栈
                x = x->lc; //沿左分支继续
            }
            else if (!S.empty()) //否则，需要出栈
            {
                x = S.pop();
                visit(x->data); //访问出栈后的当前节点
                x = x->rc; //去右孩子那里瞅瞅
            }
            else
                return;
        }
    };

    //迭代版中序遍历版本3，利用直接后继
    template<typename T, typename VST>
    void travIn_I3(BinNodePosi(T)x, VST &visit)
    {
        bool backtrack = false; // 回溯标志
        while (true)
        {
            if (HasLChild(*x) && backtrack == false) //如果有左孩子而且不是刚刚回溯过
            {
                x = x->lc; //则沿左分支继续深入
            }
            else //否则，也就是没有左子树或者刚刚从左子树回溯过
            {
                visit(x); //访问它
                if (HasRChild(*x)) //如果有右孩子
                {
                    x = x->rc; //走向右孩子方向
                    backtrack = false; //关闭回溯标志
                }
                else
                {
                    if (!(x = x->succ())) break; //终止条件是没有直接后继，意味着这是最后访问的节点
                    backtrack = true; //打开回溯标志，意味着刚从包含该节点、以后继为根的左子树回溯过
                }
            }
        }
    };
}
#endif //DSL_BINNODE_TRAVIN_H
