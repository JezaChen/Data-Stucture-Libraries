//
// Created by jeza on 17-10-9.
//

#include "BST.h"

namespace DSLibrary
{
    template<typename Key,typename E>
    E BST<Key,E>::findHelp(BSTNode<Key, E> *p, const Key & k) const //查找协助函数
    {
        if(!p) return NULL;
        if(k > p->_key) return findHelp(p->rc,k);
        else if(k < p->_key) return findHelp(p->lc,k);
        else return p->element();
    }

    template<typename Key, typename E>
    BSTNodePosi(Key,E) BST<Key,E>::insertHelp(BSTNodePosi(Key,E) p, const Key & k, const E & e,BSTNodePosi(Key,E) hot) //插入协助函数
    {
        if(!p)
            return new BSTNode<Key,E>(e,k,hot);
        if(k<p->_key)
            p->lc = insertHelp(p->lc,k,e,p);
        else if(k>p->_key)
            p->rc = insertHelp(p->rc,k,e,p);
        return p;
    }

    template<typename  Key, typename E>
    BSTNodePosi(Key,E) BST<Key,E>::deleteMin(BSTNodePosi(Key,E) rt, BSTNodePosi(Key,E) hot)
    {
        if(rt->lc==NULL) //递归基
        {
            rt->rc->parent=hot; //认爹
            return rt->rc;
        }
        else
        {
            //递归实现
            rt->lc = deleteMin(rt->lc, rt);
            return rt;
        }
    }

    template<typename Key, typename E>
    BSTNodePosi(Key,E) BST<Key,E>::getMin(BSTNodePosi(Key,E) rt)
    {
        if(rt->lc==NULL) return rt;
        else
            return getMin(rt->lc);
    }

    template<typename Key, typename E>
    BSTNodePosi(Key,E) BST<Key,E>::removeHelp(BSTNode<Key, E> *rt, const Key &k)
    {
        if(rt == NULL) return NULL;
        else if (k<rt->_key)
            rt->lc = removeHelp(rt->lc,k);
        else if(k>rt->_key)
            rt->rc = removeHelp(rt->rc,k);
        else //found
        {
            BSTNodePosi(Key,E) temp = rt;
            if(!HasLChild(*rt))
            {
                rt->rc->parent = rt->parent;
                rt = rt->rc;
                delete temp;
            }
            if(!HasRChild(*rt))
            {
                rt->lc->parent = rt->parent;
                rt = rt->lc;
                delete temp;
            }
            else
            {
                //非常灵活的方法
                BSTNodePosi(Key,E) succ = getMin(rt->rc); //找到后继
                rt->setElem(succ->element());
                rt->_key = succ->_key;
                rt->rc = deleteMin(rt->rc,rt);
                delete temp;
            }
        }
    }

    template<typename Key, typename E>
    void BST<Key,E>::clearHelp(BSTNode<Key, E> *root)
    {
        if(!root) return;
        //递归删除
        clearHelp(root->lc);
        clearHelp(root->rc);
        delete root; //最后再删除子树的根节点
    }

    template<typename Key, typename E>
    void BST<Key,E>::printHelp(BSTNode<Key, E> *root, int level) const
    {
        //也是通过递归实现
        if(root==NULL) return ;
        printHelp(root->lc,level+1);
        for(int i=0;i<level;i++) cout<<"  ";
        cout<<root->_key<<endl;
        printHelp(root->rc,level+1);
    }
}