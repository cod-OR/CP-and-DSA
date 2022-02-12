
// 127. Word Ladder

// given a beginWord, endWord.
// Find distance between them.

// Do a BFS from beginWord.
// Try all possible children

// Every word can have at max 26*10 children

// Time complexity: O(V*260*10)


class Solution {
    
    void tryChildren(string &curr, queue<string> &Q, unordered_map<string, int> &distOfString, int newDist){
        string temp;
        int m= curr.size();
        for(int i=0;i<m;i++){
            temp=curr;
            for(char c='a';c<='z';c++){
                temp[i]=c;
                if(distOfString.find(temp) != distOfString.end()){
                    if(distOfString[temp] > newDist){
                        distOfString[temp] = newDist;
                        Q.push(temp);
                    }
                }
            }
        }
    }
        
        
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        vector<vector<int> > adj;
        unordered_map<string, int> distOfString;
        int n=wordList.size();
        
        for(int i=0;i<n;i++){
            distOfString[wordList[i]]=INT_MAX;
        }
        
        queue<string> Q;
        
        string temp;
        
        int m = beginWord.size();
        
        
        tryChildren(beginWord,Q,distOfString,2);
        
        
        while(!Q.empty()){
            
            string curr = Q.front();
            Q.pop();
            
            if(curr == endWord)
                return distOfString[curr];
            
            int newDist = distOfString[curr] + 1;
            tryChildren(curr,Q,distOfString,newDist);          
            
        }
        
        return 0;
        
    }
};

