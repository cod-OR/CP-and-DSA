

// 140. Word Break II

// We will maintain a string as a candidate solution.
// And we will traverse the given string s.
// Let's say we are at index 0 in s, so we want a word in wordDict which starts with the letter s[0] 
// If there is no such word, we return.
// Else, we try all possible words; We can use a Trie data structure to optimize this.
// If a word matches a prefix of string s, we append that word to the candidate and we will recursively call the "function",
// but this time our investigation will start from the index just next to the selected prefix.
// If we reach the end of string s, we add the current candidate to the soltion. 
// Then we backtrack and pop the appended word and try different words.


class TrieNode{
  public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(){
        isEnd=0;
        children = vector<TrieNode*>(26, NULL);
    }
};


class Solution {
    void insert(TrieNode* T, string &w, int index){
        if(index == w.size()){
            T->isEnd=1;
            return;
        }
        
        int c = w[index]-'a';
        
        if(T->children[c] == NULL)
            T->children[c] = new TrieNode();
        
        insert(T->children[c] , w, index+1);
        
    }
    
    TrieNode* constructTrie(vector<string>& wordDic){
        TrieNode* T=new TrieNode();
        for(auto word:wordDic){
            insert(T, word, 0);
        }
        return T;
    }
    void wordBreak(string &s, int index, TrieNode* T, string &candidate , TrieNode* root){
        if(index == s.size()){    
            if(T->isEnd)
                sentences.push_back(candidate);

            return;
        }
        
        int c= s[index]-'a';
        
        if(T->isEnd and root->children[c]){
            candidate.push_back(' ');
            
            candidate.push_back(s[index]);
        
            wordBreak(s, index+1, root->children[c], candidate, root);
            
            candidate.pop_back();
            candidate.pop_back();
        }
        
        
        
        if(T->children[c]==NULL)
            return;
        
        candidate.push_back(s[index]);
        
        wordBreak(s, index+1, T->children[c], candidate, root);
        
        candidate.pop_back();
        
            
    }
public:
    vector<string> sentences;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        TrieNode* T = constructTrie(wordDict);
        string candidate;
        wordBreak(s,0,T,candidate,T);
        return sentences;
    }
};
