

// 198. House Robber


// dp[i] => maximum possible profit, which can be chieved in [0,i]
// i.e. he is going to rob ith house; Now two options are there => ith house is robbed Or it is not robbed
// If not robbed, this is same is solving for [0,i-1]
// If robbed, this is same as solving for [0,i-2] and then adding nums[i]

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int len=nums.size();
        int dp[len];
        for(int i=0;i<len;i++){
            if(i==0)
              dp[i]=nums[0];
            else if(i==1)
                dp[i]=max(nums[i], nums[i-1]);
            else 
                dp[i]=max(dp[i-1], nums[i]+dp[i-2]);
        }
        return dp[len-1];
        
    }
};
