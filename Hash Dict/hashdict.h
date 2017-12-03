//
// Created by jeza on 17-12-3.
//

#ifndef DSL_HASHDICT_H
#define DSL_HASHDICT_H

#include <cstring>
#include <string>
#include "../Common/Share.h"
#include "../BST/Dictionary.h"
#include "KVPair.h"

using std::string;

namespace DSLibrary
{
    template<typename Key, typename E>
    class HashDict
    {
    private:
        KVPair<Key, E> *HashTable;
        int M; //哈希表的大小
        int _size; //哈希表目前元素的数目
        const Key EmptyKey;
        const Key TombStone; //墓碑

        int p(Key K, int i) const
        {
            return i;
        }

        int h(int x) const
        { return x % M; }

        int h(char *key) const
        {
            unsigned int *lkey = (unsigned int *) key;
            int intLength = (int) strlen(key) / 4;
            unsigned int sum = 0;
            for (int i = 0; i < intLength; i++)
                sum += lkey[i];

            int extra = (int) strlen(key) - intLength * 4;
            char temp[4];
            lkey[0] = 0;
            for (int i = 0; i < extra; i++)
                temp[i] = key[intLength * 4 + i];
            lkey = (unsigned int *) temp;
            sum += lkey[0];

            return sum % M;
        }

        int h(string key)
        {
            char tempChar[key.size()];
            for (int i = 0; i < key.size(); i++)
                tempChar[i] = key[i];
            return h(tempChar);
        }

        void hashInsert(const Key &, const E &);

        bool hashSearch(const Key &, E&);

        bool hashRemove(const Key &, E&);

    public:
        HashDict(int sz, Key emptyKey, Key _tombStone)
                : M(sz), EmptyKey(emptyKey), _size(0), TombStone(_tombStone)
        {
            HashTable = new KVPair<Key, E>[M];
            for (int i = 0; i < M; i++)
                HashTable[i].setKey(emptyKey);
        }

        ~HashDict()
        {
            release(HashTable);
        }

        bool find(const Key &k, E& result)
        {
            return hashSearch(k, result);
        }

        int size()
        { return _size; }

        void insert(const Key &k, const E &it)
        {
            if (_size == M)
            {
                //TODO
            }
            hashInsert(k, it);
            _size++;
        }

        bool remove(const Key &k, E& result)
        {
            return hashRemove(k, result);
        }

        E removeAny() //删除第一个数据
        {
            if (_size == 0)
            {
                //TODO
            }
            else
            {
                for (int i = 0; i < M; i++)
                {
                    if (HashTable[i].key() != EmptyKey)
                    {
                        HashTable[i].setKey(EmptyKey);
                        _size--;
                        return HashTable[i].value();
                    }
                }
            }
        }

    };

    template<typename Key, typename E>
    void HashDict<Key, E>::
    hashInsert(const Key &k, const E &e)
    {
        int home;
        int curr = home = h(k);
        for (int i = 1; EmptyKey != (HashTable[curr].key()) && TombStone != (HashTable[curr].key()); i++)
        {
            curr = (home + p(k, i)) % M;
            if (k == HashTable[curr].key())
            {
                //TODO:不能有重复的key
            }
        }
        KVPair<Key, E> newPair(k, e);
        HashTable[curr] = newPair;
    }

    template<typename Key, typename E>
    bool HashDict<Key, E>::hashSearch(const Key &k, E& result)
    {
        int home;
        int curr = home = h(k);
        for (int i = 1;
             (k != HashTable[curr].key()) && (EmptyKey != HashTable[curr].key());
             i++)
            curr = (home + p(k, i)) % M;

        if (k == HashTable[curr].key())
        {
            result = HashTable[curr].value();
            return true;
        }
        else
            return false;
    }

    template<typename Key, typename E>
    bool HashDict<Key, E>::hashRemove(const Key &k, E& result)
    {
        int home;
        int curr = home = h(k);
        for (int i = 1;
             (k != HashTable[curr].key()) && (EmptyKey != HashTable[curr].key());
             i++)
            curr = (home + p(k, i)) % M;

        if (k == HashTable[curr].key())
        {
            E temp = HashTable[curr].value();
            KVPair<Key, E> tombKey;
            tombKey.setKey(TombStone);
            HashTable[curr] = tombKey;
            result = temp;
            return true;
        }
        else
            return false;
    }


}

#endif //DSL_HASHDICT_H
