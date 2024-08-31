#ifndef UNORDERED_MAP_HPP_
#define UNORDERED_MAP_HPP_

#include <unordered_map>

using namespace std;

template <typename K, typename V>
class UnorderedMap
{
private:
    UnorderedMap<K, V> *unordered_map;
    int length;

    void clear();
    V get(K key, bool erase);

public:
    UnorderedMap();
    ~UnorderedMap();

    int getLength();
    void insert(K key, V value);
    V get(K key);
    V remove(K key);
};

template <typename K, typename V>
UnorderedMap<K, V>::UnorderedMap()
{
    this->unordered_map = new unordered_map<K, V>;
    this->length = 0;
}

template <typename K, typename V>
UnorderedMap<K, V>::~UnorderedMap()
{
    this->clear();
}

template <typename K, typename V>
void UnorderedMap<K, V>::clear()
{
    this->unordered_map->clear();
    this->length = 0;
}

template <typename K, typename V>
int UnorderedMap<K, V>::getLength()
{
    return this->length;
}

template <typename K, typename V>
void UnorderedMap<K, V>::insert(K key, V value)
{
    this->unordered_map->insert({key, value});
    this->length++;
}

template <typename K, typename V>
V UnorderedMap<K, V>::get(K key, bool erase)
{
    auto it = this->unordered_map->find(key);
    if (it == this->unordered_map->end())
        throw "Key not found";

    V value = it->second;
    if (erase)
    {
        this->unordered_map->erase(it);
        this->length--;
    }
    return value;
}

template <typename K, typename V>
V UnorderedMap<K, V>::get(K key)
{
    return this->get(key, false);
}

template <typename K, typename V>
V UnorderedMap<K, V>::remove(K key)
{
    return this->get(key, true);
}

#endif // UNORDERED_MAP_HPP_
