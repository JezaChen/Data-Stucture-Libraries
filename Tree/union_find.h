//
// Created by jeza on 17-11-1.
//

#ifndef DSL_UNION_FIND_H
#define DSL_UNION_FIND_H

//#include "tree.h"

#include "../Common/Share.h"


namespace DSLibrary
{
    class parPtrTree
        {
        public:
            void init()
            {
                for (int i = 0; i < size; i++)
                    parent[i] = i;
            }

            void deleteAll()
            {
                release(parent);
                release(rank);
            }

            parPtrTree(int size = 1000) : size(size),
                                          parent(new int[size]),
                                          rank(new int[size])
            { init(); }

            ~parPtrTree()
            {
                deleteAll();
            }

            //implement
            void unite(int x, int y)
            {
                x = find(x);
                y = find(y);
                if (x == y) return;

                if (rank[x] < rank[y])
                    parent[x] = y;
                else
                {
                    parent[y] = x;
                    if (rank[x] == rank[y])
                    {
                        rank[y]++;
                    }
                }
            }

            bool same(int x, int y)
            {
                return find(x) == find(y);
            }

        private:
            int *parent;
            int size;
            int *rank;

            int find(int x)
            {
                if (parent[x] = x) return x;
                else return parent[x] = find(parent[x]);
            }

        };

    typedef parPtrTree unionFind;
}
#endif //DSL_UNION_FIND_H
