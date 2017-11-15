//
// Created by Jeza on 2017/9/21.
//

#ifndef DSL_BINNODE_TRAVPRE_H
#define DSL_BINNODE_TRAVPRE_H
//前序遍历
#include "BinNode.h"
#include "../Stack/Linked_Stack.h"  //引入栈头文件

namespace DSLibrary
{
    template<typename T, typename VST>
    void travPre_R(BinNodePosi(T)x, VST &visit) //递归版前序遍历
    {
        if (!x) return; //注意要有递归基
        visit(x);
        travPre_R(x->lc, visit);
        travPre_R(x->rc, visit);
    };

    template<typename T, typename VST>
    void travPre_I1(BinNodePosi(T)x, VST &visit) //迭代版前序遍历版本1
    {
        //递归转栈思想

        Single_Linked::LStack<BinNodePosi(T)> S; //辅助栈
        if (x) S.push(x);
        while (!S.empty())
        {
            x = S.pop();
            visit(x);
            //其实就是递归转成栈结构
            if (HasRChild(*x)) S.push(x->rc);
            if (HasLChild(*x)) S.push(x->lc);
        }
    };

    //迭代版先序遍历版本2
    template<typename T, typename VST>
    void visitAlongLeftBranch(BinNodePosi(T)u, Stack<BinNodePosi(T)> &S, VST &visit)
    {
        while (u)
        {
            visit(u);
            S.push(u->rc);
            u = u->lc;
        }
    }

    template<typename T, typename VST>
    void travPre_I2(BinNodePosi(T)x, VST &visit)
    {
        Stack<BinNodePosi(T)> S; //辅助栈
        if (x) S.push(x);
        while (!S.empty())
        {
            BinNodePosi(T)u = S.pop();
            visitAlongLeftBranch(u, S, visit);
        }
    };
}
#endif //DSL_BINNODE_TRAVPRE_H
