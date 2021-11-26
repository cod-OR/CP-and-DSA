
// 146. LRU Cache

class dllNode{
  public:
    int key;
    int val;
    dllNode* prev=NULL;
    dllNode* next=NULL;
};

class LRUCache {
    
    dllNode* front, *rear;
    int size;
    int capacity;
    unordered_map<int, dllNode*> store;
    
    void insertNode(int key, int val){
        if(size==capacity){
            deleteNode(rear);
            insertNode(key, val);
            return;
        }
        
        dllNode* node=new dllNode();
        node->val=val;
        node->key=key;
        if(size==0){
            front=rear=node;
        }
        else{
            front->next=node;
            node->prev=front;
            front=node;
        }
        
        store[key]=front;
        size++;
    }
    
    void deleteNode(dllNode* node){
        if(node->prev)
            node->prev->next = node->next;
        if(node->next)
            node->next->prev = node->prev;
        
        if(node==rear)
            rear=node->next;
        if(node==front)
            front=node->prev;
        
        store.erase(node->key);
        delete node;
        
        size--;
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size=0;
        front = rear = NULL;
    }
    
    int get(int key) {
        if(store.find(key) == store.end()){
            return -1; // key not present in store
        }
        else{
            dllNode* node = store[key];
            int val = node->val;
            
            // delete from current pos and attatch at the front
            deleteNode(node);
            insertNode(key, val);
            
            return val;
        }
    }
    
    void put(int key, int value) {
        if(store.find(key) != store.end()){
            deleteNode(store[key]);
            store.erase(key);
        }
        
        // add the key to store
        insertNode(key, value);
                
        // after inserting, the position of this key is at front
        store[key]=front;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
