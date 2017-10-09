//
// Created by Jeza on 2017/9/26.
//

#ifndef DSL_BSTNODE_H
#define DSL_BSTNODE_H
/**************************
 * BSTNode（非指针）状态与性质的判断
 **************************/
//”是不是“关系的判断
#define IsRoot(x) (!((x).parent))
#define IsLeaf(x) (!HasChild(x))
#define IsLChild(x) (!IsRoot(x) && (&(x)==(x).parent->lc)) //要注意需要进行根节点的判断
#define IsRChild(x) (!IsRoot(x) && (&(x)==(x).parent->rc))
//”有没有“关系的判断
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
/******************************
 * 与BSTNode（指针）有特定关系的节点的指针
 ******************************/
#define sibling(x) \
(IsLChild(*(p))?(p)->parent->rc:(p)->parent->lc)  //兄弟
#define uncle(x) \
(IsLChild((*p)->parent):(p)->parnet->parent->rc:(p)->parnet->parent->lc) //叔父
#define FromParentTo(x) \
(IsRoot(x)? _root:(IsLChild(x)?(x).parent->lc:(x).parent->rc)) //来自父亲的引用


#include <iostream>
#define BSTNodePosi(K,E) BSTNode<K,E>*
namespace DSLibrary {
    template<typename Key, typename E>
    struct BSTNode {
    private:
        E _elem;
    public:
        Key _key;
        BSTNodePosi(Key, E)parent;
        BSTNodePosi(Key, E)lc;
        BSTNodePosi(Key, E)rc; //父亲，左孩子，右孩子
        BSTNode() : parent(NULL), lc(NULL), rc(NULL) {}

        BSTNode(E e, Key k, BSTNodePosi(Key, E)p = NULL, BSTNodePosi(Key, E)lc = NULL, BSTNodePosi(Key, E)rc = NULL)
                : _elem(e), _key(k), parent(p), lc(lc), rc(rc) {}

        ~BSTNode() {}

        BSTNodePosi(Key, E)insertAsLc(const E &elem, const Key &key) {
            return lc = new BSTNode<Key, E>(elem, key, this);
        }

        BSTNodePosi(Key, E)insertAsRc(const E &elem, const Key &key) {
            return rc = new BSTNode<Key, E>(elem, key, this);
        }

        E element() {return _elem; }
        void setElem(E val) {_elem = val;}

        BSTNodePosi(Key, E)succ() {

            if (rc) {
                BSTNodePosi(Key, E)x = rc;
                while (x->lc) x = x->lc;
                return x;
            } else {
                BSTNodePosi(Key, E)x = parent;
                while (!IsLChild(*x)) x = x->parent;
                return x->parent;
            }
        }


    };
}
#endif //DSL_BSTNODE_H
