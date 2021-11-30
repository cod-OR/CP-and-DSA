
// 84. Largest Rectangle in Histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        
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
};
