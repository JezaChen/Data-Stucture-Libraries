//
// Created by Jeza on 2017/9/26.
//

#ifndef DSL_DICTIONARY_H
#define DSL_DICTIONARY_H

//字典ADT
template<typename Key, typename E>
class Dictionary
{
public:
    Dictionary() {}
    virtual ~Dictionary() {}

    virtual void insert(const Key&, const E&) = 0;
    virtual E remove(const Key& ) = 0;
    virtual E removeAny() = 0;
    virtual E find(const Key& ) = 0;
};
#endif //DSL_DICTIONARY_H
