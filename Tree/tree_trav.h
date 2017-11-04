//
// Created by jeza on 17-11-4.
//

#ifndef DSL_TREE_TRAV_H
#define DSL_TREE_TRAV_H

#include "tree.h"

#ifndef GTNodePosi
#define GTNodePosi(T) GeneralTreeNode<T>*
#endif

namespace DSLibrary
{
    template<typename T, typename VST>
    void travPre_R(GTNodePosi(T) root, VST& visit)
    {
        visit(root->data());
        GTNodePosi(T) child = root->leftMostChild();
        while(child)
        {
            travPre_R(child,visit);
            child = child ->rightSibling();
        }
        visit.handleWithEnd(); //处理末尾专用
    };

    template<typename T, typename VST>
    void travPost_R(GTNodePosi(T) root, VST& visit)
    {
        GTNodePosi(T) child = root->leftMostChild();
        while(child)
        {
            travPost_R(child,visit);
            child = child ->rightSibling();
        }

        visit(root->data());
        //visit.handleWithEnd();
    };
}

#endif //DSL_TREE_TRAV_H
