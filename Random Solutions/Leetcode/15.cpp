
// 15. 3Sum


// idea is to fix one element and then use two pointers to find combinations of other two elements
// To use two pointrs, we need to sort the array first


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        
        for(int i=0;i<n;i++){
            
            if(i<n-1 and nums[i]==nums[i+1])    
              // is an element is present multiple times, we will only its last instance, othwise it will get counted multiple times
                continue;
            
            int l=0, r=i-1;
            while(l<r){
                if(nums[l] + nums[r] + nums[i] ==0){
                    ans.push_back({nums[l], nums[r], nums[i]});
                }
                if(nums[l] + nums[r] < -nums[i]){
                    int prev=nums[l];
                    while(l<r and nums[l]==prev)    // move the pointer to next distinct element
                        l++;
                }
                else{
                    int prev=nums[r];
                    while(l<r and nums[r]==prev)    // move the pointer to next distinct element
                        r--;
                }
            }
            
            
        }
        
        return ans;
        
    }
};
