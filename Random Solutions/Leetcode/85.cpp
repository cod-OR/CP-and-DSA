
// 85. Maximal Rectangle


class Solution {
    int findmx(vector<int>& h) {
        
        stack<int> st;
        h.push_back(0);
        int ans=0;
        int n= h.size();
        
        for(int i=0;i<n;i++){
            while(!st.empty() and h[st.top()]>=h[i]){
                int ht=h[st.top()];
                st.pop();
                int l=(st.empty()?-1:st.top());
                ans= max(ans, (i-l-1)*ht);
            }
            st.push(i);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        
        int n=mat.size();
        if(n==0)return 0;
        int m= mat[0].size();
        vector<vector<int> > sum(n, vector<int> (m));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    sum[i][j] = (mat[i][j]-'0');
                }
                else{
                    if(mat[i][j]=='1')
                    sum[i][j] = sum[i-1][j] + (mat[i][j]-'0');
                }
            }
            ans = max(ans, findmx(sum[i]));
        }
        return ans;
    }
};
