

// 10. Regular Expression Matching


class Solution {
public:
    vector<vector<int>  > dp;
    Solution(){
        dp = vector<vector<int>  > (31, vector<int> (31,-1));
    }
    bool isMatch(string &t, string &p, int a=0, int b=0) {
        
        if(b>= p.size())
            return a>=t.size();
        
        if(dp[a][b] != -1)
            return dp[a][b];
        
        bool first = (t.size() > a) and (t[a]==p[b] or p[b]=='.');
        
        if(p.size() > b+1 and p[b+1]=='*'){
            return dp[a][b] = isMatch(t,p,a,b+2) or (first and isMatch(t,p,a+1,b));
        }
        else return dp[a][b] = (first and (isMatch(t, p,a+1,b+1)));
     
    }
};
