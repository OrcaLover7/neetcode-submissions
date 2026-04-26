class LRUCache {
    class ListNode{
        public:
            int key;
            int value;
            ListNode *prev, *next;
        
        ListNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {} 
    };
private:
    int _capacity;
    ListNode *head, *tail;
    unordered_map<int, ListNode*> cache;

public:

    LRUCache(int capacity) {
        _capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if(cache.count(key)){
            ListNode *node = cache[key];
            removeNode(node);
            addNode(node);
            return node->value;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        
        if(cache.count(key)){
            ListNode* found_node = cache[key];
            removeNode(found_node);
            found_node->value = value;
            addNode(found_node);
        }
        else{
            ListNode *new_node = new ListNode(key, value);

            if(cache.size() == _capacity){
                int old_tail_key = tail->key;
                ListNode *old_tail = tail;
                removeNode(old_tail);
                cache.erase(old_tail_key);
                delete old_tail;
            }
            
            addNode(new_node);
            cache[key] = new_node;
        }
    }

    void addNode(ListNode* node){
        node->prev = head;
        node->next = nullptr;

        if(head){
            head->next = node;
        }
        else
            tail = node;
        
        head = node;
    }

    void removeNode(ListNode* node){
        ListNode *prev = node->prev;
        ListNode *next = node->next;

        if(!prev && !next){
            head = nullptr;
            tail = nullptr;
            return;
        }
        else if(!prev){
            next->prev = nullptr;
            tail = next;
            return;
        }
        else if(!next)
        {
            prev->next = nullptr;
            head = prev;
            return;
        }
        else
        {prev->next = next;
        next->prev = prev;}
    }
};
