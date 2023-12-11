#pragma once

#include<vector>
#include<array>
#include<memory>
#include<functional>
#include<optional>

namespace CM {
    struct MyKey{
        int value;

        auto operator ==(const MyKey &other) const
        {
            return value == other.value;
        }
    };

    template<typename Key, typename Value>
    class sjr_map {
        struct bucket
        {
            bucket(Key key, const std::optional<Value> &value) :
                key(key),
                value(value) {}
            Key key;
            std::optional<Value> value;
        };

        using TableRow = std::vector<bucket>;
        using Table = std::vector<TableRow>;
    private:
        int _capacity;
        size_t _size;
        std::unique_ptr<Table> _table;
        std::hash<Key> _hash;

        static bucket& getNullBucket()
        {
            static bucket nullBucket{Key{}, std::nullopt};
            return nullBucket;
        }

        bucket& findBucket(const Key &key) const
        {
            const auto offset = _hash(key) % _capacity;
            auto &row = (*_table)[offset];

            for(bucket &entry : row)
            {
                if (entry.key == key)
                {
                    return entry;
                }
            }

            return getNullBucket();
        }
    public:
        explicit sjr_map(int capacity) :
            _capacity{capacity}, _size{0}, _hash{std::hash<Key>{}}
        {
            _table = std::make_unique<Table>(capacity);
        }

        auto add(const Key &key, const Value &value) const
        {
            const auto offset = _hash(key) % _capacity;
            auto &row = (*_table)[offset];
            auto isAdded = false;

            for(bucket &entry : row)
            {
                if (!entry.value.has_value() || entry.key == key)
                {
                    entry.value = value;
                    isAdded = true;
                    break;
                }
            }

            if (isAdded){
                return;
            }

            row.push_back(bucket{ key, value});
        }

        bool try_get(const Key &key, Value &value) const
        {
            const auto& bucket = findBucket(key);
            if (&bucket == &getNullBucket() || !bucket.value.has_value()){
                value = Value{};
                return false;
            }

            value = *bucket.value;
            return true;
        }

        bool remove(const Key &key) const
        {
            const auto offset = _hash(key) % _capacity;
            auto &row = (*_table)[offset];

            auto index = 0;
            auto isFound = false;
            for(bucket &entry : row)
            {
                if (entry.key == key)
                {
                    isFound = true;
                    break;
                }
                index += 1;
            }

            if (isFound)
            {
                row.erase(row.begin() + index);
                return true;
            }

            return false;
        }
    };

    void RunTests();
} // CM

namespace std
{
    template <>
    struct hash<CM::MyKey>
    {
        std::size_t operator()(const CM::MyKey& k) const
        {
            return (hash<int>()(k.value) << 1);
        }
    };
};