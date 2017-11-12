//
// Created by jeza on 17-11-12.
//

#ifndef DSL_BINNODE_TRAVLEVEL_H
#define DSL_BINNODE_TRAVLEVEL_H

#include "BinNode.h"
#include "../Queue/Linked_Queue.h"

namespace DSLibrary
{
    template<typename T, typename VST>
    void travLevel(BinNodePosi(T)x, VST &visit)
    {
        Queue<BinNodePosi(T)> Q;
        if (x) Q.enqueue(x);
        while (Q.size() != 0)
        {
            BinNodePosi(T)r = Q.dequeue();
            visit(r);
            if (HasLChild(*r)) Q.enqueue(r->lc);
            if (HasRChild(*r)) Q.enqueue(r->rc);
        }
    };

    template<typename T, typename VST>
    void travLevel_II(BinNodePosi(T)x, VST &visit)
    {
        Queue<BinNodePosi(T)> Q1, Q2;
        bool currIsQ1 = true;
        if(x) Q1.enqueue(x);
        while(Q1.size()!=0 || Q2.size()!=0)
        {
            if (currIsQ1)
            {
                BinNodePosi(T) r= Q1.dequeue();
                visit(r);
                if(HasLChild(*r)) Q2.enqueue(r->lc);
                if(HasRChild(*r)) Q2.enqueue(r->rc);
                if(Q1.size()==0)
                    currIsQ1 = false;
            }
            else
            {
                BinNodePosi(T) r=Q2.dequeue();
                visit(r);
                if(HasLChild(*r)) Q1.enqueue(r->lc);
                if(HasRChild(*r)) Q1.enqueue(r->rc);
                if(Q2.size()==0)
                    currIsQ1 = true;
            }
        }
    };

}
#endif //DSL_BINNODE_TRAVLEVEL_H
