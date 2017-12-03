//
// Created by jeza on 17-12-3.
//
#ifndef DSL_HASHDICTFUNC_H
#define DSL_HASHDICTFUNC_H

#include <ctime>
#include <cstdlib>

namespace DSLibrary
{
    template<typename Key, typename E>
    class probingFunc
    {
    private:
        static int M;
        static int *Perm;
    public:
        static int linearProbing(const Key &k, const int &i)
        {
            return i;
        }

        static int quadraticProbing(const Key &k, const int &i)
        {
            return (i * i + i) / 2;
        }

        static int pseudoRandomProbing(const Key &k, const int &i)
        {
            return Perm[i - 1];
        }

        static void setM(int newM)
        {
            if (Perm) delete[] Perm;

            M = newM;
            Perm = new int[M];
            srand(static_cast<unsigned int>(time(NULL)));
            for (int i = 0; i < M; i++)
                Perm[i] = rand() % M;
        }
    };

    template<typename Key, typename E>
    int *probingFunc<Key, E>::Perm = nullptr;

    template<typename Key, typename E>
    int probingFunc<Key, E>::M = 0;

}
#endif //DSL_HASHDICTFUNC_H
