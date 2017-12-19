//
// Created by jeza on 17-12-19.
//

#ifndef DSL_TTTREE_H
#define DSL_TTTREE_H

#include "TTNode.h"
#include "../BST/Dictionary.h"

namespace DSLibrary
{
    template<typename Key, typename T>
    class TTTree : public Dictionary<Key, T>
    {
    private:
        TTNode<Key, T> *_root;
        int recordsCount;

        void clearHelp(TTNode<Key, T> *node);

        bool insertHelp(TTNode<Key, T> *&subroot, const Key &k, const T &elem, Key &returnKey, T &returnValue,
                        TTNode<Key, T> *returnPtr);

        bool findHelp(TTNode<Key, T> *subroot, const Key &k, T &returnVal) const;

        void printHelp(TTNode<Key, T> *, int) const;

    public:
        TTTree() : _root(nullptr), recordsCount(0)
        {}

        ~TTTree()
        { clearHelp(_root); }

        void clear()
        {
            clearHelp(_root);
            _root = nullptr;
            recordsCount = 0;
        }

        T remove(const Key &k)
        {}

        T removeAny()
        {}

    };
}
#endif //DSL_TTTREE_H
