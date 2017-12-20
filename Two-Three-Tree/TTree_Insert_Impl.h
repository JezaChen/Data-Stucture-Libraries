//
// Created by jeza on 17-12-19.
//

#ifndef DSL_TTREE_INSERT_IMPL_H
#define DSL_TTREE_INSERT_IMPL_H

#include "TTNode.h"
#include "TTTree.h"

namespace DSLibrary
{
    template<typename Key, typename T>
    bool TTTree<Key, T>::insertHelp(TTNode<Key, T> *&subroot, const Key &k, const T &elem, Key &returnKey,
                                    T &returnValue, TTNode<Key, T> *returnPtr)
    {
        //首先处理第一种情况
        //当subroot为空的情况下
        if (subroot == nullptr)
        {
            subroot = new TTNode<Key, T>(k, elem);
        }
            //然后处理第二种情况：已经达到叶节点
            //那就直接插入吧
        else if (subroot->isLeaf())
        {
            //如果第二种情况，则该叶节点肯定是有左值的
            //就是右值存在与否需要进行判断
            //还有判断第二种情况的三种小情况

            //第一种小情况
            //如果右Key值不存在，意味着该节点可以直接插入数据而不用分裂
            if (subroot->_rightKey == EMPTY_KEY)
            {
                //第一种小情况的第一种小小情况，如果待插入的key值小于左key值
                if (k < subroot->_leftKey)
                {
                    //因为是叶节点，没有孩子了，直接交换位置就好
                    subroot->_rightKey = subroot->_leftKey;
                    subroot->_rightVal = subroot->_leftVal;
                    subroot->_leftKey = k;
                    subroot->_leftVal = elem;
                }
                    //否则，直接插在右key值那里就好
                else
                {
                    subroot->_rightKey = k;
                    subroot->_rightVal = elem;
                }
            }
                //如果右key值存在，则需要分裂了，大件事
            else
            {
                //分裂
            }
        }
        else //在内部结点中，还需要继续深入到叶子节点中
        {
            //递归到下一个函数的返回值
            T nxtReturnValue = EMPTY_VALUE;
            Key nxtReturnKey = EMPTY_KEY;
            TTNode<Key, T> *nxtReturnPtr = nullptr;

            if (k < subroot->_leftKey)
                insertHelp(subroot->leftChild, k, elem, nxtReturnKey, nxtReturnValue, nxtReturnPtr);
            if (k > subroot->_leftKey && subroot->_rightKey == EMPTY_KEY)
            {
                insertHelp(subroot->centreChild, k, elem, nxtReturnKey, nxtReturnValue, nxtReturnPtr);
            }
            else
            {
                insertHelp(subroot->rightChild, k, elem, nxtReturnKey, nxtReturnValue, nxtReturnPtr);
            }
            //子递归结束后还要进行上溢节点的相关操作
            if (nxtReturnKey == EMPTY_KEY) //注意要用nxtReturnKey进行判断
            {
                //如果右key值存在
                if (subroot->_rightKey != EMPTY_KEY)
                {
                    //要分裂
                }
                else //若右key值不存在，可以不用分裂直接插入
                {
                    if (nxtReturnKey < subroot->_leftKey) //这个需要改变一下位置
                    {
                        subroot->_rightKey = subroot->_leftKey;
                        subroot->rightChild = subroot->centreChild;
                        subroot->_rightVal = subroot->_leftVal;

                        //update
                        subroot->_leftKey = nxtReturnKey;
                        subroot->_leftVal = nxtReturnValue;
                        subroot->centreChild = nxtReturnPtr;
                    }
                    else
                    {
                        //这个直接插入即可，不要交换相应的位置
                        subroot->_rightKey = nxtReturnKey;
                        subroot->_rightVal = nxtReturnValue;
                        subroot->rightChild = nxtReturnPtr;
                    }
                }
            }
        }
    }

    template<typename Key, typename T>
    bool TTTree<Key, T>::splitNode(TTNode<Key, T> *subroot,
                                   const Key &inKey,
                                   const T &inVal,
                                   TTNode<Key, T> *inPtr,
                                   Key &returnKey,
                                   T &returnVal,
                                   TTNode<Key, T> *returnPtr)
    {
        returnPtr = new TTNode<Key, T>(EMPTY_KEY, EMPTY_VALUE); //先创建一个空的返回孩子指针

        //如果待插入的key值小于左key值
        //则左key值上溢
        //右key值分裂成新的结点
        if (inKey < subroot->_leftKey)
        {
            returnKey = subroot->_leftKey; returnVal = subroot->_leftVal; //原左key值上溢
            subroot->_leftKey = inKey; subroot->_leftVal = inVal;
            returnPtr->_leftKey = subroot->_rightKey; returnPtr->_leftVal = subroot->_rightVal;
            returnPtr->leftChild = subroot->centreChild; returnPtr->centreChild = subroot->rightChild;
            subroot->centreChild = inPtr;

            //还要记得赋空
            subroot->_rightKey = EMPTY_KEY;
            subroot->_rightVal = EMPTY_VALUE;
            subroot->rightChild = nullptr;
        }
        //如果待插入的key值位于中间
        //则这个key值继续上溢
        //右key值分裂成新的结点
        else if(inKey < subroot->_rightKey)
        {
            returnKey = inKey;
            returnVal = inVal;
            returnPtr->_leftKey = subroot->_rightKey;
            returnPtr->_leftVal = subroot->_rightVal;
            returnPtr->leftChild = inPtr;
            returnPtr->centreChild = subroot->rightChild;

            //记得赋空

        }
    }
}
#endif //DSL_TTREE_INSERT_IMPL_H
