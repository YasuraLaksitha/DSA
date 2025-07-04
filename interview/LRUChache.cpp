#include <unordered_map>

using namespace std;

struct Node {
    int key, value;
    Node *prev;
    Node *next;

    Node() = default;

    Node(const int k, const int v): key(k), value(v), prev(nullptr), next(nullptr) {
    }
};

class LRUCache {
    int cap;
    unordered_map<int, Node *> cacheMap;
    Node *start;
    Node *end;

    void remove_(const Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert_into_front_(Node *node) const {
        node->next = start->next;
        node->prev = start;
        node->next->prev = node;
        start->next = node;
    }

public:
    explicit LRUCache(const int capacity): cap(capacity) {
        start = new Node(0, 0);
        end = new Node(0, 0);
        start->next = end;
        end->prev = start;
    }

    int get(const int key) {
        if (cacheMap.find(key) == cacheMap.end()) return -1;

        Node *node = cacheMap[key];
        remove_(node);
        insert_into_front_(node);

        return node->value;
    }

    void put(const int key, const int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            Node *node = cacheMap[key];
            remove_(node);
            node->value = value;
            insert_into_front_(node);
        } else {
            if (cacheMap.size() == cap) {
                const Node *lru = end->prev;

                remove_(lru);
                cacheMap.erase(lru->key);
                delete lru;
            }
            const auto newNode = new Node(key, value);
            insert_into_front_(newNode);
            cacheMap[key] = newNode;
        }
    }
};
