

// 16. 3Sum Closest

// Idea is exactly simmiler to the 3Sum problem


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff=INT_MAX;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int sum;
        for(int i=0;i<n;i++){
          
            if(i<n-1 and nums[i]==nums[i+1])
                continue;
            
            int l=0, r=i-1;
            
            while(l<r){
                if(abs(nums[l] + nums[r] + nums[i] - target) < diff){
                    diff = abs(nums[l] + nums[r] + nums[i] - target);
                    sum = nums[l] + nums[r] + nums[i];
                }
                
                if(nums[l] + nums[r] < target-nums[i]){
                    int prev=nums[l];
                    while(l<r and nums[l]==prev)l++;
                }
                else{
                    int prev=nums[r];
                    while(l<r and nums[r]==prev)r--;
                }
            }
            
        }
        return sum;
    }
};
