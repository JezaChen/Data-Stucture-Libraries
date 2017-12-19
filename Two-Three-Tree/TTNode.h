//
// Created by jeza on 17-12-19.
//

#ifndef DSL_TTNODE_H
#define DSL_TTNODE_H

#define EMPTY_KEY -99999999
#define EMPTY_VALUE -99999999 //TODO:这个地方存疑

namespace DSLibrary
{
    template<typename Key, typename T>
    class TTNode
    {
    public:
        T _leftVal, _rightVal;

        Key _leftKey, _rightKey;
        TTNode *leftChild, *centreChild, *rightChild;

        TTNode(Key leftKey, T leftValue, Key rightKey = EMPTY_KEY, T rightValue = EMPTY_VALUE, TTNode<Key, T> *lc = nullptr,
               TTNode<Key, T> *cc = nullptr,
               TTNode<Key, T> *rc = nullptr)
                : _leftKey(leftKey), _leftVal(leftValue), _rightKey(rightKey), _rightVal(rightValue), leftChild(lc),
                  centreChild(cc), rightChild(rc)
        {}

        ~TTNode()
        {}

        bool isLeaf()
        {
            return !leftChild;
        }


    };
}
#endif //DSL_TTNODE_H
