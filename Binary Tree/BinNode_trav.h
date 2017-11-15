//
// Created by Jeza on 2017/9/21.
//

#ifndef DSL_BINNODE_TRAV_H
#define DSL_BINNODE_TRAV_H

#include "BinNode.h"
#include "BinNode_travPre.h"
#include "BinNode_travIn.h"
#include "BinNode_travPost.h"
#include "BinNode_travLevel.h"

namespace DSLibrary
{
    template<typename T>
    template <typename VST>
    void BinNode<T>::travPre(VST &visit)
    {
        //看情况选择吧...
        //travPre_I1(this, visit);
        travPre_R(this,visit);
        //travPre_I2(this,visit);
    }

    template<typename T>
    template <typename VST>
    void BinNode<T>::travIn(VST &visit)
    {
        travIn_I3(this, visit);
        //travIn_I1(this,visit);
        //travIn_I2(this,visit);
        //travIn_R(this,visit);
    }

    template<typename T>
    template <typename VST>
    void BinNode<T>::travPost(VST &visit)
    {
        //travPost_I(this, visit); //有问题
        travPost_R(this,visit);
    }

    template<typename T>
    template <typename VST>
    void BinNode<T>::travLevel(VST &visit)
    {
        travLevel_II(this, visit);
    }
}
#endif //DSL_BINNODE_TRAV_H
