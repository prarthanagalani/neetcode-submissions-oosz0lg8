class LRUCache {
public:
    
    class node{
        public:
        int key;
        int val;
        node* prev;
        node* next;

        node(int key1,int val1){
            key = key1;
            val = val1;
        }
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    unordered_map<int,node*>mp;

    int cap;

    LRUCache(int capacity) {

        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deletenode(node* curnode){

        node* prevnode = curnode->prev;
        node* nextnode = curnode->next;

        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }

    void addafterhead(node* curnode){

        node* nextnode = head->next;

        head->next = curnode;
        curnode->prev = head;
        curnode->next = nextnode;
        nextnode->prev = curnode;
    }
    
    int get(int key) {

        if(mp.find(key) != mp.end()){
            node* node = mp[key];

            deletenode(node);
            
            addafterhead(node);

            mp[key] = head->next;
            
            return node->val;
        }

        return -1;


        
    }
    
    void put(int key, int value) {

       if(mp.find(key) != mp.end())
        {
            node* node = mp[key];
            deletenode(node);
            mp.erase(key);
        }
        else if(cap == mp.size())
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addafterhead(new node(key,value));

        mp[key] = head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */