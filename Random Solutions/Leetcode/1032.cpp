

// 1032. Stream of Characters

// Using brute force approach, we can answer each query in O(n squared) time
// We can optimize the algorithm using tri, so that matching takens only linear time. Then we can answer each query in linear time.

// First construct a trie of all the suffixes of all the words
// Then at each query, traverse the trie, using the suffix of stream-string
// If we encounter a node with isEnd bit set, it means there exist a string in words which matches with a suffix of stream-string.


class TrieNode{
public:
    bool isEnd;
    char c;
    vector<TrieNode*> child;
    TrieNode(){
        isEnd=0;
        child = vector<TrieNode*> (26, NULL);
    }
    TrieNode(char a){
        c=a;
        isEnd=0;
        child = vector<TrieNode*> (26, NULL);
    }
};


class StreamChecker {
    
    TrieNode* T;
    string stream;
    
    void insert(TrieNode* T, string &s, int pos){
        if(pos>=s.size()){
            T->isEnd=1;
            return;
        }
        
        int c = s[pos]-'a';
        if(!T->child[c])
            T->child[c] = new TrieNode();
        
        insert(T->child[c], s, pos+1);
        
    }
    
    bool search(TrieNode* T, int pos){
        if(T==NULL)return 0;
        if(pos==-1 or T->isEnd)
            return T->isEnd;
        
        if(!T->child[stream[pos]-'a'])
            return 0;
        
        return search(T->child[stream[pos]-'a'] , pos-1);
        
    }
    
    
public:
    StreamChecker(vector<string>& words) {
        T=new TrieNode();
        for(auto it:words){
            reverse(it.begin(), it.end());
            insert(T,it,0);
        }
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        int pos = stream.size();
        pos--;
        return search(T,pos);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
