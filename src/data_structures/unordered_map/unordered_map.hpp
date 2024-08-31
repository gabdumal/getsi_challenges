#ifndef UNORDERED_MAP_HPP_
#define UNORDERED_MAP_HPP_

#include <unordered_map>

using namespace std;

template <typename K, typename V>
class UnorderedMap
{
private:
    unordered_map<K, V> map;

public:
    UnorderedMap() : map() {}
    ~UnorderedMap() {}

    void insert(K key, V value)
    {
        map.insert({key, value});
    }

    void update(K key, V value)
    {
        map[key] = value;
    }

    bool contains(K key)
    {
        return map.contains(key);
    }

    V at(K key)
    {
        return map.at(key);
    }

    void erase(K key)
    {
        map.erase(key);
    }

    size_t size()
    {
        return map.size();
    }

    typename unordered_map<K, V>::iterator begin()
    {
        return map.begin();
    }

    typename unordered_map<K, V>::iterator end()
    {
        return map.end();
    }
};

#endif // UNORDERED_MAP_HPP_
