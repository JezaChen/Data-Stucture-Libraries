//
// Created by jeza on 17-12-3.
//

#ifndef DSL_HASHDICT_H
#define DSL_HASHDICT_H

#define _TEST

#include <cstring>
#include <string>
#include "hashDictFunc.h"
#include "../Common/Share.h"
#include "../BST/Dictionary.h"
#include "KVPair.h"
#include "../Common/Exception_Handler.h"


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
            return probingFunc<Key, E>::pseudoRandomProbing(K, i);
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

        bool hashSearch(const Key &, E &);

        bool hashRemove(const Key &, E &);

//#ifdef _TEST

        void hashInsert(const Key &, const E &, int &);

        bool hashRemove(const Key &, E &, int &);

//#endif

    public:
        HashDict(int sz, Key emptyKey, Key _tombStone)
                : M(sz), EmptyKey(emptyKey), _size(0), TombStone(_tombStone)
        {
            HashTable = new KVPair<Key, E>[M];
            probingFunc<Key, E>::setM(M);
            for (int i = 0; i < M; i++)
                HashTable[i].setKey(emptyKey);
        }

        ~HashDict()
        {
            release(HashTable);
        }

        bool find(const Key &k, E &result)
        {
            return hashSearch(k, result);
        }

        int size()
        { return _size; }

        void insert(const Key &k, const E &it)
        {
            if (_size == M)
            {
                throw hashDictFull_Exception();
            }
            hashInsert(k, it);
        }

//#ifdef _TEST

        void insert_test(const Key &k, const E &it, int &picks)
        {
            if (_size == M)
            {
                throw hashDictFull_Exception();
            }
            hashInsert(k, it, picks);
        }

        bool remove_test(const Key &k, E &result, int &picks)
        {
            return hashRemove(k, result, picks);
        }

//#endif

        bool remove(const Key &k, E &result)
        {
            return hashRemove(k, result);
        }

        E removeAny() //删除第一个数据
        {
            if (_size == 0)
            {
                throw hashDictEmpty_Exception();
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
            if (k == HashTable[curr].key())
            {
                throw hashDictKeyCollision_Exception();
            }
            curr = (home + p(k, i)) % M;
        }
        KVPair<Key, E> newPair(k, e);
        HashTable[curr] = newPair;
        _size++;
    }

//#ifdef _TEST

    template<typename Key, typename E>
    void HashDict<Key, E>::
    hashInsert(const Key &k, const E &e, int &picks)
    {
        picks = 1;
        int home;
        int curr = home = h(k);
        for (int i = 1; EmptyKey != (HashTable[curr].key()) && TombStone != (HashTable[curr].key()); i++)
        {
            if (k == HashTable[curr].key())
            {
                //throw hashDictKeyCollision_Exception();
                return; //测试用的的代码不抛出异常，直接返回
            }
            curr = (home + p(k, i)) % M;
            picks++;
        }
        KVPair<Key, E> newPair(k, e);
        HashTable[curr] = newPair;
        _size++;
    }

//#endif

    template<typename Key, typename E>
    bool HashDict<Key, E>::hashSearch(const Key &k, E &result)
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
    bool HashDict<Key, E>::hashRemove(const Key &k, E &result)
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
            _size--;
            return true;
        }
        else
            return false;
    }

//#ifdef _TEST

    template<typename Key, typename E>
    bool HashDict<Key, E>::hashRemove(const Key &k, E &result, int &picks)
    {
        picks = 1;
        int home;
        int curr = home = h(k);
        for (int i = 1;
             (k != HashTable[curr].key()) && (EmptyKey != HashTable[curr].key());
             i++, picks++)
            curr = (home + p(k, i)) % M;

        if (k == HashTable[curr].key())
        {
            E temp = HashTable[curr].value();
            KVPair<Key, E> tombKey;
            tombKey.setKey(TombStone);
            HashTable[curr] = tombKey;
            result = temp;
            _size--;
            return true;
        }
        else
            return false;
    }

//#endif
}

#endif //DSL_HASHDICT_H
