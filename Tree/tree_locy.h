//
// Created by jeza on 17-11-3.
//

#ifndef DSL_TREE_LOC_ARRAY_H
#define DSL_TREE_LOC_ARRAY_H

#ifndef locTreeNodePosi
#define locTreeNodePosi(T) listOfChildren_TreeNode<T>*
#endif

#include "tree.h"
#include "../List/Doubly_Linked_List.h"
#include "../Algorithm/find.h"

namespace DSLibrary
{
    namespace TrLibrary
    {
        template<typename T>
        class listOfChildren_TreeNode : public GeneralTreeNode
        {
        public:
            listOfChildren_TreeNode(const T& val, locTreeNodePosi(T) p = nullptr)
                    : _data(val)
            {
                _parent = p;
            }

            ~listOfChildren_TreeNode()
            {
                _data = 0;
                _parent = nullptr;
                childrenList.clear();
            }

            T data()
            {
                return _data;
            }

            void setData(const T& val)
            {
                _data = val;
            }

            bool isLeaf()
            {
                return childrenList.size() == 0;
            }

            locTreeNodePosi(T) parent()
            {
                return _parent;
            }

            locTreeNodePosi(T) leftMostChild()
            {
                if(childrenList.size() == 0) return nullptr;
                else
                    return childrenList[0];
            }

            locTreeNodePosi(T) rightSibling()
            {
                //so hard...
                if(_parent == nullptr) return nullptr;

                int thisPosi = findPosinParentChildrenList();
                if(_parent->childrenList.size() == thisPosi)
                {
                    return nullptr;
                }
                else
                {
                    return childrenList[thisPosi+1];
                }
            }

            void insertAsFirstChild(const T& elem)
            {
                childrenList.moveToStart();
                childrenList.insert(new listOfChildren_TreeNode<T> (elem,this));
            }

            void insertAsRightSibling(const T& elem)
            {
                int thisPosi = findPosinParentChildrenList();

                _parent->childrenList.moveToPosi(thisPosi+1);
                _parent->childrenList.insert(new listOfChildren_TreeNode<T> (elem,_parent));
            }

            T removeFirstChild()
            {
                childrenList.moveToStart();
                locTreeNodePosi(T) temp = childrenList.remove();
                int tempValue = temp->_data;
                release(temp); //务必记得
                temp = nullptr;
                return tempValue;
            }

            T removeRightSibling()
            {
                int thisPosi = findPosinParentChildrenList();
                if(thisPosi == _parent->childrenList.size())
                {
                    //TODO
                }
                else
                {
                    _parent->childrenList.moveToPosi(thisPosi+1);
                    locTreeNodePosi(T) temp = _parent->childrenList.remove();
                    int tempValue = temp->data();
                    release(temp);
                    temp = nullptr;
                    return tempValue;
                }
            }

            void clearChildren()
            {
                int i = 0;
                childrenList.moveToPosi(i);
                while(i!=childrenList.size())
                {
                    childrenList[i]->clearChildren();
                    release(childrenList[i]); //emmm
                }
                childrenList.clear();
            }

            friend void listOfChildren_Tree<T>::clearHelp(locTreeNodePosi(T));

        private:
            T _data;
            locTreeNodePosi(T) _parent;
            Double_Linked::Llist< locTreeNodePosi(T) > childrenList;

            int findPosinParentChildrenList()
            {
                int thisPosi;
                find(_parent->childrenList,this,thisPosi);
            }


        };

        template<typename T>
        class listOfChildren_Tree
        {
        public:
            //constructor
            listOfChildren_Tree() : _root(nullptr), _size(0) {}
            listOfChildren_Tree(const T& rootValue)
                    : _root(new listOfChildren_TreeNode<T> (rootValue)),
                      _size(0)
            {}

            listOfChildren_Tree(locTreeNodePosi(T) r) : _root(r), _size(1)
            {}

            //destuctor
            ~listOfChildren_Tree()
            {
                clear();
            }

            void clear()
            {
                _root->clearChildren();
                release(_root);
                _size = 0;
            }

            locTreeNodePosi(T) root()
            {
                return _root;
            }

            void insertAsFirstChild(locTreeNodePosi(T) target, const T& val)
            {
                target->insertAsFirstChild(val);
                _size++;
            }

            void insertAsRightSibling(locTreeNodePosi(T) target, const T& val)
            {
                target->insertAsRightSibling(target);
                _size++;
            }

            int size()
            {
                return _size;
            }

        private:
            locTreeNodePosi(T) _root;
            int _size;
        };
    }
}
#endif //DSL_TREE_LOC_ARRAY_H
