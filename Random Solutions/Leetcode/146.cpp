

// 146. LRU Cache


class dllNode{
  public:
    int val;
    int key;
    dllNode* prev = NULL;
    dllNode* next = NULL;
};

class LRUCache {
    
    dllNode* front=NULL,  *rear=NULL;
    int capacity;
    int size;
    unordered_map<int, dllNode*> store;
    
    void deleteNode(dllNode* node){
        if(node->prev)
            node->prev->next = node->next;
        if(node->next)
            node->next->prev = node->prev;
        if(node==rear)
            rear = node->next;
        if(node == front)
            front = node->prev;
        size--;
        delete node;
    }
    
    void insertNode(int key, int val){
        
        if(size == capacity){
            store.erase(rear->key);
            deleteNode(rear);
            insertNode(key,val);
            return;
        }
        
        dllNode* node = new dllNode();
        node -> val = val;
        node -> key = key;
        if(size==0){
            rear = front = node;
        }
        else{
            front ->next = node;
            node->prev = front;
            front = node;
        }
        
        size++;
    }
    
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        rear=front=NULL;
        size=0;
    }
    
    int get(int key){
        int val;
        
        if(store.find(key) != store.end()){
            
            dllNode* node = store[key];
            val = node->val;
            
            // remove from previous pos
            store.erase(key);
            deleteNode(node);
            
            // add at new pos
            insertNode(key,val);
            store[key] = front;
            
        }
        else{
           // not present in store
           val = -1;
        }
        
        return val;
        
    }
    
    void put(int key, int val) {

        if(store.find(key) != store.end()){
            // if this key is present, remove it
            deleteNode(store[key]);
            store.erase(key);
        }
        
        // add at new position
        insertNode(key , val);
        store[key]=front;
        
    }
  
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
