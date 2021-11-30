
// 84. Largest Rectangle in Histogram

// One possible approach is,
// For each column, assume this column is going to be present in solution and see how much can it be extended towards left and right.
// Doing this in brute force will require O(n) time for each column, So overall O(n squared)

// Observe that:
// The rectangle can be extended, only till the column which is to the right and whose height is smaller than current column, same towards left.
// So we need to find the position of immediate left smaller element, And Same for right.
// difference between them will be the width of rectangle. (height is equal to that of current column.)
// O(n) time, O(n) space.

// Implementation can further be simplified using a stack

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
