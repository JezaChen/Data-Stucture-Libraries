//
// Created by jeza on 17-10-11.
//
#pragma once

#ifndef DSL_HUFFNODE_H
#define DSL_HUFFNODE_H


namespace DSLibrary
{

    template <typename E>
    class HuffNode //结点基类
    {
    public:
        //  HuffNode() {}
        virtual int weight()const = 0;
        virtual ~HuffNode() {}
        virtual bool isLeaf() = 0;
    };

    template<typename E>
    class HuffLeafNode : public HuffNode<E>
    {
    private:
        int _weight;
        E _elem;
    public:
        int weight()const {return _weight;}
        HuffLeafNode(const E& val, int frequency) : _weight(frequency),_elem(val) {} //???
        E value() {return _elem;}
        bool isLeaf() {return true;}
    };

    template<typename E>
    class HuffIntlNode : public HuffNode<E>
    {
    private:
        int _weight;
        HuffNode<E>* lc;
        HuffNode<E>* rc;
    public:
        HuffIntlNode(HuffNode<E>* l, HuffNode<E>* r)
        {
            _weight = l->weight() + r->weight();
            lc = l; rc = r;
        }
        int weight()const {return _weight;}
        bool isLeaf() {return false;}
        HuffNode<E>* leftChild() {return lc;}
        HuffNode<E>* rightChild() {return rc;}
        void setLeft(HuffNode<E>* l) { lc = l; }
        void setRgiht(HuffNode<E>* r) { rc = r; }
    };
}

#endif //DSL_HUFFNODE_H
