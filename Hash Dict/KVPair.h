//
// Created by jeza on 17-12-3.
//

#ifndef DSL_KVPAIR_H
#define DSL_KVPAIR_H

namespace DSLibrary
{
    template<typename Key, typename E>
    class KVPair
    {
    private:
        Key _key;
        E _value;
    public:
        KVPair()
        {}

        KVPair(Key kValue, E value) : _key(kValue), _value(value)
        {}

        KVPair(const KVPair &temp)
        {
            _key = temp._key;
            _value = temp._value;
        }

        bool operator==(const KVPair &temp)
        {
            return _value == temp._value && _key == temp._key;
        }

        KVPair &operator=(const KVPair &temp)
        {
            _key = temp._key;
            _value = temp._value;
            return *this;
        }

        Key key()
        { return _key; }

        E value()
        { return _value; }

        void setKey(const Key &k)
        {
            _key = k;
        }

        void setValue(const E &v)
        {
            _value = v;
        }
    };
}
#endif //DSL_KVPAIR_H
