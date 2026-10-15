class LRUCache {
    
    struct Node {
        int key;
        int value;
        Node *prev;
        Node *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity_;
    std::unordered_map<int, Node*> cache_;
    Node *head_;
    Node *tail_;

    void unlink_node(Node *n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void insert_front(Node *n) {
        n->prev = head_;
        n->next = head_->next;
        head_->next->prev = n;
        head_->next = n;
    }

public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        head_ = new Node(0, 0);
        tail_ = new Node(0, 0);

        head_->next = tail_;
        tail_->prev = head_;
    }

    ~LRUCache() {
        Node *n = head_;
        while( n ) {
            Node *next = n->next;
            delete n;
            n = next;
        }
    }
    
    int get(int key) {
        if( !cache_.contains(key) ) {
            return -1;
        }

        Node *get = cache_[key];
        unlink_node(get);
        insert_front(get);

        return get->value;
    }
    
    void put(int key, int value) {
        if( cache_.contains(key) ) {
            Node *n = cache_[key];
            n->value = value;
            unlink_node(n);
            insert_front(n);
            return;
        }

        Node *n = new Node(key, value);
        cache_[key] = n;
        insert_front(n);

        if( (int)cache_.size() > capacity_ ) {
            Node *lru = tail_->prev;
            int key = lru->key;

            unlink_node(lru);
            cache_.erase(key);
            delete lru;
        } 
    }
};
